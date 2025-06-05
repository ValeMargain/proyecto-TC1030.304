#ifndef MEMBRESIA_H
#define MEMBRESIA_H

#include <string>
#include <iostream>
#include <ctime>  
using namespace std;

class Membresia {
private:
    string nombre;
    int duracionDias;
    double precio;
    time_t fechaInicio;  
public:
    
    Membresia();
    Membresia(string nom, int duracion, double precio);

  
    string getNombre();
    int getDuracion();
    double getPrecio();
    time_t getFechaInicio();

 
    void setNombre(string);
    void setDuracion(int);
    void setPrecio(double);
    void setFechaInicio(time_t);

  
    bool esValida();        
    void renovar();        
    void renovar(int diasExtra);
    int diasRestantes();      

    // Mostrar info
    void mostrarInfo();
};

Membresia::Membresia()
    : nombre(""), duracionDias(0), precio(0.0) {}


Membresia::Membresia(string nom, int duracion, double precio)
    : nombre(nom), duracionDias(duracion), precio(precio) {
    fechaInicio = time(nullptr);
}

// Getters
string Membresia::getNombre() { return nombre; }
int Membresia::getDuracion() { return duracionDias; }
double Membresia::getPrecio() { return precio; }
time_t Membresia::getFechaInicio() { return fechaInicio; }

// Setters
void Membresia::setNombre(string nom) { nombre = nom; }
void Membresia::setDuracion(int duracion) { duracionDias = duracion; }
void Membresia::setPrecio(double p) { precio = p; }
void Membresia::setFechaInicio(time_t fecha) { fechaInicio = fecha; }


bool Membresia::esValida() {
    time_t ahora = time(nullptr);
    double segundosPasados = difftime(ahora, fechaInicio);
    int diasPasados = segundosPasados / (60 * 60 * 24);
    return diasPasados < duracionDias;
}


void Membresia::renovar() {
    fechaInicio = time(nullptr);
}

void Membresia::renovar(int diasExtra) {
    fechaInicio = time(nullptr);
    duracionDias += diasExtra;
}


int Membresia::diasRestantes() {
    time_t ahora = time(nullptr);
    double segundosPasados = difftime(ahora, fechaInicio);
    int diasPasados = segundosPasados / (60 * 60 * 24);
    int restantes = duracionDias - diasPasados;
    return (restantes > 0) ? restantes : 0;
}


void Membresia::mostrarInfo() {
    cout << "Membresía: " << nombre << ", duración: " << duracionDias
         << " días, precio: $" << precio << endl;
    cout << "Días restantes: " << diasRestantes() << endl;
    cout << (esValida() ? "La membresía está activa." : "La membresía ha expirado.") << endl;
}
#endif
