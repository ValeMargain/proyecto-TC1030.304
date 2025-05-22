#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
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
    Persona(const std::string& nombre, const std::string& apepat, const std::string& apemat,
            const std::string& telefono, const std::string& correo, const std::string& fecnac);

    // Getters
    std::string get_nombre() const;
    std::string get_apepat() const;
    std::string get_apemat() const;
    std::string get_telefono() const;
    std::string get_correo() const;
    std::string get_fecnac() const;

    // Setters
    void set_nombre(const std::string& nombre);
    void set_apepat(const std::string& apepat);
    void set_apemat(const std::string& apemat);
    void set_telefono(const std::string& telefono);
    void set_correo(const std::string& correo);
    void set_fecnac(const std::string& fecnac);

    virtual void mostrarInfo();
};

// Constructor por defecto
Persona::Persona()
    : nombre(""), apepat(""), apemat(""), telefono(""), correo(""), fecnac("") {}

// Constructor con parámetros
Persona::Persona(const std::string& nombre, const std::string& apepat, const std::string& apemat,
                 const std::string& telefono, const std::string& correo, const std::string& fecnac)
    : nombre(nombre), apepat(apepat), apemat(apemat), telefono(telefono), correo(correo), fecnac(fecnac) {}

// Getters
std::string Persona::get_nombre() const {
    return nombre;
}

std::string Persona::get_apepat() const {
    return apepat;
}

std::string Persona::get_apemat() const {
    return apemat;
}

std::string Persona::get_telefono() const {
    return telefono;
}

std::string Persona::get_correo() const {
    return correo;
}

std::string Persona::get_fecnac() const {
    return fecnac;
}

// Setters
void Persona::set_nombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Persona::set_apepat(const std::string& apepat) {
    this->apepat = apepat;
}

void Persona::set_apemat(const std::string& apemat) {
    this->apemat = apemat;
}

void Persona::set_telefono(const std::string& telefono) {
    this->telefono = telefono;
}

void Persona::set_correo(const std::string& correo) {
    this->correo = correo;
}

void Persona::set_fecnac(const std::string& fecnac) {
    this->fecnac = fecnac;
}

void Persona::mostrarInfo() {
    std::cout << "Nombre: " << nombre << " " << apepat << " " << apemat << std::endl;
    std::cout << "Teléfono: " << telefono << ", Correo: " << correo << std::endl;
    std::cout << "Fecha de nacimiento: " << fecnac << std::endl;
}

#endif
