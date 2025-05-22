#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <string>
#include "Persona.h"
#include "Rutina.h"  // Incluimos Rutina para poder usarla

class Entrenador : public Persona {
private:
    std::string especialidad;
    Rutina rutinaAsignada;

public:

    Entrenador();
    Entrenador(const std::string& nombre,
               const std::string& apepat,
               const std::string& apemat,
               const std::string& telefono,
               const std::string& correo,
               const std::string& fecnac,
               const std::string& especialidad);

    std::string getEspecialidad() const;
    void setEspecialidad(const std::string& esp);


    void asignarRutina(const Rutina& rutina);
    Rutina getRutina() const;

    void mostrarInfo() override {
    Persona::mostrarInfo();
    std::cout << "Especialidad: " << especialidad << std::endl;
}

};


Entrenador::Entrenador()
    : Persona(), especialidad(""), rutinaAsignada() {}


Entrenador::Entrenador(const std::string& nombre,
                       const std::string& apepat,
                       const std::string& apemat,
                       const std::string& telefono,
                       const std::string& correo,
                       const std::string& fecnac,
                       const std::string& especialidad)
    : Persona(nombre, apepat, apemat, telefono, correo, fecnac),
      especialidad(especialidad), rutinaAsignada() {}

// Getter para especialidad
std::string Entrenador::getEspecialidad() const {
    return especialidad;
}

// Setter para especialidad
void Entrenador::setEspecialidad(const std::string& esp) {
    especialidad = esp;
}

// Asignar rutina
void Entrenador::asignarRutina(const Rutina& rutina) {
    rutinaAsignada = rutina;
}

// Obtener rutina asignada
Rutina Entrenador::getRutina() const {
    return rutinaAsignada;
}



#endif
