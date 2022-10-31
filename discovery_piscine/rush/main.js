const goHome = () => scrollTo("#home-section");
const goSkills = () => scrollTo("#skill-section");
const goContact = () => scrollTo("#contact-section");

const scrollTo = (id) => {
  document.querySelector(id).scrollIntoView({ behavior: "smooth" });
};

document.querySelector("#home").addEventListener("click", goHome, false);
document.querySelector("#skill").addEventListener("click", goSkills, false);
document.querySelector("#contact").addEventListener("click", goContact, false);
