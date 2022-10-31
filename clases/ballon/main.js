const colors = {
  values: ["red", "blue", "green"],
  index: 0,
  size: 200,
  increment(element) {
    if (this.index === this.values.length - 1) this.index = 0;
    else this.index++;
    this.size += 10;
    if (this.size > 420) this.size = 200;
    this.apply(element);
  },
  decrement(element) {
    if (this.index === 0) this.index = this.values.length - 1;
    else this.index--;
    this.size -= 5;
    if (this.size < 200) this.size = 200;
    this.apply(element);
  },
  apply(element) {
    element.style.backgroundColor = this.values[this.index];
    element.style.width = `${this.size}px`;
  },
};

const ballon = document.querySelector("#ballon");

const handleClick = () => {
  colors.increment(ballon);
};

const handleMouseleave = () => {
  colors.decrement(ballon);
};

ballon.addEventListener("click", handleClick, false);
ballon.addEventListener("mouseleave", handleMouseleave, false);
