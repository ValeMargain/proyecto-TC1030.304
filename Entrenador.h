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

    std::string getEspecialidad() const;
    void setEspecialidad(std::string esp);

    void asignarRutina(Rutina rutina);
    Rutina getRutina() const;

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

std::string Entrenador::getEspecialidad() const{
    return especialidad;
}

void Entrenador::setEspecialidad(std::string esp) {
    especialidad = esp;
}

void Entrenador::asignarRutina(Rutina rutina) {
    rutinaAsignada = rutina;
}

Rutina Entrenador::getRutina() const{
    return rutinaAsignada;
}

void Entrenador::mostrarInfo() {
    std::cout << "Nombre: " << nombre << " " << apepat << " " << apemat << std::endl;
    std::cout << "Telefono: " << telefono << ", Correo: " << correo << std::endl;
    std::cout << "Fecha de nacimiento: " << fecnac << std::endl;
    std::cout << "Especialidad: " << especialidad << std::endl;
}

#endif
