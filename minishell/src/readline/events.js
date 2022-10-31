import { parseLine } from "../helpers/parse.js";
import { rl } from "./init.js";


export const initEvents = () => {

    // Iniciamos la lectura de lineas
    rl.prompt();

    /**
     * Salto de linea al pulsar Ctrl+C
     */
    rl.on('SIGINT', () => {
        console.log('');
        rl.prompt();
    });

    /**
     * Parseamos la nueva linea y iniciamos una nueva peticion de linea
     */
    rl.on('line', (line) => {
        parseLine(line);
        rl.prompt();
        rl.history.push(line);
    })

    // rl.on('history', (history) => {
    //     // console.log(`Received: ${history}`);
    // });

    // rl.on("close", function () { "console.log('Goodbye!')" });

    // rl.on('pause', () => {
    //     console.log('Readline paused.');
    // });

    // rl.on('resume', () => {
    //     console.log('Readline resumed.');
    // });

    // rl.on('SIGCONT', () => {
    //     // `prompt` will automatically resume the stream
    //     console.log("sigcount");
    //     rl.prompt();
    // });



    // rl.on('SIGTSTP', () => {
    //     // This will override SIGTSTP and prevent the program from going to the
    //     // background.
    //     console.log('Caught SIGTSTP.');
    // });




}