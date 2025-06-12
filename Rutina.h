/*
 * Proyecto 
 * Danna Valeria Rosales Margain
 * A01669036
 * 11/06/2025
 * Clase que representa una rutina de ejercicios 
 * con un nombre y una lista de hasta 50 ejercicios.
 * Permite agregar, eliminar, mostrar ejercicios, 
 * y modificar el nombre de la rutina.
 */

#ifndef RUTINA_H
#define RUTINA_H

#include <iostream>
#include <string>

class Rutina {
private:
    std::string nombre;
    std::string ejercicios[50];  // Arreglo estático para los ejercicios
    int numEjercicios;           // Contador de ejercicios agregados

public:
  
/**
 * Constructor por defecto que inicializa la rutina con nombre genérico y sin ejercicios.
 *
 * @param
 * @return Constructor que no retorna nada.
 */
    Rutina();
    Rutina(const std::string& nombre);

    void agregarEjercicio(std::string ejercicio);
    void eliminarEjercicio(std::string& ejercicio);
    void mostrarEjercicios() const;

    // Getters y setters
    std::string getNombre() const;
    void setNombre(std::string& nom);
};

Rutina::Rutina() : nombre("Rutina sin nombre"), numEjercicios(0) {}

/**
 * Agrega un ejercicio al arreglo si no 
 * se ha alcanzado el límite de 50.
 *
 * @param ejercicio Nombre del ejercicio a agregar.
 * @return Agrega el ejercicio al arreglo 
 * si hay espacio disponible.
 */
Rutina::Rutina(const std::string& nombre) : nombre(nombre), numEjercicios(0) {}
 void Rutina::agregarEjercicio(std::string ejercicio) {
    if (numEjercicios < 50) {
        ejercicios[numEjercicios++] = ejercicio;
    } else {
        std::cout << "No se pueden agregar mas ejercicios. Limite alcanzado." << std::endl;
    }
}

/**
 * Elimina un ejercicio de la rutina si existe.
 * Recorre los elementos para mantener el orden.
 *
 * @param ejercicio Referencia al nombre del ejercicio a eliminar.
 * @return Muestra en consola si el ejercicio fue 
 * eliminado o no encontrado.
 */
void Rutina::eliminarEjercicio( std::string& ejercicio) {
    bool encontrado = false;
    for (int i = 0; i < numEjercicios; ++i) {
        if (ejercicios[i] == ejercicio) {
            for (int j = i; j < numEjercicios - 1; ++j) {
                ejercicios[j] = ejercicios[j + 1];
            }
            --numEjercicios;
            encontrado = true;
            if ( encontrado == true){
            std::cout << "Ejercicio eliminado: " << ejercicio << std::endl;
            }
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Ejercicio no encontrado: " << ejercicio << std::endl;
    }
}

/**
 * Muestra en consola todos los ejercicios 
 * contenidos en la rutina.
 *
 * @param
 * @return Imprime el nombre de la rutina y sus ejercicios 
 * (si existen).
 */
void Rutina::mostrarEjercicios() const{
    std::cout << "Rutina: " << nombre << std::endl;
    if (numEjercicios == 0) {
        std::cout << "No hay ejercicios en esta rutina." << std::endl;
    } else {
        for (int i = 0; i < numEjercicios; ++i) {
            std::cout << "- " << ejercicios[i] << std::endl;
        }
    }
}

/**
 * Devuelve el nombre de la rutina.
 *
 * @param
 * @return string con el nombre de la rutina.
 */
std::string Rutina::getNombre() const {
    return nombre;
}

/**
 * Asigna un nuevo nombre a la rutina.
 *
 * @param nom Referencia al nuevo nombre para la rutina.
 * @return Actualiza el atributo `nombre` de la rutina.
 */
void Rutina::setNombre( std::string& nom) {
    nombre = nom;
}

#endif
