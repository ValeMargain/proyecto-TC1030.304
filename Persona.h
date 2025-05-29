#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

class Persona {
protected:
    std::string nombre;
    std::string apepat;
    std::string apemat;
    std::string telefono;
    std::string correo;
    std::string fecnac; 

public:
    // Constructor por defecto
    Persona();

    // Constructor con parámetros
    Persona(std::string nombre, std::string apepat, std::string apemat,
            std::string telefono, std::string correo, std::string fecnac);

    virtual void mostrarInfo();
};

// Constructor por defecto
Persona::Persona()
    : nombre(""), apepat(""), apemat(""), telefono(""), correo(""), fecnac("") {}

// Constructor con parámetros
Persona::Persona(std::string nombre, std::string apepat, std::string apemat,
                std::string telefono, std::string correo, std::string fecnac)
    : nombre(nombre), apepat(apepat), apemat(apemat), telefono(telefono), correo(correo), fecnac(fecnac) {}


void Persona::mostrarInfo() {
    std::cout << "Nombre: " << nombre << " " << apepat << " " << apemat << std::endl;
    std::cout << "Teléfono: " << telefono << ", Correo: " << correo << std::endl;
    std::cout << "Fecha de nacimiento: " << fecnac << std::endl;
}

#endif
