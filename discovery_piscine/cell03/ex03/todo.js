const add = document.querySelector("#add");

const handleClick = () => {
    const todo = prompt();
    if (todo.length == 0) return;
    console.log(todo);
    const confirm = confirm("confirm");
    console.log(confirm)
};



add.addEventListener("click", handleClick, false);
