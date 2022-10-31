// Declaramos las variables del HTML
const timer = document.querySelector("#time");
const start = document.querySelector("#start");
const counter = document.querySelector("#counter");

// Funcion del boton
const handleStart = () => {
    start.disabled = true;
    timer.disabled = true;
    let time = timer.value
    counter.innerHTML = time;
    const event = setInterval(() => {
        time--;
        counter.innerHTML = time;
        if (time == 0) {
            clearInterval(event);
            start.disabled = false;
            timer.disabled = false;
        }
    }, 1000)
}

// Escuchar eventos
start.addEventListener('click', handleStart);
