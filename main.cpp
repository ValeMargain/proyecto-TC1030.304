#include <iostream>
#include <string>
#include "Entrenador.h"
#include "Membresia.h"
#include "Rutina.h"
#include "Usuario.h"

using namespace std;

int main() {
    
    cout << "Crear Entrenador:" << endl;
    string nombre, apepat, apemat, telefono, correo, fecnac, especialidad;

    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Apellido paterno: ";
    getline(cin, apepat);
    cout << "Apellido materno: ";
    getline(cin, apemat);
    cout << "Teléfono: ";
    getline(cin, telefono);
    cout << "Correo: ";
    getline(cin, correo);
    cout << "Fecha de nacimiento (YYYY-MM-DD): ";
    getline(cin, fecnac);
    cout << "Especialidad: ";
    getline(cin, especialidad);

    Entrenador entrenador(nombre, apepat, apemat, telefono, correo, fecnac, especialidad);


    cout << "\nCrear Membresía:" << endl;
    string nomMembresia;
    int duracion;
    double precio;

    cout << "Nombre: ";
    getline(cin, nomMembresia);
    cout << "Duración (días): ";
    cin >> duracion;
    cout << "Precio: ";
    cin >> precio;
    cin.ignore(); 

    Membresia membresia(nomMembresia, duracion, precio);

   
    cout << "\n¿Deseas renovar la membresía con días extra? (s/n): ";
    char opcionRenovar;
    cin >> opcionRenovar;
    cin.ignore();

    if (opcionRenovar == 's' || opcionRenovar == 'S') {
        int extra;
        cout << "¿Cuántos días adicionales quieres agregar? ";
        cin >> extra;
        cin.ignore();
        membresia.renovar(extra);  // se usa la sobrecarga
        cout << "¡Membresía renovada con " << extra << " días extra!\n";
    } else {
        membresia.renovar();  // se usa la versión básica
        cout << "¡Membresía renovada desde hoy!\n";
    }

    
    cout << "\nCrear Rutina:" << endl;
    string nombreRutina;
    cout << "Nombre de la rutina: ";
    getline(cin, nombreRutina);

    Rutina rutina(nombreRutina);

    int nEjercicios;
    cout << "¿Cuántos ejercicios quieres agregar? ";
    cin >> nEjercicios;
    cin.ignore();

    for (int i = 0; i < nEjercicios; ++i) {
        string ejercicio;
        cout << "Ejercicio " << i + 1 << ": ";
        getline(cin, ejercicio);
        rutina.agregarEjercicio(ejercicio);
    }

    cout << "\nCrear Usuario:" << endl;
    string nomUsu, apeUsuPat, apeUsuMat, telUsu, corrUsu, fecUsu;

    cout << "Nombre: ";
    getline(cin, nomUsu);
    cout << "Apellido paterno: ";
    getline(cin, apeUsuPat);
    cout << "Apellido materno: ";
    getline(cin, apeUsuMat);
    cout << "Teléfono: ";
    getline(cin, telUsu);
    cout << "Correo: ";
    getline(cin, corrUsu);
    cout << "Fecha de nacimiento (YYYY-MM-DD): ";
    getline(cin, fecUsu);

    Usuario usuario(nomUsu, apeUsuPat, apeUsuMat, telUsu, corrUsu, fecUsu);

    
    usuario.setRutina(rutina);
    usuario.setMembresia(membresia);
    usuario.setCoach(entrenador);


    cout << "\nMostrando información del usuario:" << endl;
    usuario.mostrarInfo();

    cout << "\nMostrando información del entrenador directamente:" << endl;
    entrenador.mostrarInfo();

    return 0;
}
