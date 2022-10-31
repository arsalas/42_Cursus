// Declaramos las variables del HTML
const n1 = document.querySelector("#n1");
const n2 = document.querySelector("#n2");
const add = document.querySelector("#add");
const subtract = document.querySelector("#subtract");
const multiply = document.querySelector("#multiply");
const division = document.querySelector("#division");
const result = document.querySelector("#result");

// Operaciones calculadora
const handleClick = (operation) => {
    const num1 = parseInt(n1.value);
    const num2 = parseInt(n2.value);
    switch (operation) {
        case 'add':
            printResult(num1 + num2);
            break;
        case 'subtract':
            printResult(num1 - num2);
            break;
        case 'multiply':
            printResult(num1 * num2);
            break;
        case 'division':
            printResult(num1 / num2);
            break;
    }
}

// Printar resultado
const printResult = (number) => {
    result.innerHTML = number;
}

// Escuchar eventos
add.addEventListener('click', handleClick.bind(this, 'add'));
subtract.addEventListener('click', handleClick.bind(this, 'subtract'));
multiply.addEventListener('click', handleClick.bind(this, 'multiply'));
division.addEventListener('click', handleClick.bind(this, 'division'));
