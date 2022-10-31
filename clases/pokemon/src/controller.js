import { getPokemon, printPokemon } from "./pokemon.js";

export const Controller = {
    search: document.querySelector("#search"),
    form: document.querySelector("#form"),
    history: document.querySelector("#history"),
    content: document.querySelector("#content"),
    clean: document.querySelector("#clean"),
    addHistory: (image) => {
        const self = Controller;
        const node = document.createElement("img");
        node.src = image;
        self.history.appendChild(node);
    },
    handleSubmit: async (e) => {
        const self = Controller;
        e.preventDefault();
        self.content.innerHTML = "Searching...";
        const pokemon = await getPokemon(self.search.value);
        if (pokemon) {
            printPokemon(pokemon);
            self.addHistory(pokemon.sprites.front_default);
            self.form.reset();
        }
        else self.content.innerHTML = "Pokemon not found";
    },
    handleClean: () => Controller.history.innerHTML = "",
    start: () => {
        const self = Controller;
        console.log("START APP");
        self.form.addEventListener('submit', self.handleSubmit);
        self.clean.addEventListener('click', self.handleClean);
    }
}