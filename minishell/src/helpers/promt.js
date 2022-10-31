import { colors } from "./colors.js";

export const getPrompt = () => `${colors.fg.green}${process.env.USERDOMAIN}@minishell $ ${colors.reset}`;