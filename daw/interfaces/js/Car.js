/**
 * Clase para gestionar el movimiento y informacion de cada coche
 */
class Car {
    id;
    distance;
    image;
    position;

    constructor(id) {
        this.id = id;
        this.image = `./images/car${id}.png`;
        this.distance = 0;
    }

    /**
     * Recorre una distancia aleatorea y anima el movimiento del coche
     */
    run() {
        if (this.distance < 100) {
            const dist = getRandom();
            document.querySelector(`#car_${this.id}`).animate(
                {
                    marginLeft: [`${this.distance}%`, `${(this.distance + dist) < 100 ? this.distance + dist : 100}%`]
                },
                {
                    duration: params.speed,
                    easing: "linear",
                    iterations: 1,
                    fill: "both"
                }
            );
            this.distance += dist;
            if (this.distance >= 100) this.finish();
        }
    }

    /**
     * Asigna la posicion final del coche en la carrera
     */
    finish() {
        params.positions.push(this.id);
        this.position = params.positions.length;
    }
}