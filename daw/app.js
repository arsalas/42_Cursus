
// Declaracion de variables
const app = document.querySelector("#app");
const nCars = document.querySelector("#nCars");
const distance = document.querySelector("#distance");
const start = document.querySelector("#start");
const reset = document.querySelector("#reset");
let cars = [];
let interval;


// Creacion de la array de coches
const createCars = () => {
  for (let i = 1; i <= nCars.value; i++) {
    const car = new Car(i);
    cars = [...cars, car];
  }
}

const destroyCars = () => {
  cars.forEach((car) => {
    car.destroy;
  })
  cars = [];
}

const printCars = () => {
  let html = '';
  cars.forEach((car) => {
    html += carElement(car)
  })
  for (i = cars.length; i <= 9; i++)
    html += roadElement();
  app.innerHTML = html;
}

const loadCars = () => {
  destroyCars();
  createCars();
  printCars();
}

