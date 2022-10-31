const goHome = () => {
  window.scrollTo({top: 0, behavior: 'smooth'});
};
const goSkills = () => {
  const el = document.querySelector("#skill").getBoundingClientRect();
  window.scrollTo({top: el.bottom + el.top, behavior: 'smooth'});
};
const goContact = () => {
  window.scrollTo({top: document.body.scrollHeight, behavior: 'smooth'});
};

document.querySelector("#home").addEventListener("click", goHome, false);
document.querySelector("#skill").addEventListener("click", goSkills, false);
document.querySelector("#contact").addEventListener("click", goContact, false);
