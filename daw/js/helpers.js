/**
 * Ordenar una array de objetos por una key de manera descendente
 */
const sortByKeyDesc = (array, key) => {
  return array.sort((a, b) => {
    const x = a[key];
    const y = b[key];
    return x > y ? -1 : x < y ? 1 : 0;
  });
};

/**
 * Genera un numero entre 1 y 10
 */
const getRandom = () => (Math.floor(Math.random() * 10) + 1)
