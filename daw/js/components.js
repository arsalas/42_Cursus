/**
 * html del coche y la carretera
 */
const carComponent = (car) => {
  return `<div class="road">
        <img id="car_${car.id}" src="${car.image}" />
      </div>`;
};

/**
 * html de la carretera sin coche
 */
const roadComponent = () => {
  return `<div class="road"></div>`;
};

/**
 * Crea el componente del coche en funcion de su posicion
 */
const positionComponent = (position) => {
  switch (position) {
    case 1:
      return "<img src='images/gold.png'>";
    case 2:
      return "<img src='images/silver.png'>";
    case 3:
      return "<img src='images/bronze.png'>";
    default:
      return position;
  }
};

/**
 * Crea la tabla de html con las posiciones de cada coche
 */
const tableComponent = () => {
  let tableHtml = `<div class="container-table">
  <div class="table">`;
  const carSort = sortByKeyDesc(CarController.cars, "position");
  carSort.forEach((row) => {
      tableHtml += `
      <div class="row ${getClassPosition(row.position)}">
      <div class="column"><img src='${row.image}' /></div>
      <div class="column position">${positionComponent(row.position)}</div>
      </div>
      `;
  });
  tableHtml += `</div></div>`;
  return tableHtml;
};
