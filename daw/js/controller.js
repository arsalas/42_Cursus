const CarController = {
    cars: [],
    maxCars: 9,

    /**
     * Crea la array de instancias de la clase coche
     */
    createCars() {
        for (let i = 1; i <= params.nCars.value; i++) {
            const car = new Car(i);
            this.cars = [...this.cars, car];
        }
    },

    /**
     * Destruye las instancias de la clase coche y vacia la array
     */
    destroyCars() {
        this.cars.forEach((car) => {
            car.destroy;
        })
        this.cars = [];
    },

    /**
     * Printa los coches y los carriles vacios hasta el maximo de posiciones
     */
    printCars() {
        let html = '';
        this.cars.forEach((car) => {
            html += carComponent(car)
        })
        for (i = this.cars.length; i <= this.maxCars; i++)
            html += roadComponent();
        params.app.innerHTML = html;
    },

    /**
     * Inicia el proceso de la creacion y printado de coches
     */
    loadCars() {
        this.destroyCars();
        this.createCars();
        this.printCars();
    }
}