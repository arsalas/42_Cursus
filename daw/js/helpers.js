/**
 * Ordenar una array de objetos por una key de manera ascendente
 */
const sortByKeyDesc = (array, key) => {
  return array.sort((a, b) => {
    const x = a[key];
    const y = b[key];
    return x < y ? -1 : x < y ? 1 : 0;
  });
};

/**
 * Genera un numero entre 1 y 10
 */
const getRandom = () => (Math.floor(Math.random() * 10) + 1)

/**
 * Obtiene la clase de css en funcion de la posicion del coche
 */
const getClassPosition = (position) => {
  switch (position) {
    case 1:
      return "first"
    case 2:
      return "second"
    case 3:
      return "third"
    }
    return "";
}

