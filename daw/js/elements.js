const carElement = (car) => {
    return (
      `<div class="road">
        <img id="car_${car.id}" src="${car.image}" />
      </div>`
    )
  }

const roadElement = () => {
    return (
      `<div class="road">
      </div>`
    )
  }