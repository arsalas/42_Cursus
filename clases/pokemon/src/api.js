const url = "https://pokeapi.co/api/v2/pokemon/"

export const getPokemonApi = async (pokemon) => {
    try {
        const resp = await fetch(url + pokemon.toLowerCase());
        return await resp.json();
    } catch (e) {
        return false;
    }
}