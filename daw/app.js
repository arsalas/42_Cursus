//import { test } from "./src/test.js";

console.log("probando");

class Car {
  id;
  distance;

  run() {
    Math.floor(Math.random() * 9);
  }
}

const start = () => {
  const app = document.querySelector("#app");
  const nCars = document.querySelector("#nCars");
  const distance = document.querySelector("#distance");
  const start = document.querySelector("#start");
  // app.innerHTML = "Hola Mundo";

  const run = () => Math.floor(Math.random() * 10) + 1;

  const getCars = () => {
    return [...Array(parseInt(nCars.value)).keys()];
  };

  start.addEventListener("click", () => {
    const a = getCars();
    console.log(
      a,
      nCars.value,
      distance.value,
      Math.floor(Math.random() * 10) + 1
    );
  });
};
