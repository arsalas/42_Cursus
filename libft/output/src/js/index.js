const start = () => {
    const div = document.querySelector("#result");
    console.log(div);
    div.innerHTML =`<h2>456</h2>`;
    div.append(JSON.stringify(data));

}