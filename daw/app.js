/**
 * Declaracion de las variables
 */
const params = {
  app: document.querySelector("#app"),
  nCars: document.querySelector("#nCars"),
  speed: document.querySelector("#speed"),
  start: document.querySelector("#start"),
  reset: document.querySelector("#reset"),
  table: document.querySelector("#table"),
  positions: [],
  interval: undefined
}


CarController.loadCars();