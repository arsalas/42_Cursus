class Car {
    id;
    distance;
    image;

    constructor(id) {
        this.id = id;
        this.image = `./images/car${id}.png`;
        this.distance = 0;
    }

    calcDist(dist){
        return (dist / parseInt(distance.value) * 100);
    }

    run() {
        const dist = Math.floor(Math.random() * 10) + 1;
        document.querySelector(`#car_${this.id}`).animate(
            {
                marginLeft: [`${this.calcDist(this.distance)}%`, `${this.calcDist(this.distance + dist) < 100 ? this.calcDist(this.distance + dist) : 100}%`]
            },
            {
                duration: 500,
                easing: "linear",
                iterations: 1,
                fill: "both"
            }
        );
        this.distance += dist;
        if (this.distance >= distance.value)
        {
            clearInterval(interval);
            console.log("FIN");
        }

    }
}