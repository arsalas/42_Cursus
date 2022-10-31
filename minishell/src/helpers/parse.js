
const quantityQuotes = (str, c) => {
    if (c !== '"' || c !== "'")
        return 0;
    return str.split('').filter(c => c == c).length;
}

const executeCmd = (tokens) => {
    if (tokens[0] == 'echo') {
        tokens.shift();
        const str = [];
        const quotes = {
            isOpen: false,
            type: "",
            content: []
        }
        tokens.map(token => {

            if (token.includes('"')) {
                let aux = token.split('"');
                // Expandimos las variables
                aux = aux.map(a => {
                    if(a.charAt(0) == '$') {
                        a = a.replace('$', '');
                        a = process.env[a];
                    }
                    return a;
                })
                str.push( aux.join(''));
            }





            // if (token.includes('"')) {
            //     if (!quotes.isOpen) {
            //         const repitChars = quantityQuotes(token, '"');
            //         if (repitChars == 2) {
            //             str.push(token.replaceAll('"', ''));
            //         }
            //     }
            // }
        })

        console.log(str.join(' '));
    }
    else if (tokens[0] == 'env')
        console.log(process.env);
    else if (tokens[0] == 'export') {

        for (let clave in process.env) {
            console.log('declare -x', process.env[clave]);
        }
    }
}


export const parseLine = (line) => {
    const tokens = line.trim().split(' ');
    executeCmd(tokens);
}