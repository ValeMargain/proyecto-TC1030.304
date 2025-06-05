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
    // Constructores
    Rutina();
    Rutina(std::string& nombre);

    void agregarEjercicio(std::string ejercicio);
    void eliminarEjercicio(std::string& ejercicio);
    void mostrarEjercicios() const;

    // Getters y setters
    std::string getNombre() const;
    void setNombre( std::string& nuevoNombre);
};

Rutina::Rutina() : nombre("Rutina sin nombre"), numEjercicios(0) {}

Rutina::Rutina( std::string& nombre) : nombre(nombre), numEjercicios(0) {}
 void Rutina::agregarEjercicio(std::string ejercicio) {
    if (numEjercicios < 50) {
        ejercicios[numEjercicios++] = ejercicio;
    } else {
        std::cout << "No se pueden agregar más ejercicios. Límite alcanzado." << std::endl;
    }
}


void Rutina::eliminarEjercicio( std::string& ejercicio) {
    bool encontrado = false;
    for (int i = 0; i < numEjercicios; ++i) {
        if (ejercicios[i] == ejercicio) {
            for (int j = i; j < numEjercicios - 1; ++j) {
                ejercicios[j] = ejercicios[j + 1];
            }
            --numEjercicios;
            encontrado = true;
            if ( encontrado = true){
            std::cout << "Ejercicio eliminado: " << ejercicio << std::endl;
            }
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Ejercicio no encontrado: " << ejercicio << std::endl;
    }
}

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

std::string Rutina::getNombre() const {
    return nombre;
}

void Rutina::setNombre( std::string& nuevoNombre) {
    nombre = nuevoNombre;
}

#endif
