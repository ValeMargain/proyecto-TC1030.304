#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Persona.h"
#include "Rutina.h"
#include "Membresia.h"
#include "Entrenador.h"

class Usuario : public Persona {
private:
    Rutina rutina;
    Entrenador coach;  
    Membresia membresia;
    bool tieneCoach;  

public:
    Usuario();
    Usuario(const std::string& nombre, const std::string& apepat, const std::string& apemat,
            const std::string& telefono, const std::string& correo, const std::string& fecnac);

    void asignarEntrenador(const Entrenador& entrenador);
    void asignarMembresia(const Membresia& nuevaMembresia);
    void agregarRutina(const Rutina& nuevaRutina);

    Rutina getRutina();
    void setRutina(const Rutina& nuevaRutina);

    Entrenador getCoach();
    void setCoach(const Entrenador& nuevoCoach);

    Membresia getMembresia();
    void setMembresia(const Membresia& nuevaMembresia);

    void mostrarInfo() override;
};


Usuario::Usuario()
    : Persona(), rutina(), coach(), membresia(), tieneCoach(false) {}

Usuario::Usuario(const std::string& nombre, const std::string& apepat, const std::string& apemat,
                 const std::string& telefono, const std::string& correo, const std::string& fecnac)
    : Persona(nombre, apepat, apemat, telefono, correo, fecnac),
      rutina(), coach(), membresia(), tieneCoach(false) {}

void Usuario::asignarEntrenador(const Entrenador& entrenador) {
    coach = entrenador;
    tieneCoach = true;
}

void Usuario::asignarMembresia(const Membresia& nuevaMembresia) {
    membresia = nuevaMembresia;
}

void Usuario::agregarRutina(const Rutina& nuevaRutina) {
    rutina = nuevaRutina;
}

Rutina Usuario::getRutina() {
    return rutina;
}

void Usuario::setRutina(const Rutina& nuevaRutina) {
    rutina = nuevaRutina;
}

Entrenador Usuario::getCoach() {
    return coach;
}

void Usuario::setCoach(const Entrenador& nuevoCoach) {
    coach = nuevoCoach;
    tieneCoach = true;
}

Membresia Usuario::getMembresia() {
    return membresia;
}

void Usuario::setMembresia(const Membresia& nuevaMembresia) {
    membresia = nuevaMembresia;
}

void Usuario::mostrarInfo() {
    Persona::mostrarInfo();
    std::cout << "--- Rutina ---" << std::endl;
    rutina.mostrarEjercicios();
    std::cout << "--- Membresía ---" << std::endl;
    membresia.mostrarInfo();
    if (tieneCoach) {
        std::cout << "--- Entrenador asignado ---" << std::endl;
        coach.mostrarInfo();
    } else {
        std::cout << "Sin entrenador asignado." << std::endl;
    }
}

#endif
