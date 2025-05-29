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
   
    Usuario(string nombre, string apepat, string apemat, string telefono, string correo, string fecnac,
            Persona* coach, Membresia* membresia, Rutina* rutina)
        : Persona(nombre, apepat, apemat, telefono, correo, fecnac),
          coach(coach), membresia(membresia), rutina(rutina) {}


    void mostrarInfo()  {
        Persona::mostrarInfo();

        cout << "\nEntrenador:\n";
        if (coach)
            coach->mostrarInfo();
        else
            cout << "No tiene entrenador asignado.\n";

        cout << "\nMembresia:\n";
        if (membresia)
            membresia->mostrarInfo();
        else
            cout << "No tiene membresía asignada.\n";

        cout << "\nRutina:\n";
        if (rutina)
            rutina->mostrarEjercicios();
        else
            cout << "No tiene rutina asignada.\n";
    }

    // Getters y setters si se requieren
    void setCoach(Persona* entrenador) {
        coach = entrenador;
    }

    void setMembresia(Membresia* mem) {
        membresia = mem;
    }

    void setRutina(Rutina* rut) {
        rutina = rut;
    }

    Persona* getCoach() {
        return coach;
    }

    Membresia* getMembresia() {
        return membresia;
    }

    Rutina* getRutina() {
        return rutina;
    }
};

#endif
