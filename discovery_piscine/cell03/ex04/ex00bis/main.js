const getRandom = () => Math.ceil(Math.random() * 255);

const handleClick = () => {
  $("#body").css(
    "backgroundColor",
    `rgb(${getRandom()}, ${getRandom()}, ${getRandom()})`
  );
};

$("#btn").click(handleClick);
