#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "Entrenador.h"
#include "Membresia.h"
#include "Rutina.h"
#include "Usuario.h"

using namespace std;

class Menu {
private:
    static const int MAX = 10;

    Persona* entrenadores[MAX];
    int totalEntrenadores;

    Membresia* membresias[MAX];
    int totalMembresias;

    Rutina* rutinas[MAX];
    int totalRutinas;

    Persona* usuarios[100];
    int totalUsuarios;

    void mostrarEntrenadores();
    void mostrarMembresias();
    void mostrarRutinas();
    void mostrarUsuarios();

    void crearEntrenador();
    void crearMembresia();
    void crearRutina();
    void renovarMembresia();
    void crearUsuario();
    void eliminarEjercicioRutina();

public:
    Menu();

    void mostrarMenuPrincipal();
    int pedirOpcion();
    void ejecutarOpcion(int opcion);
};


Menu::Menu() : totalEntrenadores(0), totalMembresias(0), totalRutinas(0), totalUsuarios(0) {
    // Crear entrenador por defecto
    entrenadores[totalEntrenadores++] = new Entrenador(
        "Carlos", "Lopez", "Ramirez", "5551234567",
        "carlos.lopez@gym.com", "1980-01-01", "Fuerza"
    );

    // Crear membresía por defecto
    membresias[totalMembresias++] = new Membresia(
        "Básica", 30, 499.99
    );

    // Crear rutina por defecto
    Rutina* rutina = new Rutina("Rutina Inicial");
    rutina->agregarEjercicio("Flexiones");
    rutina->agregarEjercicio("Sentadillas");
    rutina->agregarEjercicio("Abdominales");
    rutinas[totalRutinas++] = rutina;
}


void Menu::mostrarEntrenadores() {
    if (totalEntrenadores == 0) {
        cout << "No hay entrenadores registrados.\n";
        return;
    }
    cout << "--- Entrenadores ---\n";
    for (int i = 0; i < totalEntrenadores; ++i) {
        cout << i << ": ";
        entrenadores[i]->mostrarInfo();
        cout << endl;
    }
}

void Menu::mostrarMembresias() {
    if (totalMembresias == 0) {
        cout << "No hay membresías registradas.\n";
        return;
    }
    cout << "--- Membresías ---\n";
    for (int i = 0; i < totalMembresias; ++i) {
        cout << i << ": ";
        membresias[i]->mostrarInfo();
    }
}

void Menu::mostrarRutinas() {
    if (totalRutinas == 0) {
        cout << "No hay rutinas registradas.\n";
        return;
    }
    cout << "--- Rutinas ---\n";
    for (int i = 0; i < totalRutinas; ++i) {
        cout << i << ": " << rutinas[i]->getNombre() << endl;
    }
}

void Menu::mostrarUsuarios() {
    if (totalUsuarios == 0) {
        cout << "No hay usuarios registrados.\n";
        return;
    }
    cout << "--- Usuarios ---\n";
    for (int i = 0; i < totalUsuarios; ++i) {
        cout << "\nUsuario #" << i + 1 << ":\n";
        usuarios[i]->mostrarInfo();
        cout << "------------------\n";
    }
}

void Menu::crearEntrenador() {
    if (totalEntrenadores >= MAX) {
        cout << "No se pueden agregar más entrenadores.\n";
        return;
    }

    string nombre, apepat, apemat, telefono, correo, fecnac, especialidad;
    cout << "Nombre: "; getline(cin, nombre);
    cout << "Apellido paterno: "; getline(cin, apepat);
    cout << "Apellido materno: "; getline(cin, apemat);
    cout << "Teléfono: "; getline(cin, telefono);
    cout << "Correo: "; getline(cin, correo);
    cout << "Fecha de nacimiento (YYYY-MM-DD): "; getline(cin, fecnac);
    cout << "Especialidad: "; getline(cin, especialidad);

    entrenadores[totalEntrenadores++] = new Entrenador(nombre, apepat, apemat,
        telefono, correo, fecnac, especialidad);

    cout << "Entrenador creado exitosamente.\n";
}

void Menu::crearMembresia() {
    if (totalMembresias >= MAX) {
        cout << "No se pueden agregar más membresías.\n";
        return;
    }

    string nombre;
    int duracion;
    double precio;

    cout << "Nombre: "; getline(cin, nombre);
    cout << "Duración (días): "; cin >> duracion;
    cout << "Precio: "; cin >> precio;
    cin.ignore();

    membresias[totalMembresias++] = new Membresia(nombre, duracion, precio);
    cout << "Membresía creada exitosamente.\n";
}

void Menu::crearRutina() {
    if (totalRutinas >= MAX) {
        cout << "No se pueden agregar más rutinas.\n";
        return;
    }

    string nombreRutina;
    cout << "Nombre de la rutina: "; getline(cin, nombreRutina);

    Rutina* rutina = new Rutina(nombreRutina);

    int n;
    cout << "¿Cuántos ejercicios deseas agregar? "; cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string ejercicio;
        cout << "Ejercicio " << i + 1 << ": ";
        getline(cin, ejercicio);
        rutina->agregarEjercicio(ejercicio);
    }

    rutinas[totalRutinas++] = rutina;
    cout << "Rutina creada exitosamente.\n";
}

void Menu::renovarMembresia() {
    if (totalMembresias == 0) {
        cout << "No hay membresías para renovar.\n";
        return;
    }

    mostrarMembresias();

    int idx;
    do {
        cout << "Elige el índice de la membresía (0 a " << totalMembresias - 1 << "): ";
        cin >> idx;
        cin.ignore();
        if (idx < 0 || idx >= totalMembresias) {
            cout << "Índice inválido. Intenta de nuevo.\n";
        }
    } while (idx < 0 || idx >= totalMembresias);

    char op;
    cout << "¿Deseas renovar con días extra? (s/n): ";
    cin >> op;
    cin.ignore();

    if (op == 's' || op == 'S') {
        int extra;
        cout << "¿Cuántos días extra? ";
        cin >> extra;
        cin.ignore();
        membresias[idx]->renovar(extra);
    } else {
        membresias[idx]->renovar();
    }
    cout << "Membresía renovada.\n";
}

void Menu::crearUsuario() {
    if (totalEntrenadores == 0 || totalMembresias == 0 || totalRutinas == 0) {
        cout << "Debes tener al menos un entrenador, una membresía y una rutina antes de crear un usuario.\n";
        return;
    }

    if (totalUsuarios >= 100) {
        cout << "No se pueden crear más usuarios.\n";
        return;
    }

    string nomUsu, apeUsuPat, apeUsuMat, telUsu, corrUsu, fecUsu;
    int idxEntrenador, idxMembresia, idxRutina;

    cout << "\n=== Crear Usuario ===\n";
    cout << "Nombre: "; getline(cin, nomUsu);
    cout << "Apellido paterno: "; getline(cin, apeUsuPat);
    cout << "Apellido materno: "; getline(cin, apeUsuMat);
    cout << "Teléfono: "; getline(cin, telUsu);
    cout << "Correo: "; getline(cin, corrUsu);
    cout << "Fecha de nacimiento (YYYY-MM-DD): "; getline(cin, fecUsu);

    mostrarEntrenadores();
    do {
        cout << "Selecciona el índice del entrenador: ";
        cin >> idxEntrenador;
        cin.ignore();
        if (idxEntrenador < 0 || idxEntrenador >= totalEntrenadores) {
            cout << "Índice inválido. Intenta de nuevo.\n";
        }
    } while (idxEntrenador < 0 || idxEntrenador >= totalEntrenadores);

    mostrarMembresias();
    do {
        cout << "Selecciona el índice de la membresía: ";
        cin >> idxMembresia;
        cin.ignore();
        if (idxMembresia < 0 || idxMembresia >= totalMembresias) {
            cout << "Índice inválido. Intenta de nuevo.\n";
        }
    } while (idxMembresia < 0 || idxMembresia >= totalMembresias);

    mostrarRutinas();
    do {
        cout << "Selecciona el índice de la rutina: ";
        cin >> idxRutina;
        cin.ignore();
        if (idxRutina < 0 || idxRutina >= totalRutinas) {
            cout << "Índice inválido. Intenta de nuevo.\n";
        }
    } while (idxRutina < 0 || idxRutina >= totalRutinas);

    Usuario* usuario = new Usuario(
        nomUsu, apeUsuPat, apeUsuMat, telUsu, corrUsu, fecUsu,
        entrenadores[idxEntrenador],
        membresias[idxMembresia],
        rutinas[idxRutina]
    );

    usuarios[totalUsuarios++] = usuario;
    cout << "Usuario creado exitosamente.\n";
}

void Menu::eliminarEjercicioRutina() {
    if (totalRutinas == 0) {
        cout << "No hay rutinas disponibles.\n";
        return;
    }

    mostrarRutinas();

    int idx;
    cout << "Selecciona el índice de la rutina: ";
    cin >> idx;
    cin.ignore();

    if (idx < 0 || idx >= totalRutinas) {
        cout << "Índice inválido.\n";
        return;
    }

    string ejercicio;
    cout << "Nombre del ejercicio a eliminar: ";
    getline(cin, ejercicio);

    rutinas[idx]->eliminarEjercicio(ejercicio);
    cout << "Ejercicio eliminado si existía.\n";
}

void Menu::mostrarMenuPrincipal() {
    cout << "\n=== MENÚ PRINCIPAL ===\n";
    cout << "1. Crear entrenador\n";
    cout << "2. Crear membresia\n";
    cout << "3. Crear rutina\n";
    cout << "4. Renovar membresia\n";
    cout << "5. Crear usuario\n";
    cout << "6. Mostrar usuarios\n";
    cout << "7. Eliminar ejercicio de rutina\n";
    cout << "8. Mostrar entrenadores\n"; // <- NUEVA LÍNEA
    cout << "0. Salir\n";
    cout << "Elige una opcion: ";
}


int Menu::pedirOpcion() {
    int opcion;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

void Menu::ejecutarOpcion(int opcion) {
    switch (opcion) {
    case 1:
        crearEntrenador();
        break;
    case 2:
        crearMembresia();
        break;
    case 3:
        crearRutina();
        break;
    case 4:
        renovarMembresia();
        break;
    case 5:
        crearUsuario();
        break;
    case 6:
        mostrarUsuarios();
        break;
    case 7:
        eliminarEjercicioRutina();
        break;
    case 8:
        mostrarEntrenadores(); // <- NUEVO CASE
        break;
    case 0:
        cout << "Saliendo del programa. ¡Hasta luego!\n";
        break;
    default:
        cout << "Opción inválida. Intenta de nuevo.\n";
        break;
    }
}

#endif
