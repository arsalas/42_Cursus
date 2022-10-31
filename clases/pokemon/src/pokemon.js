import { getPokemonApi } from "./api.js";
import { imagesComponent, statsComponent, typesComponent, titleComponent } from "./components.js";

export const getPokemon = async (pokemon) => getPokemonApi(pokemon);

export const printPokemon = (pokemon) => {
    let html = titleComponent(pokemon.id, pokemon.name);
    html += imagesComponent(pokemon.sprites.front_default, pokemon.sprites.front_shiny, pokemon.sprites.back_default, pokemon.sprites.back_shiny);
    html += typesComponent(pokemon.types);
    html += statsComponent(pokemon.stats);
    content.innerHTML = html;
}
