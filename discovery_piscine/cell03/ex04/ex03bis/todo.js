const todos = JSON.parse(localStorage.getItem("todo")) || [];

const handleClick = () => {
  const todo = prompt();
  if (!todo || todo.length === 0) return;
  addTodo(todo);
};

const getNextId = () => {
  let id = 0;
  todos.forEach((todo) => {
    if (todo.id > id) id = todo.id;
  });
  id++;
  return id;
};

const saveStorage = () => {
  localStorage.setItem("todo", JSON.stringify(todos));
};

function handleDelete() {
  const canDelete = confirm("confirm");
  if (!canDelete) return;
  $(`#${this.id}`).click(handleDelete);
  $(`#${this.id}`).remove();
  const id = this.id.split("todo_")[1];
  const i = todos.findIndex((t) => t.id == id);
  todos.splice(i, 1);
  saveStorage();
}

const printTodo = (newId, todo) => {
  const id = `todo_${newId}`;
  const html = `<div id="${id}" class="todo">${todo}</div>`;
  $("#ft_list").prepend(html);
  $(`#${id}`).click(handleDelete);
};

const addTodo = (todo) => {
  const id = getNextId();
  printTodo(id, todo);
  todos.push({ id, todo });
  saveStorage();
};

$("#add").click(handleClick);
todos.forEach((todo) => {
  printTodo(todo.id, todo.todo);
});
