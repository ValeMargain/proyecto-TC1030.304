/**
 * Danna Valeria Rosales Margain
 * A01669036
 * 11/06/2025
 * Clase que representa a un entrenador del gimnasio.
 * Hereda de Persona e incluye atributos adicionales 
 * como la especialidad
 * y una rutina asignada.
 */
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
/**
     * Constructor por defecto que inicializa los atributos vacíos.
     *
     * @param
     * @return Constructor que no retorna nada.
     */
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

/**
 * Asigna una rutina al entrenador.
 *
 * @param rutina Objeto de tipo Rutina a asignar.
 * @return Asigna el objeto al atributo `rutinaAsignada`.
 */
void Entrenador::asignarRutina(Rutina rutina) {
    rutinaAsignada = rutina;
}

Rutina Entrenador::getRutina() const{
    return rutinaAsignada;
}

/**
 * Muestra en consola los datos personales del entrenador y su especialidad.
 *
 * @param
 * @return Imprime los datos del entrenador.
 */
void Entrenador::mostrarInfo() {
    std::cout << "Nombre: " << nombre << " " << apepat << " " << apemat << std::endl;
    std::cout << "Telefono: " << telefono << ", Correo: " << correo << std::endl;
    std::cout << "Fecha de nacimiento: " << fecnac << std::endl;
    std::cout << "Especialidad: " << especialidad << std::endl;
}

#endif
