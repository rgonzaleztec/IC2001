# Codigo ejemplo para Estructuras de Datos IC2001

Toda la información aqui colocada es parte de las prácticas que se desarrollan, se deben complementar y requieren guías para hacerlo que son proporcionadas por el profesor. No intenta ser un sitio con información completa más halla de fines académicos para el curso de Estructuras de Datos.


## Estructuras Jerárquocas (Árboles)
En ciencias de la computación y en informática, un árbol es un tipo abstracto de datos (TAD) ampliamente usado que imita la estructura jerárquica de un árbol, con un valor en la raíz y subárboles con un nodo padre, representado como un conjunto de nodos enlazados.

![Jerarquica vs lineal](/Codigo/Semana%206/img/arbolvslineal.png)

**Componentes importantes de los árboles**
**Nodos**:Se le llama Nodo a cada elemento que contiene un Árbol

**Nodo Raíz**:Se refiere al primer nodo de un Árbol, Solo un nodo del Árbol puede ser la Raíz

**Nodo Padre**:Se utiliza este termino para llamar a todos aquellos nodos que tiene al menos un hijo

**Nodo Hijo**:Los hijos son todos aquellos nodos que tiene un padre

**Nodo Hermano**:Los nodos hermanos son aquellos nodos que comparte a un mismo padre en común dentro de la estructura

**Nodo Hoja**:Son todos aquellos nodos que no tienen hijos, los cuales siempre se encuentran en los extremos de la estructura

**Nodo Rama**:Estos son todos aquellos nodos que no son la raíz  y que ademas tiene al menos un hijo

![Tipos de nodos](/Codigo/Semana%206/img/tiposdenodos.png)


Nodos padre e hijo

![Padre e hijo](/Codigo/Semana%206/img/nodospadrehijohermano.png)

Los arboles a demas de los nodos tiene otras propiedades importantes que son utilizadas en diferente ámbitos los cuales son:
__Nivel__: Nos referimos como nivel a cada generación dentro del árbol. Por ejemplo, cuando a un nodo hoja le agregamos un hijo, el nodo hoja pasa a ser un nodo rama pero a demas el árbol crece una generación por lo que el Árbol tiene un nivel mas.Cada generación tiene un número de Nivel distinto que las demas generaciones.

* Un árbol vacío tiene 0 niveles
* El nivel de la Raíz es 1
* El nivel de cada nodo se calculado contando cuantos nodos existen sobre el, hasta llegar a la raíz + 1, y de forma inversa también se podría, contar cuantos nodos existes desde la raíz hasta el nodo buscado + 1.

__Altura__: Le llamamos Altura al número máximo de niveles de un Árbol

![Altura y Nivel](/Codigo/Semana%206/img/alturaniveles.png)

__Peso__: Conocemos como peso a el número de nodos que tiene un Árbol. Este factor es importante por que nos da una idea del tamaño del árbol y el tamaño en memoria que nos puede ocupar en tiempo de ejecución(Complejidad Espacial en análisis de algoritmos.)

![Peso](/Codigo/Semana%206/img/peso.png)


__Orden__: El Orden de un árbol es el número máximo de hijos que puede tener un Nodo

![Orden](/Codigo/Semana%206/img/orden.png)

__Grado__: El grado se refiere al número mayor de hijos que tiene alguno de los nodos del Árbol y esta limitado por el Orden, ya que este indica el número máximo de hijos que puede tener un nodo

![Grado](/Codigo/Semana%206/img/grado.png)

## Árbol n-ario
Los arboles n-arios son aquellos arboles donde el número máximo de hijos por nodo es de N, en la figura 7 podemos apreciar dos árboles con grado 2 y grado 3, estos dos arboles también los podemos definir como Árbol n-ario con n = 2 y n=3 respectivamente.

## Árboles binarios
Esta estructura se caracteriza por que cada nodo solo puede tener máximo 2 hijo, dicho de otra manera es un Árbol n-ario de Grado 2.

![Binario](/Codigo/Semana%206/img/arbolbinario.png)

__Árbol binario lleno__: Es aquel que el que todos los nodos tiene cero o 2 hijos con excepción de la Raíz.

![lleno](/Codigo/Semana%206/img/arbolbinariolleno.png)

__Árbol binario perfecto__: Es un Árbol lleno en donde todos las Hojas están en el mismo Nivel.

![perfecto](/Codigo/Semana%206/img/arbolbinarioperfecto1.png)


## Recorridos sobre Árboles
Los recorridos son algoritmos que nos permiten recorrer un árbol en un orden especifico, los recorridos nos pueden ayudar encontrar un nodo en el árbol, o buscar una posición determinada para insertar o eliminar un nodo.

Básicamente podemos catalogar las búsqueda en dos tipos, las búsqueda en profundidad y las búsquedas en amplitud.

## Búsqueda en profundidad
**Recorrido Pre-orden**: El recorrido inicia en la Raíz y luego se recorre en pre-orden cada unos de los sub-árboles de izquierda a derecha.

Esta definición puede ser un poco compleja de entender por lo que mejor les dejo la siguiente imagen.

![Preorden](/Codigo/Semana%206/img/preorden.png)

### Función recursiva que recorre un árbol en preorden

```c++
    public void preorden(NodoArbol nodo)
    {
        if (nodo==null)
            return;

        std::cout >> "Valor de Nodo ->" >> nodo.value;
        preorden(nodo.hijo1);
        preorden(nodo.hijo2);
    }
```


**Recorido pos-orden**: Se recorre el pos-orden cada uno de los sub-árboles y al final se recorre la raíz.

Para comprender mejor esta definición observemos la siguiente imagen:

![Pos-orden](/Codigo/Semana%206/img/postorden.png)

### Función recursiva que recorre un árbol en Post-orden

```c++
    public void posorden(NodoArbol nodo)
    {
        if (nodo==null)
            return;

        posorden(nodo.hijo1);
        posorden(nodo.hijo2);
        std::cout >> "Valor de Nodo ->" >> nodo.value;
       
    }
```

**Recorrido in-orden**: Se recorre en in-orden el primer sub-árbol, luego se recorre la raíz y al final se recorre en in-orden los demas sub-árboles

![En-orden](/Codigo/Semana%206/img/inorden.png)

### Función recursiva que recorre un árbol en En-orden

```c++
    public void inorden(NodoArbol nodo)
    {
        if (nodo==null)
            return;

        inorden(nodo.hijo1);
        std::cout >> "Valor de Nodo ->" >> nodo.value;
        inorden(nodo.hijo2);
        
       
    }
```

## Búsqueda en amplitud
Se recorre primero la raíz, luego se recorren los demas nodos ordenados por el nivel al que pertenecen en orden de Izquierda a derecha.
Este tipo de búsqueda se caracteriza por que la búsqueda se hace nivel por nivel y de izquierda a derecha.

![En-orden](/Codigo/Semana%206/img/busquedaamplitud.png)

En la imagen podemos observa que el árbol es recorrido en su totalidad pero esto no siempre es a sí, ya que el algoritmo se detiene cuando el elemento buscado es encontrado.

### Función busqueda anchura

```c++
    public boolean busquedaAnchura(char c)
    {
        Queue<NodoArbol> colaAuxiliar = New Linkedlist<NodoArbol>();
        colaAuxiliar.add(raiz);

        while (colaAuxiliar.size() !=0)
        {
            NodoArbol nodo = colaAuxiliar.poll();
            std::cout >> "Valor de Nodo ->" >> nodo.value;
            if (nodo.value == c)
            {
                return true;
            }
            else
            {
                colaAuxiliar.add(nodo.hijo1);
                colaAuxiliar.add(nodo.hijo2);
            }
        }
        return false;
        
       
    }
```

Si observamos el código de forma minuciosa podemos observar dos puntos muy interesantes, el primero es que esta función no es recursiva, y la segunda es que se utiliza una Cola para controlar el flujo del recorrido.

Los pasos para hacer el recorrido es el siguiente:

* Se agrega la Raíz a la cola de nodos por visitar
*   Mientras que la cola no este vacía se saca el primer elemento de la cola y continuamos con el paso 3, Pero; si la cola esta vacía entonces nos vamos al paso 5.
*   Se valida si el elemento sacado de la pila es el que estamos buscando, Si lo es, entonces hemos terminado, Si no lo es se agregan todos los hijos del nodo a la pila de nodos pendientes por procesar.
*   Regresamos al paso 2.
*   Terminamos sin un resultado.




## Implementación en C++
```c++
using namespace std;
int main()
{
    int n, iarreglo[30], ibuscado=0;
    bool encontrado;
    cout << "Ingrese maximo 30 números para un arreglo:\n";
    cout << "Cuantos elementos te gustaria ingresar?: \n";
    cin >> n;
    cout << "Ingresaremos:" << n << endl;
    int valor=0;

    for (int idx = 0; idx < n; ++idx)
    {
        cin >> valor;
        iarreglo[idx] = valor;
        cout << iarreglo[idx] << std::endl;
        valor = 0;
    }
    n = 0;

    cout << "Cual numero buscas?\n" << endl;
    cin >> ibuscado;
    encontrado = false;
    while (n < 30)
    {
        if (iarreglo[n] == ibuscado)
        {
            n = 30;
            cout << "Numero encontrado" << endl;
            encontrado = true;
        }
        cout << n << endl;
        n++;
    }
    if (encontrado == false)
    {
        cout << "Numero No encontrado" << endl;
    }
    cin >> ibuscado;
    return 0;
}
```
**Intenta hacer una versión de este algoritmo pero ordenado primero y luego haces la busqueda**
**Toma el tiempo antes de entrar al while y despues de salir para que compares**




## License
[MIT](https://choosealicense.com/licenses/mit/)
