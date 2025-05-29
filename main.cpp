#include <iostream>
#include <string>
#include "Entrenador.h"
#include "Membresia.h"
#include "Rutina.h"
#include "Usuario.h"

using namespace std;

int main() {
    // Crear entrenador
    cout << "=== Crear Entrenador ===" << endl;
    string nombre, apepat, apemat, telefono, correo, fecnac, especialidad;
    cout << "Nombre: "; getline(cin, nombre);
    cout << "Apellido paterno: "; getline(cin, apepat);
    cout << "Apellido materno: "; getline(cin, apemat);
    cout << "Telefono: "; getline(cin, telefono);
    cout << "Correo: "; getline(cin, correo);
    cout << "Fecha de nacimiento (YYYY-MM-DD): "; getline(cin, fecnac);
    cout << "Especialidad: "; getline(cin, especialidad);

    Persona* entrenador = new Entrenador(nombre, apepat, apemat, telefono, correo, fecnac, especialidad);

    // Crear membresía
    cout << "\n=== Crear Membresía ===" << endl;
    string nomMembresia;
    int duracion;
    double precio;
    cout << "Nombre: "; getline(cin, nomMembresia);
    cout << "Duración (días): "; cin >> duracion;
    cout << "Precio: "; cin >> precio;
    cin.ignore();

    Membresia* membresia = new Membresia(nomMembresia, duracion, precio);

    // Renovar membresía
    char op;
    cout << "¿Deseas renovar con días extra? (s/n): ";
    cin >> op; cin.ignore();
    if (op == 's' || op == 'S') {
        int extra;
        cout << "¿Cuántos días extra? "; cin >> extra; cin.ignore();
        membresia->renovar(extra);
    } else {
        membresia->renovar();
    }

    // Crear rutina
    cout << "\n=== Crear Rutina ===" << endl;
    string nombreRutina;
    cout << "Nombre de la rutina: "; getline(cin, nombreRutina);

    Rutina* rutina = new Rutina(nombreRutina);
    int n;
    cout << "¿Cuántos ejercicios quieres agregar? "; cin >> n; cin.ignore();
    for (int i = 0; i < n; ++i) {
        string ejercicio;
        cout << "Ejercicio " << i + 1 << ": ";
        getline(cin, ejercicio);
        rutina->agregarEjercicio(ejercicio);
    }

    // Crear usuario
    cout << "\n=== Crear Usuario ===" << endl;
    string nomUsu, apeUsuPat, apeUsuMat, telUsu, corrUsu, fecUsu;
    cout << "Nombre: "; getline(cin, nomUsu);
    cout << "Apellido paterno: "; getline(cin, apeUsuPat);
    cout << "Apellido materno: "; getline(cin, apeUsuMat);
    cout << "Telefono: "; getline(cin, telUsu);
    cout << "Correo: "; getline(cin, corrUsu);
    cout << "Fecha de nacimiento (YYYY-MM-DD): "; getline(cin, fecUsu);

    Persona* usuario = new Usuario(nomUsu, apeUsuPat, apeUsuMat, telUsu, corrUsu, fecUsu, entrenador, membresia, rutina);

    // Mostrar info
    cout << "\n=== INFORMACIÓN COMPLETA DEL USUARIO ===" << endl;
    usuario->mostrarInfo();

    return 0;
}