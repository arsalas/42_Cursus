const goHome = () => {
  const ele = document.querySelector("#home").scrollIntoView();
};
const goSkills = () => {
  const ele = document.querySelector("#skill").scrollIntoView();
};
const goContact = () => {
  const ele = document.querySelector("#contact").scrollIntoView();
};

document.querySelector("#home").addEventListener("click", goHome, false);
document.querySelector("#skill").addEventListener("click", goSkills, false);
document.querySelector("#contact").addEventListener("click", goContact, false);
