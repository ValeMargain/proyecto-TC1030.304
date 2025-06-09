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


Usuario::Usuario() : Persona("", "", "", "", "", ""), coach(nullptr), membresia(nullptr), rutina(nullptr) {}

Usuario::Usuario(std::string nombre, std::string apepat, std::string apemat,
                 std::string telefono, std::string correo, std::string fecnac,
                 Persona* coach, Membresia* mem, Rutina* rut)
    : Persona(nombre, apepat, apemat, telefono, correo, fecnac),
      coach(coach), membresia(mem), rutina(rut) {}

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

void Usuario::setCoach(Persona* entrenador) {
    coach = entrenador;
}

void Usuario::setMembresia(Membresia* mem) {
    membresia = mem;
}

void Usuario::setRutina(Rutina* rut) {
    rutina = rut;
}

Persona* Usuario::getCoach() const {
    return coach;
}

Membresia* Usuario::getMembresia() const {
    return membresia;
}

Rutina* Usuario::getRutina() const {
    return rutina;
}
#endif