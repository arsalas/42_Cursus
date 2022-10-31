// Este array no se puede modificar,
var posibilidades = ["piedra", "papel", "tijera"];
//    //

/**
 * Parametros que se usaran en la aplicacion
 */
const params = {
    isGameStart: false,
    name: document.querySelector("input[name='nombre']"),
    qGames: document.querySelector("input[name='partidas']"),
    actual: document.querySelector("#actual"),
    total: document.querySelector("#total"),
    history: document.querySelector("#historial"),
    playerImages: document.querySelector("#jugador"),
    machineImage: document.querySelector("#maquina img"),
    optionSelected: false,
    rivalOptionSelected: false,
    gamesPlayed: 0,
    play: document.querySelectorAll("button")[0],
    start: document.querySelectorAll("button")[1],
    reset: document.querySelectorAll("button")[2],
    images: {}
}

/**
 * Obtencion de que se va a jugar
 */
const getOption = () => {
    const index = Math.floor(Math.random() * 3)
    return posibilidades[index];
};

/**
 * Deja todas las imagenes con la clase noSeleccionado
 */
const clearSelectedImages = () => {
    for (let key in params.images) {
        params.images[key].classList.remove("seleccionado");
        params.images[key].classList.add("noSeleccionado");
    }
}

/**
 * Asigna las imagenes de cada opcion en funcion de la array de posibilidades
 */
const asignImagesPlayer = () => {
    params.images = {}
    params.playerImages.innerHTML = '';
    posibilidades.forEach((option) => {
        const img = document.createElement("img");
        img.src = `img/${option}Jugador.png`
        img.classList.add("noSeleccionado");
        params.playerImages.appendChild(img);
        params.images[option] = img;
        asignImageEvent(img, option);
    })
}

/**
 * Asigna el evento asociado a clicar la imagen
 * @param {string} img La ruta de la imagen
 * @param {string} option La opcion correspondiente a la imagen
 */
const asignImageEvent = (img, option) => {
    img.addEventListener('click', () => {
        params.optionSelected = option;
        clearSelectedImages();
        params.images[option].classList.remove("noSeleccionado");
        params.images[option].classList.add("seleccionado");
    })
}

/**
 * Comprueba si en nombre introducido en el input es valido
 * @returns true si el nombre es valido, false en caso contrario
 */
const isNameValid = () => {
    const name = params.name.value;
    if (name.length <= 3) return false;
    if (!isNaN(name.charAt(0))) return false;
    return true;
}

/**
 * Comprueba si la cantidad de partidas seleccionadas es valida
 * @returns true si el la cantidad de partidas es valida, false en caso contrario
 */
const isGamesValid = () => {
    if (parseInt(params.qGames.value) > 0) return true;
    else return false;
}

/**
 * Pinta en pantalla la cantidad de partidas jugadas
 */
const renderGamesPlayed = () => {
    params.actual.innerHTML = params.gamesPlayed;
}

/**
 * Pinta en pantalla la cantidad de partidas totales
 */
const renderTotalGames = () => {
    params.total.innerHTML = params.qGames.value;
}

/**
 * Incrementa el numero de partidas jugadas y las pinta en pantalla
 */
const increaseGamesPlayed = () => {
    ++params.gamesPlayed;
    renderGamesPlayed();
}

/**
 * Comprueba si los datos introducidos son validos y gestiona la clase correspondiente del input
 * @returns true si los datos introducidos son validos, false en caso contrario
 */
const validateData = () => {
    const name = isNameValid();
    const qGames = isGamesValid();

    if (!name) params.name.classList.add("fondoRojo");
    else params.name.classList.remove("fondoRojo");
    if (!qGames) params.qGames.classList.add("fondoRojo");
    else params.qGames.classList.remove("fondoRojo");
    if (name && qGames) return true;
    else return false;
}

/**
 * Desactiva los inputs del formulario
 */
const disabledInputs = () => {
    params.name.disabled = true;
    params.qGames.disabled = true;
}

/**
 * Activa los inputs del formulario
 */
const enabledInputs = () => {
    params.name.disabled = false;
    params.qGames.disabled = false;
}

/**
 * Evento que se activa al apretar el boton de JUGAR
 */
const playAction = () => {
    // Si la partida no ha empezado no deja elegir la accion
    if (params.isGameStart) return;
    params.isGameStart = validateData();
    if (params.isGameStart) {
        disabledInputs();
        renderTotalGames(params.qGames.value);
    } else {
        enabledInputs();
    }
}

/**
 * El jugador gana la partida y lo indica en el historial
 */
const winGame = () => {
    addHistory(`Gana ${params.name.value}`);
}

/**
 * El jugador pierde la partida y lo indica en el historial
 */
const loseGame = () => {
    addHistory(`Gana la maquina`);
}

/**
 * El jugador empata la partida y lo indica en el historial
 */
const drawGame = () => {
    addHistory(`Empate`);
}

/**
 * Pinta en pantalla un nuevo registro en el historial
 * @param {string} text Texto que se imprimira en el historial
 */
const addHistory = (text) => {
    const li = document.createElement("li");
    li.appendChild(document.createTextNode(text));
    params.history.appendChild(li);
}

/**
 * Comprueba el resultado de la partida y pinta en el historial el resultado
 * @param {number} iPlayer La posicion de la accion del jugador en la array de posibilidades 
 * @param {number} iMachine La posicion de la accion de la maquina en la array de posibilidades 
 */
const resultGame = (iPlayer, iMachine) => {
    if (iPlayer === iMachine) drawGame();
    else if ((iPlayer === 0 && iMachine === posibilidades.length - 1) || iPlayer - 1 === iMachine)
        winGame();
    else loseGame();
    increaseGamesPlayed();
}

/**
 * Busca el indice de la accion enviada
 * @param {string} option Un elemento de la array de posibilidades 
 * @returns La posicion en el array de option
 */
const findIndexByOption = (option) => posibilidades.findIndex(opt => opt === option);

/**
 * Accion que se realiza al pulsar el boton de YA
 */
const choosedAction = () => {
    if (!params.optionSelected || !params.isGameStart) return;
    params.rivalOptionSelected = getOption();
    params.machineImage.src = `img/${params.rivalOptionSelected}Ordenador.png`
    const iPlayer = findIndexByOption(params.optionSelected);
    const iMachine = findIndexByOption(params.rivalOptionSelected);
    resultGame(iPlayer, iMachine);
}

/**
 * Reinicia a los valores por defecto de la aplicacion
 */
const resetValues = () => {
    params.qGames.value = 0;
    params.gamesPlayed = 0;
    params.machineImage.src = "img/defecto.png";
    params.isGameStart = false;
}

/**
 * Reinicia la partida
 */
const resetGame = () => {
    if (!params.isGameStart) return;
    addHistory("Nueva partida");
    enabledInputs();
    resetValues();
    clearSelectedImages();
    renderTotalGames();
    renderGamesPlayed(0);
}

// EVENTOS
params.play.addEventListener('click', playAction);
params.start.addEventListener('click', choosedAction);
params.reset.addEventListener('click', resetGame);

asignImagesPlayer();
