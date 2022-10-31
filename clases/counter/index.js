const counter = window.document.querySelector('#counter');
const add = window.document.querySelector('#add');
const sustrac = window.document.querySelector('#sustrac');


const handlerAdd = () => {
    counter.innerHTML = parseInt(counter.textContent) + 1;
}
const handlerSustrac = () => {
    counter.innerHTML = parseInt(counter.textContent) - 1;
}

add.addEventListener('click', handlerAdd, false);
sustrac.addEventListener('click', handlerSustrac, false);