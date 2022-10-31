/**
 * html del coche y la carretera
 */
const carComponent = (car) => {
  return (`<div class="road">
        <img id="car_${car.id}" src="${car.image}" />
      </div>`);
};

/**
 * html de la carretera sin coche
 */
const roadComponent = () => {
  return (`<div class="road"></div>`);
};

/**
 * Crea la tabla de html con las posiciones de cada coche
 */
const tableComponent = () => {
  let tableHtml = `
  <table>
  <tr>
    <th></th>
    <th>Car</th>
    <th>Position</th>
    <th>Distance</th>
  </tr>`;
  const carSort = sortByKeyDesc(CarController.cars, "distance");
  carSort.forEach((row, index) => {
    tableHtml += `
    <tr>
      <th><img src='${row.image}' /></th>
      <th>Coche ${row.id}</th>
      <th>${index + 1}</th>
      <th>${row.distance}</th>
    </tr>
    `;
  });
  tableHtml += `</table>`;
  return tableHtml;
};
