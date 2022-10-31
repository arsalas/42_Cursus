const carElement = (car) => {
  return `<div class="road">
        <img id="car_${car.id}" src="${car.image}" />
      </div>`;
};

const roadElement = () => {
  return `<div class="road"></div>`;
};

const sortByKeyDesc = (array, key) => {
  return array.sort((a, b) => {
    const x = a[key];
    const y = b[key];
    return x > y ? -1 : x < y ? 1 : 0;
  });
};

const createTable = () => {
  let tableHtml = `
  <table>
  <tr>
    <th></th>
    <th>Car</th>
    <th>Position</th>
    <th>Distance</th>
  </tr>`;
  const carSort = sortByKeyDesc(cars, "distance");
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
