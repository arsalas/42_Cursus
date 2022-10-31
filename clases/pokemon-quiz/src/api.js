const url = "https://pokeapi.co/api/v2/pokemon/"

export const getPokemonApi = async (id) => {
    try {
        const resp = await fetch(url + id);
        return await resp.json();
    } catch (e) {
        return false;
    }
}