# Codigo ejemplo para Estructuras de Datos IC2001

Toda la información aqui colocada es parte de las prácticas que se desarrollan, se deben complementar y requieren guías para hacerlo que son proporcionadas por el profesor. No intenta ser un sitio con información completa más halla de fines académicos para el curso de Estructuras de Datos.


## Árboles Balanceados por Altura (AVL)
Los árboles AVL son árboles BB donde todo nodo cumple la propiedad de equilibrado AVL:

* La altura del subárbol izquierdo y del derecho no se diferencian en más de uno
* Son árboles binarios balanceados por altura
* Concebidos especialmente para ser aplicados en los árboles binarios de búsqueda
* Evitan que los árboles se “degeneren” (sesgados a derecha o izquierda)
* Sus inventores fueron G. Adelson-Velskii y E. Landis
* Su implementación es más compleja que un árbol binario simple
* Las operaciones de búsqueda, inserción y borrado mantienen un buen tiempo de desempeño O(Log n) 
* Para comprender el algoritmo de inserción en AVL se requiere entender primero que son las rotaciones
* La operación de borrado es bastante compleja
* Se han propuesto variantes y mejoras a los árboles AVL: Árboles rojinegros, Árboles Splay, AA-Árboles
* Se verá a continuación las rotaciones y luego el algoritmo de inserción


Los AVL son también ABB, de modo que mantienen todas las operaciones que poseen éstos. Las nuevas operaciones son las de equilibrar el árbol, pero eso se hace como parte de las operaciones de insertado y borrado.

**No se trata de árboles perfectamente equilibrados**, pero sí son lo suficientemente equilibrados como para que su comportamiento sea lo bastante bueno como para usarlos donde los ABB no garantizan tiempos de búsqueda óptimos.

El algoritmo para mantener un árbol AVL equilibrado se basa en reequilibrados locales, de modo que no es necesario explorar todo el árbol después de cada inserción o borrado.


## Factor de Balance
Cada nodo, además de la información que se pretende almacenar, debe tener los dos punteros a los árboles derecho e izquierdo, igual que los ABB, y además un miembro nuevo: el factor de equilibrio.

El factor de equilibrio es la diferencia entre las alturas del árbol derecho y el izquierdo:
**FE = altura subárbol derecho - altura subárbol izquierdo;**
__Por definición, para un árbol AVL, este valor debe ser -1, 0 o 1__

### Rotaciónes simples de nodos
Consiste en reacomodar los registros de un árbol binario de tal forma que los factores de balance de todos los nodos sean -1, 0, ó 1 y que el recorrido inorden sea el mismo que antes del reacomodo. Estas operaciones se conocen como rotaciones.
Los reequilibrados se realizan mediante rotaciones, en el siguiente punto veremos cada caso, ahora vamos a ver las cuatro posibles rotaciones que podemos aplicar

### Rotación Simple a la derecha (SD)
Esta rotación se usará cuando el subárbol izquierdo de un nodo sea 2 unidades más alto que el derecho, es decir, cuando su FE sea de -2. Y además, la raíz del subárbol izquierdo tenga una FE de -1 ó 0, es decir, que esté cargado a la izquierda o equilibrado.

Procederemos del siguiente modo:
Llamaremos P al nodo que muestra el desequilibrio, el que tiene una FE de -2. Y llamaremos Q al nodo raíz del subárbol izquierdo de P. Además, llamaremos A al subárbol izquierdo de Q, B al subárbol derecho de Q y C al subárbol derecho de P.

En el gráfico que puede observar que tanto B como C tienen la misma altura (n), y A es una unidad mayor (n+1). Esto hace que el FE de Q sea -1, la altura del subárbol que tiene Q como raíz es (n+2) y por lo tanto el FE de P es -2.

* Pasamos el subárbol derecho del nodo Q como subárbol izquierdo de P. Esto mantiene el árbol como ABB, ya que todos los valores a la derecha de Q siguen estando a la izquierda de P.
* El árbol P pasa a ser el subárbol derecho del nodo Q.
* Ahora, el nodo Q pasa a tomar la posición del nodo P, es decir, hacemos que la entrada al árbol sea el nodo Q, en lugar del nodo P. Previamente, P puede que fuese un árbol completo o un subárbol de otro nodo de menor altura.

El siguiente árbol esta desequilibrado a la izquierda. Se requiere la fórmula para estimar la altura para este proceso.

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-1.gif)

Empezamos el cálculo de las alturas para cada nodo padre, el proceso se detiene cuando se llega a los nodos hoja. Se logra determinar que el nodo raíz de todo el árbol esta desbalanciado, por lo que ahora vamos a mover Q y P, vamos a hacer una rotación simple a la derecha.

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-2.gif)

Movemos los enlaces de Nodo (3) a Nodo (5) y de este a Nodo (4)

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-3.gif)

Ahora Nodo (3) pasa a ser el padre de todo el árbol

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-4.gif)

En el árbol resultante se puede ver que tanto P como Q quedan equilibrados en cuanto altura. En el caso de P porque sus dos subárboles tienen la misma altura (n), en el caso de Q, porque su subárbol izquierdo A tiene una altura (n+1) y su subárbol derecho también, ya que a P se añade la altura de cualquiera de sus subárboles.

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-5.gif)

En el caso de que el subárbol izquierdo esté equilibrado, el procedimiento es similar, pero los FE de los nodos P y Q en el árbol resultante son diferentes.

En principio, parece poco probable que nos encontremos un árbol con esta estructura, pero es posible encontrarlos cuando se borran nodos.

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-1b.gif)

Aplicamos el mismo algoritmo para la rotación:

Paso 1

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-2b.gif)

Paso 2

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-3b.gif)

Paso 4

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-4b.gif)

En el árbol resultante se puede ver que tanto P como Q quedan equilibrados en cuanto altura. En el caso de P porque su subárbol izquierdo es una unidad más alto que el derecho, quedando su FE en -1. En el caso de Q, porque su subárbol derecho una altura (n+1) y su subárbol izquierdo, una altura de n.

![Desequilibrado a la izquierda](/Codigo/Semana%207/img/RSD-5b.gif)

De modo que, aunque aplicamos el mismo algoritmo, ya que en ambos casos se trata de una rotación simple, deberemos tener en cuenta estos detalles a la hora de ajustar los nuevos valores de FE en nuestro programa.

### Rotación simple a la Izquierda (SI)
Se trata del caso simétrico del anterior. Esta rotación se usará cuando el subárbol derecho de un nodo sea 2 unidades más alto que el izquierdo, es decir, cuando su FE sea de 2. Y además, la raíz del subárbol derecho tenga una FE de 1 ó 0, es decir, que esté cargado a la derecha o esté equilibrado.

Procederemos del siguiente modo:

Llamaremos P al nodo que muestra el desequilibrio, el que tiene una FE de 2. Y llamaremos Q al nodo raíz del subárbol derecho de P. Además, llamaremos A al subárbol izquierdo de P, B al subárbol izquierdo de Q y C al subárbol derecho de Q.

En el gráfico que puede observar que tanto A como B tienen la misma altura (n), y C es una unidad mayor (n+1). Esto hace que el FE de Q sea 1, la altura del subárbol que tiene Q como raíz es (n+2) y por lo tanto el FE de P es 2.

* Pasamos el subárbol izquierdo del nodo Q como subárbol derecho de P. Esto mantiene el árbol como ABB, ya que todos los valores a la izquierda de Q siguen estando a la derecha de P.
* El árbol P pasa a ser el subárbol izquierdo del nodo Q.
* Ahora, el nodo Q pasa a tomar la posición del nodo P, es decir, hacemos que la entrada al árbol sea el nodo Q, en lugar del nodo P. Previamente, P puede que fuese un árbol completo o un subárbol de otro nodo de menor altura.

El siguiente es un árbol desequilibrado a la derecha

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RSI-1.gif)

Igual al anterior vamos calculando las alturas de los nodos primero. Buscamos los nodos que tengan el mayor desequilibrio, para luego buscar el hijo con el FE mayor para proceder a equilibrar.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RSI-2.gif)

Al calcular los FE nos damos cuenta que los nodos (9) y (5) van a requerir moverse.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RSI-3.gif)

Cambiamos los apuntadores para mantener el balance de nuestro árbol binario.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RSI-4.gif)

El proceso sencillo parece muy sencillo y con un poco de recursión lo podemos solventar.

En el árbol resultante se puede ver que tanto P como Q quedan equilibrados en cuanto altura. En el caso de P porque sus dos subárboles tienen la misma altura (n), en el caso de Q, porque su subárbol izquierdo A tiene una altura (n+1) y su subárbol derecho también, ya que a P se añade la altura de cualquiera de sus subárboles.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RSI-5.gif)


### Rotación doble a la derecha (DD)
Esta rotación se usará cuando el subárbol izquierdo de un nodo sea 2 unidades más alto que el derecho, es decir, cuando su FE sea de -2. Y además, la raíz del subárbol izquierdo tenga una FE de 1, es decir, que esté cargado a la derecha.

Este es uno de los posibles árboles que pueden presentar esta estructura, pero hay otras dos posibilidades. El nodo R puede tener una FE de -1, 0 ó 1. En cada uno de esos casos los árboles izquierdo y derecho de R (B y C) pueden tener alturas de n y n-1, n y n, o n-1 y n, respectivamente.

El modo de realizar la rotación es independiente de la estructura del árbol R, cualquiera de las tres produce resultados equivalentes. Haremos el análisis para el caso en que FE sea -1.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDD-1.gif)

En este caso tendremos que realizar dos rotaciones.

Llamaremos P al nodo que muestra el desequilibrio, el que tiene una FE de -2. Llamaremos Q al nodo raíz del subárbol izquierdo de P, y R al nodo raíz del subárbol derecho de Q.

* Haremos una rotación simple de Q a la izquierda.
* Después, haremos una rotación simple de P a la derecha.

Con más detalle, procederemos del siguiente modo:

* Pasamos el subárbol izquierdo del nodo R como subárbol derecho de Q. Esto mantiene el árbol como ABB, ya que todos los valores a la izquierda de R siguen estando a la derecha de Q.
* Ahora, el nodo R pasa a tomar la posición del nodo Q, es decir, hacemos que la raíz del subárbol izquierdo de P sea el nodo R en lugar de Q.
* El árbol Q pasa a ser el subárbol izquierdo del nodo R.

Observando tenemos problemas con R y P que tienen un FE de -2. Vamos a tener que aplicar una doble rotación.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDD-2.gif)

Hemos movido a Nodo (7) como padre de (5) y (8). Recomodamos los enlaces de estos y volvmoes a calcular los FE de los nodos y se mantiene un -2 lo cual debemos corregir.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDD-3.gif)

* Pasamos el subárbol derecho del nodo R como subárbol izquierdo de P. Esto mantiene el árbol como ABB, ya que todos los valores a la derecha de R siguen estando a la izquierda de P.
* Ahora, el nodo R pasa a tomar la posición del nodo P, es decir, hacemos que la entrada al árbol sea el nodo R, en lugar del nodo P. Como en los casos anteriores, previamente, P puede que fuese un árbol completo o un subárbol de otro nodo de menor altura.
* El árbol P pasa a ser el subárbol derecho del nodo R.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDD-4.gif)

Hemos movido a Nodo (7) como padre mayor del árbol, ahora (5) y (9) son sus hijos y logramos reacomodar nuestro árbol y ya la FE esta con valores que podemos aceptar.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDD-5.gif)

### Rotación doble a la izquierda (DI)
Esta rotación se usará cuando el subárbol derecho de un nodo sea 2 unidades más alto que el izquierdo, es decir, cuando su FE sea de 2. Y además, la raíz del subárbol derecho tenga una FE de -1, es decir, que esté cargado a la izquierda. Se trata del caso simétrico del anterior.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDI-1.gif)

En este caso también tendremos que realizar dos rotaciones.

Llamaremos P al nodo que muestra el desequilibrio, el que tiene una FE de 2. Llamaremos Q al nodo raíz del subárbol derecho de P, y R al nodo raíz del subárbol izquierdo de Q.

* Haremos una rotación simple de Q a la derecha.
* Después, haremos una rotación simple de P a la izquierda.

Con más detalle, procederemos del siguiente modo:

* Pasamos el subárbol derecho del nodo R como subárbol izquierdo de Q. Esto mantiene el árbol como ABB, ya que todos los valores a la derecha de R siguen estando a la izquierda de Q.
* Ahora, el nodo R pasa a tomar la posición del nodo Q, es decir, hacemos que la raíz del subárbol derecho de P sea el nodo R en lugar de Q.
* El árbol Q pasa a ser el subárbol derecho del nodo R.

Luego de calcular los FE de todo el árbol podemos notar que hay qyue trabajar en los nodos (5), (7) y (10).

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDI-2.gif)

Una vez realizadas las reconexiones de los nodos, calculamos y nos damos cuenta que Nodo (5) y (7) aún tienen problemas.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDI-3.gif)

* Pasamos el subárbol izquierdo del nodo R como subárbol derecho de P. Esto mantiene el árbol como ABB, ya que todos los valores a la izquierda de R siguen estando a la derecha de P.
* Ahora, el nodo R pasa a tomar la posición del nodo P, es decir, hacemos que la entrada al árbol sea el nodo R, en lugar del nodo P. Como en los casos anteriores, previamente, P puede que fuese un árbol completo o un subárbol de otro nodo de menor altura.
* El árbol P pasa a ser el subárbol izquierdo del nodo R.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDI-4.gif)

Ahora tenemos un árbol balanceado con un FE que se puede aceptar.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/RDI-5.gif)

## Reequilibrados en árboles AVL
Cada vez que insertemos o eliminemos un nodo en un árbol AVL pueden suceder dos cosas: que el árbol se mantenga como AVL o que pierda esta propiedad. En el segundo caso siempre estaremos en uno de los explicados anteriormente, y recuperaremos el estado AVL aplicando la rotación adecuada.

Ya comentamos que necesitamos añadir un nuevo miembro a cada nodo del árbol para averiguar si el árbol sigue siendo AVL, el Factor de Equilibrio. Cada vez que insertemos o eliminemos un nodo deberemos recorrer el camino desde ese nodo hacia el nodo raíz actualizando los valores de FE de cada nodo. Cuando uno de esos valores sea 2 ó -2 aplicaremos la rotación correspondiente.

Debido a que debemos ser capaces de recorrer el árbol en dirección a la raíz, añadiremos un nuevo puntero a cada nodo que apunte al nodo padre. Esto complicará algo las operaciones de inserción, borrado y rotación, pero facilita y agiliza mucho el cálculo del FE, y veremos que las complicaciones se compensan en gran parte por las facilidades obtenidas al disponer de este puntero.

**En rigor, no es necesario ese puntero, podemos almacenar el camino que recorremos para localizar un nodo concreto usando una pila, y después podemos usar la pila para recuperar el camino en orden inverso. Pero esto nos obliga a introducir otra estructura dinámica, y según mi opinión, complica en exceso el algoritmo.**

Cuando estemos actualizando los valores de FE no necesitamos calcular las alturas de las dos ramas de cada nodo, sabiendo en valor anterior de FE, y sabiendo en qué rama hemos añadido o eliminado el nodo, es fácil calcular el nuevo valor de FE. Si el nodo ha sido añadido en la rama derecha o eliminado en la izquierda, y ha habido un cambio de altura en la rama, se incrementa el valor de FE; si el nodo ha sido añadido en la rama izquierda o eliminado en la derecha, y ha habido un cambio de altura en la rama, se decrementa el valor de FE.

Los cambios de altura en una rama se producen sólo cuando el FE del nodo raíz de esa rama ha cambiado de 0 a 1 ó de 0 a -1. En caso contrario, cuando el FE cambia de 1 a 0 ó de -1 a 0, no se produce cambio de altura.

Si no hay cambio de altura, los valores de FE del resto de los nodos hasta el raíz no pueden cambiar, recordemos que el factor de equilibrio se define como la diferencia de altura entre las ramas derecha e izquierda de un nodo, la altura de la rama que no pertenece al camino no puede cambiar, puesto que sigue teniendo los mismos nodos que antes, de modo que si la altura de la rama que pertenece al camino no cambia, tampoco puede cambiar el valor de FE.

Por ejemplo, supongamos que en siguiente árbol AVL insertamos el nodo de valor 8:

![Desequilibrado a la derecha](/Codigo/Semana%207/img/AVL-i1.gif)

Para empezar, cualquier nodo nuevo será un nodo hoja, de modo que su FE será siempre 0.

Ahora actualizamos el valor de FE del nodo padre del que acabamos de insertar (P). El valor previo es 0, y hemos añadido un nodo en su rama izquierda, por lo tanto, el nuevo valor es -1. Esto implica un cambio de altura, por lo tanto, continuamos camino hacia la raíz.

A continuación tomamos el nodo padre de P (Q), cuyo valor previo de FE era 1, y al que también hemos añadido un nodo en su rama izquierda, por lo tanto decrementamos ese valor, y el nuevo será 0. En este caso no ha incremento de altura, la altura del árbol cuya raíz es Q sigue siendo la misma, por lo tanto, ninguno de los valores de FE de los nodos hasta el raíz puede haber cambiado. Es decir, no necesitamos seguir recorriendo el camino.

Si verificamos el valor de FE del nodo R vemos que efectivamente se mantiene, puesto que tanto la altura del subárbol derecho como del izquierdo, siguen siendo las mismas.

Pero algunas veces, el valor de FE del nodo es -2 ó 2, son los casos en los que perdemos la propiedad AVL del árbol, y por lo tanto tendremos que recuperarla.

### Reequilibrados en árboles AVL por inserción de un nodo
En ese caso, cuando el valor de FE de un nodo tome el valor -2 ó 2, no seguiremos el camino, sino que, con el valor de FE de el nodo actual y el del nodo derecho si FE es 2 o el del nodo izquierdo si es -2, determinaremos qué tipo de rotación debemos hacer.

| FE nodo actual | FE del nodo derecho | FE del nodo izquierdo | Rotación
| ------------- | ------------- | ------------- | ------------- |
| -2  | No Importa  | -1 | RSD
| -2  | No Importa  | 1 | RDD
| 2  | -1  | No Importa | RDI
| 2  | 1  | No Importa | RSI

El resto de los casos no nos interesan. Esto es porque en nodos desequilibrados hacia la derecha, con valores de FE positivos, siempre buscaremos el equilibrio mediante rotaciones a la izquierda, y viceversa, con nodos desequilibrados hacia la izquierda, con valores de FE negativos, buscaremos el equilibrio mediante rotaciones a la derecha.

Supongamos que el valor de FE del nodo ha pasado de -1 a -2, debido a que se ha añadido un nodo. Esto implica que el nodo añadido lo ha sido en la rama izquierda, si lo hubiéramos añadido en la derecha el valor de FE nunca podría decrecer.

### Reequilibrados en árboles AVL por borrado de un nodo
Cuando el desequilibrio se debe a la eliminación de un nodo la cosa puede ser algo diferente, pero veremos que siempre se puede llegar a uno de los casos anteriores.

Supongamos el siguiente ejemplo, en el árbol AVL eliminaremos el nodo de valor 3:

![Desequilibrado a la derecha](/Codigo/Semana%207/img/AVL-b1.gif)

![Desequilibrado a la derecha](/Codigo/Semana%207/img/AVL-b2.gif)

El valor de FE del nodo P pasa de 1 a 2, sabemos que cuando el valor de FE de un nodo es 2 siempre tenemos que aplicar una rotación a izquierdas. Para saber cual de las dos rotaciones debemos aplicar miramos el valor de FE del nodo derecho. Pero en este caso, el valor de FE de ese nodo es 0. Esto no quiere decir que no podamos aplicar ninguna de las rotaciones, por el contrario, podremos aplicar cualquiera de ellas. Aunque por economía, lo razonable es aplicar la rotación simple.

Rotación Simple

![Desequilibrado a la derecha](/Codigo/Semana%207/img/AVL-b3.gif)

Del mismo modo, el valor de FE del nodo derecho podría haber sido 1 ó -1, en ese caso sí está determinado el tipo de rotación a realizar.

El razonamiento es similar cuando se eliminan nodos y el resultado es que se obtiene un nodo con FE de -2, en este caso se realizará una rotación a derechas, y la rotación dependerá del valor de FE del nodo izquierdo al que muestra el desequilibrio. Si es 0 ó -1 haremos una rotación simple, si es 1, haremos una rotación doble.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/AVL-b4.gif)

Tendremos entonces una tabla más general para decidir la rotación a aplicar:

| FE nodo actual | FE del nodo derecho | FE del nodo izquierdo | Rotación
| ------------- | ------------- | ------------- | ------------- |
| -2  | No Importa  | -1 | RSD
| -2  | No Importa  | 0 | RSD
| -2  | No Importa  | 1 | RDD
| 2  | -1  | No Importa | RDI
| 2  | 0  | No Importa | RSI
| 2  | 1  | No Importa | RSI

**Los árboles AVL siempre quedan equilibrados después de una rotación.**

Esto puede comprobarse analizando los métodos de rotación que hemos estudiado, después de efectuada la rotación, la altura del árbol cuya raíz es el nodo rotado se mantiene, por lo tanto, no necesitamos continuar el camino hacia la raíz: sabemos que el árbol es AVL.




```c++
// Arbol AVL en C++
// (C) Mayo 2002, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
using namespace std;

class AVL;

// Clase Nodo de Arbol AVL:
class Nodo {
  public:
   // Constructor:
   Nodo(const int dat, Nodo *pad=NULL, Nodo *izq=NULL, Nodo *der=NULL) :
     dato(dat), padre(pad), izquierdo(izq), derecho(der), FE(0) {}
   // Miembros:
   int dato;
   int FE;
   Nodo *izquierdo;
   Nodo *derecho;
   Nodo *padre;
   friend class AVL;
};

class AVL {
  private:
   enum {IZQUIERDO, DERECHO};
   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;

  public:
   // Constructor y destructor básicos:
   AVL() : raiz(NULL), actual(NULL) {}
   ~AVL() { Podar(raiz); }
   // Insertar en árbol ordenado:
   void Insertar(const int dat);
   // Borrar un elemento del árbol:
   void Borrar(const int dat);
   // Función de búsqueda:
   bool Buscar(const int dat);
   // Comprobar si el árbol está vacío:
   bool Vacio(Nodo *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
   // Contar número de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un dato:
   int Altura(const int dat);
   // Devolver referencia al dato del nodo actual:
   int &ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una función a cada elemento del árbol:
   void InOrden(void (*func)(int&, int) , Nodo *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(int&, int) , Nodo *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(int&, int) , Nodo *nodo=NULL, bool r=true);
  private:
   // Funciones de equilibrado:
   void Equilibrar(Nodo *nodo, int, bool);
   void RSI(Nodo* nodo);
   void RSD(Nodo* nodo);
   void RDI(Nodo* nodo);
   void RDD(Nodo* nodo);
   // Funciones auxiliares
   void Podar(Nodo* &);
   void auxContador(Nodo*);
   void auxAltura(Nodo*, int);
};

// Poda: borrar todos los nodos a partir de uno, incluido
void AVL::Podar(Nodo* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un dato en el árbol AVL
void AVL::Insertar(const int dat)
{
   Nodo *padre = NULL;

   cout << "Insertar: " << dat << endl;
   actual = raiz;
   // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new Nodo(dat);
   // Si el dato es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) {
      padre->izquierdo = new Nodo(dat, padre);
      Equilibrar(padre, IZQUIERDO, true);
   }
   // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->dato) {
      padre->derecho = new Nodo(dat, padre);
      Equilibrar(padre, DERECHO, true);
   }
}

// Equilibrar árbol AVL partiendo del nodo nuevo
void AVL::Equilibrar(Nodo *nodo, int rama, bool nuevo)
{
   bool salir = false;

   // Recorrer camino inverso actualizando valores de FE:
   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE--; // Depende de si añadimos ...
         else                  nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++; // ... o borramos
         else                  nodo->FE--;
      if(nodo->FE == 0) salir = true; // La altura de las rama que
                                      // empieza en nodo no ha variado,
                                      // salir de Equilibrar
      else if(nodo->FE == -2) { // Rotar a derechas y salir:
         if(nodo->izquierdo->FE == 1) RDD(nodo); // Rotación doble
         else RSD(nodo);                         // Rotación simple
         salir = true;
      }
      else if(nodo->FE == 2) {  // Rotar a izquierdas y salir:
         if(nodo->derecho->FE == -1) RDI(nodo); // Rotación doble
         else RSI(nodo);                        // Rotación simple
         salir = true;
      }
      if(nodo->padre) 
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre; // Calcular FE, siguiente nodo del camino.
   }   
}

// Rotación doble a derechas
void AVL::RDD(Nodo* nodo)
{
   cout << "RDD" << endl;
   Nodo *Padre = nodo->padre;
   Nodo *P = nodo;
   Nodo *Q = P->izquierdo;
   Nodo *R = Q->derecho;
   Nodo *B = R->izquierdo;
   Nodo *C = R->derecho;

   if(Padre) 
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else raiz = R;

   // Reconstruir árbol:
   Q->derecho = B;
   P->izquierdo = C;
   R->izquierdo = Q;
   R->derecho = P;
   
   // Reasignar padres:
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = Q;
   if(C) C->padre = P;

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}

// Rotación doble a izquierdas
void AVL::RDI(Nodo* nodo)
{
   cout << "RDI" << endl;
   Nodo *Padre = nodo->padre;
   Nodo *P = nodo;
   Nodo *Q = P->derecho;
   Nodo *R = Q->izquierdo;
   Nodo *B = R->izquierdo;
   Nodo *C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else raiz = R;

   // Reconstruir árbol:
   P->derecho = B;
   Q->izquierdo = C;
   R->izquierdo = P;
   R->derecho = Q;
   
   // Reasignar padres:
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = P;
   if(C) C->padre = Q;

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}

// Rotación simple a derechas
void AVL::RSD(Nodo* nodo)
{
   cout << "RSD" << endl;
   Nodo *Padre = nodo->padre;
   Nodo *P = nodo;
   Nodo *Q = P->izquierdo;
   Nodo *B = Q->derecho;

   if(Padre) 
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else raiz = Q;

   // Reconstruir árbol:
   P->izquierdo = B;
   Q->derecho = P;
   
   // Reasignar padres:
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

// Rotación simple a izquierdas
void AVL::RSI(Nodo* nodo)
{
   cout << "RSI" << endl;
   Nodo *Padre = nodo->padre;
   Nodo *P = nodo;
   Nodo *Q = P->derecho;
   Nodo *B = Q->izquierdo;

   if(Padre) 
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else raiz = Q;

   // Reconstruir árbol:
   P->derecho = B;
   Q->izquierdo = P;
   
   // Reasignar padres:
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;
   
   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

// Eliminar un elemento de un árbol AVL
void AVL::Borrar(const int dat)
{
   Nodo *padre = NULL;
   Nodo *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat == actual->dato) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            // El nodo padre del actual puede ser ahora un nodo hoja, por lo tanto su
            // FE es cero, pero debemos seguir el camino a partir de su padre, si existe.
            if((padre->derecho == actual && padre->FE == 1) ||
               (padre->izquierdo == actual && padre->FE == -1)) {
               padre->FE = 0;
               actual = padre;
               padre = actual->padre;
            }
            if(padre)
               if(padre->derecho == actual) Equilibrar(padre, DERECHO, false);
               else                         Equilibrar(padre, IZQUIERDO, false);
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::InOrden(void (*func)(int&, int) , Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato, nodo->FE);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PreOrden(void (*func)(int&, int), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->dato, nodo->FE);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PostOrden(void (*func)(int&, int), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato, nodo->FE);
}

// Buscar un valor en el árbol
bool AVL::Buscar(const int dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return true; // dato encontrado
      else if(dat > actual->dato) actual = actual->derecho; // Seguir
      else if(dat < actual->dato) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el dato dat
int AVL::Altura(const int dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; // dato encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int AVL::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void AVL::auxContador(Nodo *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int AVL::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void AVL::auxAltura(Nodo *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// Función de prueba para recorridos del árbol
void Mostrar(int &d, int FE)
{
   cout << d << "(" << FE << "),";
}

int main()
{
   // Un árbol de enteros
   AVL ArbolInt;

   // Inserción de nodos en árbol:
/*   ArbolInt.Insertar(15);
   ArbolInt.Insertar(4);
   ArbolInt.Insertar(20);
   ArbolInt.Insertar(3);
   ArbolInt.Insertar(25);
   ArbolInt.Insertar(6);
   ArbolInt.Insertar(8);*/
   ArbolInt.Insertar(1);
   ArbolInt.Insertar(2);
   ArbolInt.Insertar(3);
   ArbolInt.Insertar(4);
   ArbolInt.Insertar(5);
   ArbolInt.Insertar(6);
   ArbolInt.Insertar(7);
   ArbolInt.Insertar(8);
   ArbolInt.Insertar(9);
   ArbolInt.Insertar(10);
   ArbolInt.Insertar(11);
   ArbolInt.Insertar(12);
   ArbolInt.Insertar(13);
   ArbolInt.Insertar(14);
   ArbolInt.Insertar(15);
   ArbolInt.Insertar(16);

   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   // Mostrar el árbol en tres ordenes distintos:
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(8);
   ArbolInt.Borrar(11);

   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   // Mostrar el árbol en tres ordenes distintos:
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

/*   // Borraremos algunos elementos:
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   ArbolInt.Borrar(5);
   cout << "Borrar   5: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(8);
   cout << "Borrar   8: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(15);
   cout << "Borrar  15: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(245);
   cout << "Borrar 245: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(4);
   cout << "Borrar   4: ";
   ArbolInt.InOrden(Mostrar);
   ArbolInt.Borrar(17);
   cout << endl;
   cout << "Borrar  17: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   // Veamos algunos parámetros
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   cout << "Altura de 1 " << ArbolInt.Altura(1) << endl;
   cout << "Altura de 10 " << ArbolInt.Altura(10) << endl;
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   cin.get();

   // Arbol de cadenas:
   AVL<Cadena> ArbolCad;

   // Inserción de valores:
   ArbolCad.Insertar("Hola");
   ArbolCad.Insertar(",");
   ArbolCad.Insertar("somos");
   ArbolCad.Insertar("buenos");
   ArbolCad.Insertar("programadores");

   // Mostrar en diferentes ordenes:
   cout << "InOrden: ";
   ArbolCad.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolCad.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolCad.PostOrden(Mostrar);
   cout << endl;

   // Borrar "buenos":
   ArbolCad.Borrar("buenos");
   cout << "Borrar 'buenos': ";
   ArbolCad.InOrden(Mostrar);
   cout << endl; */
   cin.get();
   return 0;
}
```


## Árboles SPLAY (Zig-Zag)
Esta estructura garantiza que para cualquier secuencia de M operaciones en un árbol, empezando desde un árbol vacío, toma a lo más tiempo O(M log(N). A pesar que esto no garantiza que alguna operación en particular tome tiempo O(N), si asegura que no existe ninguna secuencia de operaciones que sea mala. En general, cuando una secuencia de M operaciones toma tiempo O(M f(N)), se dice que el costo amortizado en tiempo de cada operación es O(f(N)). Por lo tanto, en un splay tree los costos amortizados por operacion son de O(log(N)).

La idea básica de un splay tree es que después que un nodo es accesado éste se "sube" hasta la raíz del árbol a través de rotaciones al estilo AVL. Una manera de realizar esto, que NO funciona, es realizar rotaciones simples entre el nodo accesado y su padre hasta dejar al nodo accesado como raíz del árbol. El problema que tiene este enfoque es que puede dejar otros nodos muy abajo en el árbol, y se puede probar que existe una secuencia de M operaciones que toma tiempo O(M N), por lo que esta idea no es muy buena.

La estrategia de "splaying" es similar a la idea de las rotaciones simples. Si el nodo k es accesado, se realizaran rotaciones para llevarlo hasta la raíz del árbol. Sea k un nodo distinto a la raíz del árbol. Si el padre de k es la raíz del árbol, entonces se realiza una rotación simple entre estos dos nodos. En caso contrario, el nodo k posee un nodo padre p y un nodo "abuelo" a. Para realizar las rotaciones se deben considerar dos casos posibles (más los casos simétricos).

El primer caso es una inserción zig-zag, en donde k es un hijo derecho y p es un hijo izquierdo (o viceversa). En este caso, se realiza una rotación doble estilo AVL (ver siguiente figura).
![Desequilibrado a la derecha](/Codigo/Semana%207/img/splay1.png)

El otro caso es una inseción zig-zig, en donde k y p son ambos hijos izquierdo o derecho. En este caso, se realiza la transformación indicada en la figura siguiente.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/splay2.png)

El efecto del splaying es no sólo de mover el nodo accesado a la raíz, sino que sube todos los nodos del camino desde la raíz hasta el nodo accesado aproximadamente a la mitad de su profundidad anterior, a costa que algunos pocos nodos bajen a lo más dos niveles en el árbol.

El siguiente ejemplo muestra como queda el splay tree luego de accesar al nodo d.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/splay3.png)

El primer paso es un zig-zag entre los nodos d, b y f.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/splay4.png)

El último paso es un zig-zig entre los nodos d, h y j.

![Desequilibrado a la derecha](/Codigo/Semana%207/img/splay5.png)

Para borrar un elemento de un splay tree se puede proceder de la siguiente forma: se realiza una búsqueda del nodo a eliminar, lo cual lo deja en la raíz del árbol. Si ésta es eliminada, se obtienen dos subárboles Sizq y Sder. Se busca el elemento mayor en Sizq, con lo cual dicho elemento pasa a ser su nueva raíz, y como era el elemento mayor Sizq ya no tiene hijo derecho, por lo que se cuelga Sder como subárbol derecho de Sizq, con lo que termina la operación de eliminación.

El análisis de los splay trees es complejo, porque debe considerar la estructura cambiante del árbol en cada acceso realizado. Por otra parte, los splay trees son más fáciles de implementar que un AVL dado que no hay que verificar una condición de balance.

### Implementación en C++

```c++

/*
 *  C++ Program to Implement Splay Tree
 */
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
 
struct splay
{
    int key;
    splay* lchild;
    splay* rchild;
};
 
class SplayTree
{
    public:
        SplayTree()
        {
        }
 
        // RR(Y rotates to the right)
        splay* RR_Rotate(splay* k2)
        {
            splay* k1 = k2->lchild;
            k2->lchild = k1->rchild;
            k1->rchild = k2;
            return k1;
        }
 
        // LL(Y rotates to the left)
        splay* LL_Rotate(splay* k2)
        {
            splay* k1 = k2->rchild;
            k2->rchild = k1->lchild;
            k1->lchild = k2;
            return k1;
        }
 
        // An implementation of top-down splay tree
        splay* Splay(int key, splay* root)
        {
            if (!root)
                return NULL;
            splay header;
            /* header.rchild points to L tree;
            header.lchild points to R Tree */
            header.lchild = header.rchild = NULL;
            splay* LeftTreeMax = &header;
            splay* RightTreeMin = &header;
            while (1)
            {
                if (key < root->key)
                {
                    if (!root->lchild)
                        break;
                    if (key < root->lchild->key)
                    {
                        root = RR_Rotate(root);
                        // only zig-zig mode need to rotate once,
                        if (!root->lchild)
                            break;
                    }
                    /* Link to R Tree */
                    RightTreeMin->lchild = root;
                    RightTreeMin = RightTreeMin->lchild;
                    root = root->lchild;
                    RightTreeMin->lchild = NULL;
                }
                else if (key > root->key)
                {
                    if (!root->rchild)
                        break;
                    if (key > root->rchild->key)
                    {
                        root = LL_Rotate(root);
                        // only zag-zag mode need to rotate once,
                        if (!root->rchild)
                            break;
                    }
                    /* Link to L Tree */
                    LeftTreeMax->rchild = root;
                    LeftTreeMax = LeftTreeMax->rchild;
                    root = root->rchild;
                    LeftTreeMax->rchild = NULL;
                }
                else
                    break;
            }
            /* assemble L Tree, Middle Tree and R tree */
            LeftTreeMax->rchild = root->lchild;
            RightTreeMin->lchild = root->rchild;
            root->lchild = header.rchild;
            root->rchild = header.lchild;
            return root;
        }
 
        splay* New_Node(int key)
        {
            splay* p_node = new splay;
            if (!p_node)
            {
                fprintf(stderr, "Out of memory!\n");
                exit(1);
            }
            p_node->key = key;
            p_node->lchild = p_node->rchild = NULL;
            return p_node;
        }
 
        splay* Insert(int key, splay* root)
        {
            static splay* p_node = NULL;
            if (!p_node)
                p_node = New_Node(key);
            else
                p_node->key = key;
            if (!root)
            {
                root = p_node;
                p_node = NULL;
                return root;
            }
            root = Splay(key, root);
            /* This is BST that, all keys <= root->key is in root->lchild, all keys >
            root->key is in root->rchild. */
            if (key < root->key)
            {
                p_node->lchild = root->lchild;
                p_node->rchild = root;
                root->lchild = NULL;
                root = p_node;
            }
            else if (key > root->key)
            {
                p_node->rchild = root->rchild;
                p_node->lchild = root;
                root->rchild = NULL;
                root = p_node;
            }
            else
                return root;
            p_node = NULL;
            return root;
        }
 
        splay* Delete(int key, splay* root)
        {
            splay* temp;
            if (!root)
                return NULL;
            root = Splay(key, root);
            if (key != root->key)
                return root;
            else
            {
                if (!root->lchild)
                {
                    temp = root;
                    root = root->rchild;
                }
                else
                {
                    temp = root;
                    /*Note: Since key == root->key,
                    so after Splay(key, root->lchild),
                    the tree we get will have no right child tree.*/
                    root = Splay(key, root->lchild);
                    root->rchild = temp->rchild;
                }
                free(temp);
                return root;
            }
        }
 
        splay* Search(int key, splay* root)
        {
            return Splay(key, root);
        }
 
        void InOrder(splay* root)
        {
            if (root)
            {
                InOrder(root->lchild);
                cout<< "key: " <<root->key;
                if(root->lchild)
                    cout<< " | left child: "<< root->lchild->key;
                if(root->rchild)
                    cout << " | right child: " << root->rchild->key;
                cout<< "\n";
                InOrder(root->rchild);
            }
        }
};
 
int main()
{
    SplayTree st;
    int vector[10] = {9,8,7,6,5,4,3,2,1,0};
    splay *root;
    root = NULL;
    const int length = 10;
    int i;
    for(i = 0; i < length; i++)
        root = st.Insert(vector[i], root);
    cout<<"\nInOrder: \n";
    st.InOrder(root);
    int input, choice;
    while(1)
    {
        cout<<"\nSplay Tree Operations\n";
        cout<<"1. Insert "<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>input;
            root = st.Insert(input, root);
            cout<<"\nAfter Insert: "<<input<<endl;
            st.InOrder(root);
            break;
        case 2:
            cout<<"Enter value to be deleted: ";
            cin>>input;
            root = st.Delete(input, root);
            cout<<"\nAfter Delete: "<<input<<endl;
            st.InOrder(root);
            break;
        case 3:
            cout<<"Enter value to be searched: ";
            cin>>input;
            root = st.Search(input, root);
            cout<<"\nAfter Search "<<input<<endl;
            st.InOrder(root);
            break;
 
        case 4:
            exit(1);
        default:
            cout<<"\nInvalid type! \n";
        }
    }
    cout<<"\n";
    return 0;
}
```




## License
[MIT](https://choosealicense.com/licenses/mit/)
