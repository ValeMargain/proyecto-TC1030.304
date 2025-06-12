/*
 * Proyecto Gym - Sistema de Gestión
 * Danna Valeria Rosales Margain
 * A01669036
 * 11/06/2025
 *
 * Este es un proyecto para la clase de Programación Orientada a Objetos.
 * El programa gestiona la información de un gimnasio, incluyendo usuarios,
 * entrenadores, membresías y rutinas de ejercicio. Permite crear y administrar
 * estos elementos, asignar rutinas a entrenadores y usuarios, controlar la
 * validez de membresías, y mostrar información relevante de cada entidad.
 */
#include "Menu.h"
int main() {
    Menu menu;
    int opcion;

    do {
        menu.mostrarMenuPrincipal();
        
        cin >> opcion;
        cin.ignore();
        menu.ejecutarOpcion(opcion);
    } while (opcion != 0);

    return 0;
}
