import { TodoList } from "./TodoList.js";


export class TodoController {

    #form = window.document.querySelector('#todoForm');
    #input = window.document.querySelector('#todoInput');
    #progress = window.document.querySelector('#progress');
    #completed = window.document.querySelector('#completed');
    #todosList = new TodoList();

    start() {
        console.log("START APP");
        this.#form.addEventListener('submit', this.#handlerSubmit.bind(this), false);
    }

    #listenEvents(id) {
        document.querySelector(`#delete-${id}`).addEventListener('click', this.#handlerClickDelete.bind(this, id), false);
        document.querySelector(`#edit-${id}`).addEventListener('click', this.#handlerClickEdit.bind(this, id), false);
        document.querySelector(`#completed-${id}`).addEventListener('change', this.#handlerChange.bind(this, id), false);
        document.querySelector(`#form-${id}`).addEventListener('submit', this.#handlerSubmitEdit.bind(this, id), false);
    }


    #handlerSubmit(ev) {
        ev.preventDefault();
        const id = this.#todosList.create(this.#input.value);
        this.#todosList.printTodo(id);
        this.#listenEvents(id);
        this.#form.reset();
        this.#updateProgress();
    }

    #handlerSubmitEdit(id, ev) {
        ev.preventDefault();
        const check = document.querySelector(`#check-${id}`);
        const input = document.querySelector(`#input-${id}`);
        check.classList.remove('is-hidden');
        input.classList.add('is-hidden');
        this.#todosList.update(id, input.value);
        document.querySelector(`#label-${id}`).innerHTML = input.value;
    }

    #handlerClickDelete(id) {
        document.querySelector(`#delete-${id}`).removeEventListener('click', this.#handlerClickDelete, false);
        document.querySelector(`#edit-${id}`).removeEventListener('click', this.#handlerClickEdit, false);
        document.querySelector(`#completed-${id}`).removeEventListener('change', this.#handlerChange, false);
        document.querySelector(`#form-${id}`).removeEventListener('submit', this.#handlerSubmitEdit, false);
        document.querySelector(`#todo-${id}`).remove();
        this.#todosList.delete(id);
        this.#updateProgress();

    }

    #handlerClickEdit(id) {
        const check = document.querySelector(`#check-${id}`);
        const input = document.querySelector(`#input-${id}`);
        check.classList.add('is-hidden');
        input.classList.remove('is-hidden');
        input.value = document.querySelector(`#label-${id}`).textContent;
        input.select();
    }

    #handlerChange(id) {
        const label = document.querySelector(`#label-${id}`);
        if (this.#todosList.completedTodo(id)) label.style.textDecoration = 'line-through';
        else label.style.textDecoration = 'none';
        this.#updateProgress();
    }

    #updateProgress() {
        const { completed, total } = this.#todosList.getProgress();
        this.#progress.setAttribute('value', completed / total * 100);
        this.#completed.innerHTML = `${completed} / ${total}`
    }

}



