import * as readline from 'readline';
import { getPrompt } from '../helpers/index.js';

export const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: true,
    prompt: getPrompt(),
    history: [],
});
