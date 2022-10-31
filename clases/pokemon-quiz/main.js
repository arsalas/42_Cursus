import { getPokemonApi } from "./src/api.js";

const data = {
    pokemon: 1,
    options: [],
    games: 0,
    success: 0,
    click: false
}

const getPokemons = () => {
    const options = [];
    while (options.length < 4) {
        const id = Math.ceil(Math.random() * 650);
        if (!options.includes(id)) options.push(id)
    }
    return options;
}

const getPokemon = async (id) => {
    const pokemon = await getPokemonApi(id)
    if (!pokemon) return false;
    return {
        id,
        name: pokemon.name
    }
}

const printOptions = (options) => {
    for (let i = 0; i < options.length; i++) {
        const opt = options[i];
        getPokemon(opt).then(res => document.querySelector(`#opt${i + 1}`).textContent = res.name)

    }
}




const printPokemonImg = (id) => {
    document.querySelector('#pkmImg').innerHTML = ` <img class="hidden" src="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/other/dream-world/${id}.svg" alt="pokemon">`;
}


const handleClick = (option) => {
    if (data.click)
        return;
    data.click = true;
    data.games++
    document.querySelector('img').classList.remove('hidden');

    if (data.options[option - 1] == data.pokemon) {
        printResult(true);
        data.success++;
    } else {
        printResult(false);

    }
    setTimeout(() => {
        start()
    }, 1000);
}

const printResume = () => {
    document.querySelector('#resume').innerHTML = `aciertos: ${data.success}  fallos: ${data.games - data.success}`
}
const printResult = (result) => {
    let html;
    if (result) {
        html = 'CORRECTO!';
        document.querySelector('#result').classList.add('success')
        document.querySelector('#result').classList.remove('fail')
    }
    else {
        document.querySelector('#result').classList.add('fail')
        document.querySelector('#result').classList.remove('success')
        html = 'FALLASTE!';
    }
    document.querySelector('#result').innerHTML = html
}

const start = async () => {
    data.options = []
    data.click = false;
    printResume();
    document.querySelector('#result').classList.remove('success')
    document.querySelector('#result').classList.remove('fail')
    document.querySelector('#result').innerHTML = 'SELECCIONA UNA OPCION'
    const pokemons = getPokemons();
    printPokemonImg(pokemons[0]);
    data.pokemon = pokemons[0]
    data.options = pokemons;
    data.options.sort(() => Math.random() - 0.5);
    printOptions(data.options);



    document.querySelector('#opt1').addEventListener('click', handleClick.bind(this, 1), false)
    document.querySelector('#opt2').addEventListener('click', handleClick.bind(this, 2), false)
    document.querySelector('#opt3').addEventListener('click', handleClick.bind(this, 3), false)
    document.querySelector('#opt4').addEventListener('click', handleClick.bind(this, 4), false)
}

start();
