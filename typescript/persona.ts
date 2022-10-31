import { Direccion } from "./direccion";
import { Mail } from "./mail";
import { Telefono } from "./telefono";

enum Sexo {
    H = 'Hombre',
    M = 'Mujer',
}

export class Persona {

    private nombre: string;
    private apellidos: string;
    private edad: number;
    private dni: string;
    private cumpleanos: Date;
    private color: string;
    private sexo: Sexo;
    private direcciones: Direccion[];
    private mails: Mail[];
    private telefonos: Telefono[];
    private notas: string;

    public constructor(nombre: string, apellidos: string, edad: number, sexo: string, cumpleanos: Date) {
        this.nombre = nombre;
        this.apellidos = apellidos;
        this.edad = edad;
        this.sexo = Sexo[sexo];
        this.cumpleanos = cumpleanos;
    }

    public createPersona() {

    }

    public print() {
        console.log("Nombre: " + this.nombre);
        console.log("Apellidos: " + this.apellidos);
        console.log("Edad: " + this.edad);
        console.log("Sexo: " + this.sexo);
        console.log("Cumpleaños: " + this.cumpleanos);
    }
}