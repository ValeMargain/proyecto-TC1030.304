/**
 * Proyecto 
 * Danna Valeria Rosales Margain
 * A01669036
 * 11/06/2025
 * Clase abstracta que representa a una persona con atributos generales como nombre,
 * apellidos, teléfono, correo y fecha de nacimiento.
 *
 * Sirve como clase base para otras clases como Usuario o Entrenador.
 */
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
#include <string>
#include <cctype>

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

    // Setters
    void setNombre(std::string nombre);
    void setApePat(std::string apepat);
    void setApeMat(std::string apemat);
    void setTelefono(std::string telefono);
    void setCorreo(std::string correo);
    void setFecNac(std::string fecnac);

    // Getters
    std::string getNombre() const;
    std::string getApePat() const;
    std::string getApeMat() const;
    std::string getTelefono() const;
    std::string getCorreo() const;
    std::string getFecNac() const;

/**
 * Método virtual puro que se debe implementar en las clases derivadas para mostrar la información personal.
 *
 * @param
 * @return Método abstracto, no retorna nada.
 */
    virtual void mostrarInfo() = 0;

};

// Constructor por defecto
Persona::Persona()
    : nombre(""), apepat(""), apemat(""), telefono(""), correo(""), fecnac("") {}

// Constructor con parámetros
Persona::Persona(std::string nombre, std::string apepat, std::string apemat,
                std::string telefono, std::string correo, std::string fecnac)
    : nombre(nombre), apepat(apepat), apemat(apemat), telefono(telefono), correo(correo), fecnac(fecnac) {}

//Setters
void Persona::setNombre(std::string nombre) {
    if (nombre.empty()) {
        std::cerr << "Nombre inválido. No puede estar vacío.\n";
        return;
    }
    bool valido = true;
    for (size_t i = 0; i < nombre.size(); ++i) {
        char c = nombre[i];
        if (!isalpha(c) && c != ' ') {
            valido = false;
            break;
        }
    }
    if (valido) {
        this->nombre = nombre;
    } else {
        std::cerr << "Nombre inválido. Solo letras y espacios.\n";
    }
}

void Persona::setApePat(std::string apepat) {
    if (apepat.empty()) {
        std::cerr << "Apellido paterno inválido. No puede estar vacío.\n";
        return;
    }
    bool valido = true;
    for (size_t i = 0; i < apepat.size(); ++i) {
        char c = apepat[i];
        if (!isalpha(c) && c != ' ') {
            valido = false;
            break;
        }
    }
    if (valido) {
        this->apepat = apepat;
    } else {
        std::cerr << "Apellido paterno inválido. Solo letras y espacios.\n";
    }
}

void Persona::setApeMat(std::string apemat) {
    if (apemat.empty()) {
        std::cerr << "Apellido materno inválido. No puede estar vacío.\n";
        return;
    }
    bool valido = true;
    for (size_t i = 0; i < apemat.size(); ++i) {
        char c = apemat[i];
        if (!isalpha(c) && c != ' ') {
            valido = false;
            break;
        }
    }
    if (valido) {
        this->apemat = apemat;
    } else {
        std::cerr << "Apellido materno inválido. Solo letras y espacios.\n";
    }
}


void Persona::setTelefono(std::string telefono) {
    this->telefono = telefono;
}
void Persona::setCorreo(std::string correo) {
    this->correo = correo;
}
void Persona::setFecNac(std::string fecnac) {
    this->fecnac = fecnac;
}

// Getters
std::string Persona::getNombre() const {
    return nombre;
}
std::string Persona::getApePat() const {
    return apepat;
}
std::string Persona::getApeMat() const {
    return apemat;
}
std::string Persona::getTelefono() const {
    return telefono;
}
std::string Persona::getCorreo() const {
    return correo;
}
std::string Persona::getFecNac() const {
    return fecnac;
}



#endif
