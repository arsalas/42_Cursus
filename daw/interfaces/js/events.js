
/**
 * Evento de click de boton start
 * Oculta el boton de start y muestra el de reset
 * Inicia la carrera
 */
params.start.addEventListener("click", () => {
    params.start.style.display = 'none';
    params.reset.style.display = 'block';
    params.nCars.disabled = true;
    startRace();
});

/**
 * Evento de click de boton restart
 * Oculta el boton de rest y muestra el de start
 * Para el event de la carrera
 */
params.reset.addEventListener("click", () => {
    CarController.loadCars();
    params.start.style.display = 'block';
    params.reset.style.display = 'none';
    params.nCars.disabled = false;
    clearInterval(params.interval);
    params.table.innerHTML = '';

});

/**
 * Prepara los datos de los coches al cambiar el desplegable
 */
params.nCars.addEventListener("change", () => {
    CarController.loadCars();
})

/**
 * Inicia la carrera con un interval cada x tiempo
 */
const startRace = () => {
    params.interval = setInterval(() => {
        CarController.cars.forEach((car) => {
            car.run();
        })
        if (params.positions.length == params.nCars.value) {
            clearInterval(params.interval);
            params.table.innerHTML = tableComponent();
        }
    }, params.speed)
}