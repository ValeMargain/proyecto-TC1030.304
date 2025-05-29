#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <string>
#include "Persona.h"
#include "Rutina.h"

class Entrenador : public Persona {
private:
    std::string especialidad;
    Rutina rutinaAsignada;

public:
    Entrenador();
    Entrenador(std::string nombre, std::string apepat, std::string apemat,
               std::string telefono, std::string correo, std::string fecnac,
               std::string especialidad);

    std::string getEspecialidad();
    void setEspecialidad(std::string esp);

    void asignarRutina(Rutina rutina);
    Rutina getRutina();

    void mostrarInfo();
};

// Implementación

Entrenador::Entrenador()
    : Persona(), especialidad(""), rutinaAsignada() {}

Entrenador::Entrenador(std::string nombre, std::string apepat, std::string apemat,
                       std::string telefono, std::string correo, std::string fecnac,
                       std::string especialidad)
    : Persona(nombre, apepat, apemat, telefono, correo, fecnac),
      especialidad(especialidad), rutinaAsignada() {}

std::string Entrenador::getEspecialidad() {
    return especialidad;
}

void Entrenador::setEspecialidad(std::string esp) {
    especialidad = esp;
}

void Entrenador::asignarRutina(Rutina rutina) {
    rutinaAsignada = rutina;
}

Rutina Entrenador::getRutina() {
    return rutinaAsignada;
}

void Entrenador::mostrarInfo() {
    Persona::mostrarInfo();
    std::cout << "Especialidad: " << especialidad << std::endl;
}

#endif
