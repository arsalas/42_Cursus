const search = document.querySelector("#search");
const form = document.querySelector("#form");
const history = document.querySelector("#history");
const content = document.querySelector("#content");
const clean = document.querySelector("#clean");

const handleSubmit = async (e) => {
    e.preventDefault();
    content.innerHTML = "Searching...";
    const pokemon = await getPokemon(search.value);
    if (pokemon) {
        printPokemon(pokemon);
        addhistory(pokemon.sprites.front_default);
        form.reset();
    }
    else content.innerHTML = "Pokemon not found";
}

const addhistory = (image) => {
    const node = document.createElement("img");
    node.src = image
    history.appendChild(node);
}

const getPokemon = async (pokemon) => {
    try {
        const resp = await fetch(`https://pokeapi.co/api/v2/pokemon/${pokemon.toLowerCase()}`);
        return await resp.json();
    } catch (e) {
        return false;
    }
}

const getColorByType = (type) => {
    switch (type) {
        case 'fire':
            return 'is-danger';
        case 'water':
            return 'is-info';
        case 'grass':
            return 'is-success';
        case 'electric':
            return 'is-warning';
        case 'flying':
            return 'is-link';
        default:
            return ''
    }
}

const imagesComponent = (image, imageShiny, imageBack, imageBackShiny) => {
    let html = `<img src="${image}">`
    html += `<img src="${imageShiny}">`
    html += `<img src="${imageBack}">`
    html += `<img src="${imageBackShiny}">`
    return html
}

const typesComponent = (types) => {
    let html = `<div class="mt-5 is-size-5 has-text-weight-bold">TYPES</div>`;
    types.forEach(type => {
        html += `<span class="tag ${getColorByType(type.type.name)} is-medium mr-2">${type.type.name.toUpperCase()}</span>`;
    });
    return html;
}

const statsComponent = (stats) => {
    let html = `<div class="mt-5 is-size-5 has-text-weight-bold">STATS</div>`;
    stats.forEach(stat => {
        html += `
        <div class="is-flex is-justify-content-space-between">
            <div class="has-text-weight-bold">${stat.stat.name.toUpperCase()}</div>
            <div class="has-text-weight-bold">${stat.base_stat}</div>
        </div>
        <progress class="progress is-primary is-small" value="${stat.base_stat}" max="255">${stat.base_stat}</progress>
        `
    });
    return html;
}

const printPokemon = (pokemon) => {
    let html = `<h3 class="title">#${pokemon.id} - ${pokemon.name.toUpperCase()}</h3>`;
    html += imagesComponent(pokemon.sprites.front_default, pokemon.sprites.front_shiny, pokemon.sprites.back_default, pokemon.sprites.back_shiny);
    html += typesComponent(pokemon.types);
    html += statsComponent(pokemon.stats);
    content.innerHTML = html;
}

const handleClean = () => {
    history.innerHTML = "";
}

form.addEventListener('submit', handleSubmit)
clean.addEventListener('click', handleClean)
