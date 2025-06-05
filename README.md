# proyecto-TC1030.304
Proyecto desarrollado en C++
GymManager es un proyecto diseñado para demostrar la implementación de un sistema de gestión de gimnasio utilizando programación orientada a objetos (POO) en C++. Este sistema permite simular el funcionamiento básico de un gimnasio, donde los usuarios pueden recibir entrenamientos personalizados, adquirir una membresía y recibir acompañamiento de un entrenador .
Para ello, se han definido cuatro clases principales y una clase base que representa a toda persona involucrada en el sistema.

* Persona (abstracta): Es la clase base que tiene atributos comunes, como nombre, apellidos, teléfono, correo y fecha de nacimiento.No se crean objetos directamente de Persona, sino que se hereda para crear a Entrenador y Usuario. 
* Entrenador: Hereda de Persona y añade la especialidad. Puede ser asignado a usuarios, lo cual ayuda a personalizar los entrenamientos. 
* Usuario: También hereda de Persona y tiene su propia membresía, rutina y entrenador asignado. Es quien en realidad usa el gimnasio. 
* Membresía: Incluye nombre, duración (días), precio y fecha de inicio. Tiene la posibilidad de renovarse, ya sea con o sin días adicionales, para que los usuarios puedan seguir disfrutando del gimnasio. 
* Rutina: Es una lista personalizada de ejercicios. Se puede modificar en cualquier momento, agregando o eliminando ejercicios para adaptarse a las necesidades del usuario. 
* Menu: Es la clase que se encarga de toda la interacción con el programa. Muestra las opciones, recibe la entrada del usuario y ejecuta las acciones correspondientes. Además, gestiona listas de entrenadores, membresías, rutinas y usuarios, con límites específicos para mantener la organización (máximo 10 entrenadores, 10 membresías, 10 rutinas y 100 usuarios). 

Funcionalidades del sistema:
* Crear y registrar un entrenador: Permite ingresar los datos personales y la especialidad de un entrenador para registrarlo en el sistema. Estos entrenadores luego pueden ser asignados a los usuarios. 
* Crear una membresía: Registra una nueva membresía especificando su nombre, duración en días y precio. Cada usuario debe tener una membresía asociada. 
* Crear y personalizar una rutina con ejercicios: Permite crear una rutina nombrada e ingresar una lista personalizada de ejercicios. Cada rutina puede ser asignada a un usuario.
*  
* Renovar una membresía, ya sea con días adicionales o sin ellos: Opción para extender la duración de una membresía. Puede renovarse tal cual o agregando días adicionales, según lo decida el usuario. 
* Crear un usuario: Registra un nuevo usuario con sus datos personales, y le asigna un entrenador, una membresía y una rutina. No se puede crear un usuario si no existe al menos un entrenador, una membresía y una rutina registrados previamente. 
* Mostrar todos los usuarios registrados: Muestra una lista detallada de todos los usuarios que han sido registrados, incluyendo sus datos y lo que tienen asignado. 
* Eliminar ejercicios de una rutina existente: Permite seleccionar una rutina ya creada y eliminar de ella un ejercicio específico por su nombre. 
* Salir del programa: Permite seleccionar una rutina ya creada y eliminar de ella un ejercicio específico por su nombre. 
Validaciones y restricciones
* No se permite crear usuarios sin tener al menos una membresía, una rutina y un entrenador registrados.

* Límite de almacenamiento:

    * Máximo 10 entrenadores.

    * Máximo 10 membresías.

    * Máximo 10 rutinas.

    * Máximo 100 usuarios.

* No hay validación avanzada de fechas o correos electrónicos.

* La entrada no validada (como letras en lugar de números) puede provocar errores de ejecución.

* No hay persistencia de datos: al cerrar el programa, se pierde la información.

Diagrama UML: 
![gimmnasioUML](https://github.com/user-attachments/assets/377afe9a-26c7-4bf3-ab8d-397ba10d80fd)

Consideraciones El programa está diseñado para correr en cualquier sistema operativo que soporte C++ estándar. Tutorial para compilar el programa en Windows: TylerMSFT. (2023, 12 de octubre). Tutorial: Compilar un programa nativo de C++ en la línea de comandos. Microsoft aprende. https://learn.microsoft.com/es-es/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-170
