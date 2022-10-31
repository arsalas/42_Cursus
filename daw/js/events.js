
start.addEventListener("click", () => {
    start.style.display = 'none';
    reset.style.display = 'block'
    nCars.disabled = true;
    distance.disabled = true;
    startRace();
});

reset.addEventListener("click", () => {
    loadCars();
    start.style.display = 'block';
    reset.style.display = 'none';
    nCars.disabled = false;
    distance.disabled = false;
    clearInterval(interval);
    table.innerHTML = '';

});

nCars.addEventListener("change", () => {
    loadCars();
})

const startRace = () => {

    interval = setInterval(() => {
        cars.forEach((car) => {
            car.run();
        })
        table.innerHTML = createTable();
    }, 500)
}
