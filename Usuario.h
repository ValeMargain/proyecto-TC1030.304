/*
 * Proyecto 
 * Danna Valeria Rosales Margain
 * A01669036
 * 11/06/2025
 * Clase que representa a un usuario del gimnasio.
 * Hereda de Persona y contiene información adicional como
 * entrenador asignado,
 * membresía activa y rutina personal de ejercicios
 */

#ifndef USUARIO_H
#define USUARIO_H


#include <iostream>
#include <string>
#include "Persona.h"
#include "Entrenador.h"
#include "Membresia.h"
#include "Rutina.h"

using namespace std;

class Usuario : public Persona {
private:
    Persona* coach;
    Membresia* membresia;
    Rutina* rutina;


public:
    Usuario ();
     Usuario(std::string nombre, std::string apepat, std::string apemat,
            std::string telefono, std::string correo, std::string fecnac,
            Persona* coach, Membresia* mem, Rutina* rut);

    void mostrarInfo();

    // Getters y setters si se requieren
    void setCoach(Persona* entrenador);
    void setMembresia(Membresia* mem);
    void setRutina(Rutina* rut);

    Persona* getCoach() const;
    Membresia* getMembresia() const;
    Rutina* getRutina() const;
};


Usuario::Usuario() : Persona("", "", "", "", "", ""), 
coach(nullptr), membresia(nullptr), rutina(nullptr) {}

Usuario::Usuario(std::string nombre, std::string apepat, std::string apemat,
                 std::string telefono, std::string correo, std::string fecnac,
                 Persona* coach, Membresia* mem, Rutina* rut)
    : Persona(nombre, apepat, apemat, telefono, correo, fecnac),
      coach(coach), membresia(mem), rutina(rut) {}

/**
 * Muestra en consola toda la información del usuario: 
 * datos personales, entrenador, membresía y rutina.
 *
 * @param
 * @return Imprime los datos completos del usuario.
 */
void Usuario::mostrarInfo() {
    std::cout << "Nombre: " << nombre << " " << apepat << " " << apemat << std::endl;
    std::cout << "Telefono: " << telefono << ", Correo: " << correo << std::endl;
    std::cout << "Fecha de nacimiento: " << fecnac << std::endl;

    std::cout << "\nEntrenador:\n";
    if (coach)
        coach->mostrarInfo();
    else
        std::cout << "No tiene entrenador asignado.\n";

    std::cout << "\nMembresia:\n";
    if (membresia)
        membresia->mostrarInfo();
    else
        std::cout << "No tiene membresia asignada.\n";

    std::cout << "\nRutina:\n";
    if (rutina)
        rutina->mostrarEjercicios();
    else
        std::cout << "No tiene rutina asignada.\n";
}

/**
 * Asigna un entrenador al usuario.
 *
 * @param entrenador Puntero a un objeto Persona que representa al entrenador.
 * @return Asigna el puntero al atributo `coach`.
 */
void Usuario::setCoach(Persona* entrenador) {
    coach = entrenador;
}

/**
 * Asigna una membresía al usuario.
 *
 * @param mem Puntero al objeto Membresia.
 * @return Asigna el puntero al atributo `membresia`.
 */
void Usuario::setMembresia(Membresia* mem) {
    membresia = mem;
}

/**
 * Asigna una rutina al usuario.
 *
 * @param rut Puntero al objeto Rutina.
 * @return Asigna el puntero al atributo `rutina`.
 */
void Usuario::setRutina(Rutina* rut) {
    rutina = rut;
}

/**
 * Obtiene el entrenador asignado al usuario.
 *
 * @param
 * @return Puntero al objeto Persona que representa al entrenador.
 */
Persona* Usuario::getCoach() const {
    return coach;
}

/**
 * Obtiene la membresía asignada al usuario.
 *
 * @param
 * @return Puntero al objeto Membresia.
 */
Membresia* Usuario::getMembresia() const {
    return membresia;
}

/**
 * Obtiene la rutina asignada al usuario.
 *
 * @param
 * @return Puntero al objeto Rutina.
 */
Rutina* Usuario::getRutina() const {
    return rutina;
}
#endif