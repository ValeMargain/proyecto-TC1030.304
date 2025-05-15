# proyecto-TC1030.304
Proyecto desarrollado en C++
GymManager es un proyecto diseñado para demostrar la implementación de un sistema de gestión de gimnasio utilizando programación orientada a objetos (POO) en C++. Este sistema permite simular el funcionamiento básico de un gimnasio, donde los usuarios pueden recibir entrenamientos personalizados, adquirir una membresía y recibir acompañamiento de un entrenador .
Para ello, se han definido cuatro clases principales y una clase base que representa a toda persona involucrada en el sistema.

* Persona: Clase abstracta que almacena atributos como nombre, apellidos, edad, teléfono, correo y fecha de nacimiento. Es heredada por las clases Usuario y Entrenador. 
* Usuario: Hereda de Persona. Representa a un cliente del gimnasio. Puede tener asignado un entrenador, una membresía activa y una rutina personalizada. 
* Entrenador: Hereda de Persona. Se encarga de crear rutinas y asignarlas a los usuarios que entrena. También gestiona una lista de sus usuarios. 
* Membresía: Clase que contiene la información relacionada con el acceso del usuario al gimnasio: tipo de membresía, duración, precio y fecha de inicio. Incluye métodos para validar su vigencia y renovarla. 
* Rutina: Representa un conjunto de ejercicios personalizados asignados a un usuario. Contiene una lista de ejercicios que pueden ser modificados. 

Funcionalidad:
El programa permite realizar las siguientes acciones:
* Registrar un usuario, ingresando sus datos personales. 
* Registrar un entrenador, ingresando su especialidad y datos generales. 
* Crear y registrar una membresía, especificando su duración y precio. 
* Asignar un entrenador a un usuario. 
* Asignar o renovar una membresía para un usuario. 
* Crear y asignar rutinas con ejercicios personalizados. 
* Mostrar información detallada de usuarios, entrenadores, membresía y rutinas. 
* Calcular cuántos días le quedan a una membresía. 
* Validar si una membresía está activa. 
* Mostrar rutinas con todos los ejercicios correspondientes.
 Limitaciones: 
* No tiene almacenamiento persistente: Los datos de usuarios, entrenadores, rutinas y membresía solo existen mientras el programa está en ejecución. Al cerrarlo, toda la información se pierde. 
* Interfaz por consola: No cuenta con una interfaz gráfica. 
* Validación básica de datos: No hay validación avanzada de estructuras como el correo o  numero telefónico. 
* No hay control de acceso o autenticación: Cualquier persona puede ingresar datos o modificar la información del sistema. No hay login para usuarios ni entrenadores. 
* Asignación simple de rutinas y entrenadores: No se valida la disponibilidad o carga de trabajo de un entrenador al asignarlo a múltiples usuarios.
* No se permiten tener más de un entrenador y una membresía por usuario.  

Consideraciones El programa está diseñado para correr en cualquier sistema operativo que soporte C++ estándar. Tutorial para compilar el programa en Windows: TylerMSFT. (2023, 12 de octubre). Tutorial: Compilar un programa nativo de C++ en la línea de comandos. Microsoft aprende. https://learn.microsoft.com/es-es/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-170


