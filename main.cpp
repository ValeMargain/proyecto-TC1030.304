
#include "Menu.h"
int main() {
    Menu menu;
    int opcion;

    do {
        menu.mostrarMenuPrincipal();
        opcion = menu.pedirOpcion();
        menu.ejecutarOpcion(opcion);
    } while (opcion != 0);

    return 0;
}
