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

    // Métodos para manipular ejercicios
    // En la clase
    void agregarEjercicio(std::string ejercicio);
    void eliminarEjercicio(std::string& ejercicio);
    void mostrarEjercicios() ;

    // Getters y setters
    std::string getNombre() ;
    void setNombre( std::string& nuevoNombre);
};



// Implementación de constructores y métodos inline para claridad 

inline Rutina::Rutina() : nombre("Rutina sin nombre"), numEjercicios(0) {}

inline Rutina::Rutina( std::string& nombre) : nombre(nombre), numEjercicios(0) {}

inline void Rutina::agregarEjercicio(std::string ejercicio) {
    if (numEjercicios < 50) {
        ejercicios[numEjercicios++] = ejercicio;
    } else {
        std::cout << "No se pueden agregar más ejercicios. Límite alcanzado." << std::endl;
    }
}


inline void Rutina::eliminarEjercicio( std::string& ejercicio) {
    bool encontrado = false;
    for (int i = 0; i < numEjercicios; ++i) {
        if (ejercicios[i] == ejercicio) {
            for (int j = i; j < numEjercicios - 1; ++j) {
                ejercicios[j] = ejercicios[j + 1];
            }
            --numEjercicios;
            encontrado = true;
            std::cout << "Ejercicio eliminado: " << ejercicio << std::endl;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Ejercicio no encontrado: " << ejercicio << std::endl;
    }
}

inline void Rutina::mostrarEjercicios()  {
    std::cout << "Rutina: " << nombre << std::endl;
    if (numEjercicios == 0) {
        std::cout << "No hay ejercicios en esta rutina." << std::endl;
    } else {
        for (int i = 0; i < numEjercicios; ++i) {
            std::cout << "- " << ejercicios[i] << std::endl;
        }
    }
}

inline std::string Rutina::getNombre()  {
    return nombre;
}

inline void Rutina::setNombre( std::string& nuevoNombre) {
    nombre = nuevoNombre;
}

#endif
