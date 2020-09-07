# Prácticas de Estructuras de Datos IC2001 Semana 2

## Contribuciones
Solicitudes de pull son bienvenidas como mejoras a los codigos o prácticas aquí alojadas. Para cambios grandes debe crear un discusión o crear un incidente para analizarlo.

Por favor asegurece que código ha sido realmente probado antes de solicitar el pull.

## Laboratorio sobre arreglos
Utilizando un arreglo modifique el código de OpenGL para que el nombre de la ventana sea pedido al usuario usuario en la consola antes de cargar la ventana de openGL. El texto debe aparecer en la ventana.

### Uso de arreglos y matrices
Lo que se pretende en este laboratorio es el manejo de arreglos y matrices, además utilizar algoritmos sencillos.

Ingrese al ambiente de programación, cree un nuevo proyecto  y declare un arreglo de enteros para 10 valores numéricos y almacenarlos en un arreglo. En vez de leer los números de teclado, insértele números random. 
Para esto primero debe incluir 

```c++
#include <time.h>
Inicialice el random con la siguiente función.
srand ( time(NULL) );// solo se hace una única vez, no cada vez que genere un número.
Para escoger el número random puede hacerlo con la siguiente instrucción 
int numero = rand() % 100;
```
### Varios ejercicos para prácticar
* Realice un método para imprimir en consola cual es el número menor y cuál es el número mayor que está almacenado en el arreglo
* Realice un método para imprimir los números pares almacenados en el arreglo
* Imprima la sumatoria de los números múltiplos de 3 y la sumatoria de los números múltiplos de 5
* Declare una matriz pequeña a lo sumo de 7 filas, 7 columnas, almacene en ella valores enteros aleatorios (0 a 81)
* Imprima las dos diagonales de la matriz usado ciclos


## Laboratorios con listas
* Primero vamos a crear una estructura de datos EDT abstracta para poder manejar mi horario semanal.
La estructura debe tener nombre del día, nombre de la clase, indicar de M(mañana),T(tarde),N(noche), NumHoras

* Cree una función que inserte un nodo nuevo a la lista de clases de horario
* Cree una función que imprima la lista del inicio al final
* Imprimir la lista del final hacia el inicio
* Contar e imprimir la cantidad de los nodos de la lista
* Realizar una función booleana “buscar” para determinar si una clase ya está insertada en el horario
* Modifique la función de insertar para que inserte en cualquier parte de la lista
* Cree una función que le permite borrar un nodo
* Cree una función que le permita modificar un nodo
* Cree una función que le permite contar cuantos elementos tiene la lista
* Cree todas las funciones de insertar, borrar, modificar, buscar pero ahora para listas doblemente enlazadas
* Cree listas enlazas para controlar las tareas que hago durante la semana


## License
[MIT](https://choosealicense.com/licenses/mit/)
