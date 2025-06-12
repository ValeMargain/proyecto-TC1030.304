/**
 * Danna Valeria Rosales Margain
 * A01669036
 * 11/06/2025
 * Clase que representa una membresía de gimnasio.
 * Contiene información como nombre, duración en días, 
 * precio y fecha de inicio.
 * Permite verificar si la membresía está activa, 
 * renovarla y calcular los días restantes.
 */
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

/**
 * Verifica si la membresía aún es válida según la fecha actual y la duración.
 *
 * @param
 * @return true si aún no ha expirado, false si ya expiró.
 */
bool Membresia::esValida() {
    time_t ahora = time(nullptr);
    double segundosPasados = difftime(ahora, fechaInicio);
    int diasPasados = segundosPasados / (60 * 60 * 24);
    return diasPasados < duracionDias;
}

/**
 * Renueva la membresía reiniciando la fecha de inicio al día actual.
 *
 * @param
 * @return Actualiza `fechaInicio` con la fecha actual.
 */
void Membresia::renovar() {
    fechaInicio = time(nullptr);
}

/**
 * Renueva la membresía al día actual y
 *  extiende la duración en días adicionales.
 *
 * @param diasExtra Número de días adicionales a agregar.
 * @return Actualiza `fechaInicio` y extiende la duración.
 */
void Membresia::renovar(int diasExtra) {
    fechaInicio = time(nullptr);
    duracionDias += diasExtra;
}

/**
 * Calcula los días restantes antes de que expire la membresía.
 *
 * @param
 * @return int con la cantidad de días restantes. 
 * Si ya expiró, devuelve 0.
 */
int Membresia::diasRestantes() {
    time_t ahora = time(nullptr);
    double segundosPasados = difftime(ahora, fechaInicio);
    int diasPasados = segundosPasados / (60 * 60 * 24);
    int restantes = duracionDias - diasPasados;
    return (restantes > 0) ? restantes : 0;
}

/**
 * Muestra en consola la información general de la membresía, 
 * incluyendo días restantes y estado.
 *
 * @param
 * @return Imprime datos de la membresía y si está activa o expirada.
 */
void Membresia::mostrarInfo() {
    cout << "Membresia: " << nombre << ", duracion: " << duracionDias
         << " dias, precio: $" << precio << endl;
    cout << "Dias restantes: " << diasRestantes() << endl;
    cout << (esValida() ? "La membresia esta activa." : 
    "La membresia ha expirado.") << endl;
}
#endif
