
export class TodoList {

    #todos;
    #maxId;

    constructor(todos = []) {
        this.#todos = todos;
        this.#maxId = this.#getMaxId();
    }

    create(description) {
        this.#maxId++;
        this.#todos.push({
            id: this.#maxId,
            description,
            completed: false
        });
        return this.#maxId;
    }

    #getMaxId() {
        let max;
        if (this.#todos.length === 0) return 0;
        for (let i = 0; i < this.#todos.length; i++) {
            const element = this.#todos[i];
            if (!max) max = element.id;
            else if (max < element.id) max = element.id;
        }
        return max + 1;
    }

    edit(id, content) {

        const index = this.#getIndexById(id);
        this.#todos[index].content = content;
        document.querySelector('#label-' + id).innerHTML = content;
    }


    delete(id) {
        const index = this.#getIndexById(id);
        this.#todos.splice(index, 1);
    }

    update(id, msg) {
        const index = this.#getIndexById(id);
        this.#todos[index].description = msg;
    }

    #getIndexById = (id) => this.#todos.findIndex(t => t.id === id);

    printTodo(id) {
        const todo = this.#todos.find(t => t.id === id)
        const html = ` <div id="todo-${todo.id}" class="panel-block is-flex is-justify-content-space-between">
       <div style="width:90%">
            <label id="check-${todo.id}">
               <input id="completed-${todo.id}" type="checkbox" class="is-clickable">
               <span id="label-${todo.id}">${todo.description}</span>
            </label>
            <form id="form-${todo.id}">
                <input id="input-${todo.id}" class="input is-small is-hidden"  type="text">
            </form>
        </div>
       <div>
           <span id="edit-${todo.id}" class="icon is-clickable">
               <i class="fa-solid fa-pen-to-square"></i> </span>
           <span id="delete-${todo.id}" class="icon is-clickable">
               <i class="fa-solid fa-trash-can"></i> </span>
       </div>
   </div>`;
        document.querySelector('#todoList').insertAdjacentHTML('beforeend', html)
    }

    completedTodo(id) {
        const index = this.#getIndexById(id);
        this.#todos[index].completed = !this.#todos[index].completed;
        return this.#todos[index].completed;
    }

    getProgress() {
        let completed = 0;
        this.#todos.forEach(todo => {
            if (todo.completed) completed++;
        });
        return { completed, total: this.#todos.length };

    }

}