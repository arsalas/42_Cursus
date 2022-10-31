class Car {
    id;
    distance;
    image;

    constructor(id) {
        this.id = id;
        this.image = `./images/car${id}.png`;
        this.distance = 0;
    }

    run() {
        if (this.distance < 100) {
            const dist = getRandom();
            document.querySelector(`#car_${this.id}`).animate(
                {
                    marginLeft: [`${this.distance}%`, `${(this.distance + dist) < 100 ? this.distance + dist : 100}%`]
                },
                {
                    duration: params.speed.value * 250,
                    easing: "linear",
                    iterations: 1,
                    fill: "both"
                }
            );
            this.distance += dist;
            if (this.distance >= 100) {
                // clearInterval(params.interval);
                params.positions.push(this.id);
            }
        }
    }
}