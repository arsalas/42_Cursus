/**
 * Declaracion de las variables
 */
const params = {
  app: document.querySelector("#app"),
  nCars: document.querySelector("#nCars"),
  start: document.querySelector("#start"),
  reset: document.querySelector("#reset"),
  table: document.querySelector("#table"),
  speed: 500,
  positions: [],
  interval: undefined
}


CarController.loadCars();