# Codigo ejemplo para Estructuras de Datos IC2001

Toda la información aqui colocada es parte de las prácticas que se desarrollan, se deben complementar y requieren guías para hacerlo que son proporcionadas por el profesor. No intenta ser un sitio con información completa más halla de fines académicos para el curso de Estructuras de Datos.


## Búsqueda secuencial
Cuando los ítems de datos se almacenan en una colección, por ejemplo en una lista, decimos que tienen una relación lineal o secuencial. Cada ítem de datos se almacena en una posición relativa a los demás. En las listas de Python, estas posiciones relativas son los valores de los índices de los ítems individuales. Dado que estos valores de los índices están ordenados, es posible para nosotros visitarlos en secuencia. Este proceso da lugar a nuestra primera técnica de búsqueda, la búsqueda secuencial.

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



## Binaria
La búsqueda de un elemento dentro de un array es una de las operaciones más importantes en el procesamiento de información, y permite la recuperación de datos. El caso de la Búsqueda Binaria, que es uno de las tantas búsquedas que existe, pero la más usada, está hecho para diferentes campos en el mundo laboral, como por ejemplo una secretaria podría perder tan sólo uno o dos minutos para encontrar el archivo de uno de los clientes de la compañía para la cual trabaja, esto, asumiendo que los archivos estén perfectamente ordenados y catalogados.

```c++
using namespace std;

int main ()
{
    int n, i, iarreglo[30], num, primero, ultimo, medio;
    cout<<"Ingrese un arreglo ordenado: ";
    cout<<"Cuantos elementos te gustaria ingresar?: ";
    cin>>n;
    
    for (i=0; i>iarreglo[i]; 
    {
        cout<<"Ingrese el numero que desea buscar: ";
        cin>>num;
    }
    primero=0;
    ultimo=n-1;
    meedio=(primero+ultimo)/2;
    while (primero<=ultimo); 
    {
        if (A[medio]< num);
        {
            primero=medio+1;
        } else if (A[medio]== num) 
        {
            cout<<" Se encontro la posición ";
            cout<<medio+1;
            break;
        }
        else {
            ultimo = medio - 1;
        }

        medio = (primero+ultimo)/2;
    }
    if (primero>ultimo)
    {
        cout<<num<<" no se encontro";
    }

    return 0;
}

```

## Búsqueda por interpolación
La búsqueda de interpolación es un algoritmo para buscar una clave en una matriz que ha sido ordenada por valores numéricos asignados a las claves ( valores clave ). Fue descrito por primera vez por WW Peterson en 1957. La búsqueda por interpolación se asemeja al método por el cual las personas buscan un nombre en una guía telefónica (el valor clave por el cual se ordenan las entradas del libro): en cada paso, el algoritmo calcula en qué lugar del espacio de búsqueda restante el elemento buscado podría basarse en los valores de clave en los límites del espacio de búsqueda y el valor de la clave buscada, generalmente mediante una interpolación lineal . El valor de clave que se encuentra realmente en esta posición estimada se compara con el valor de clave que se busca. Si no es igual, dependiendo de la comparación, el espacio de búsqueda restante se reduce a la parte anterior o posterior a la posición estimada. Este método solo funcionará si los cálculos sobre el tamaño de las diferencias entre los valores clave son razonables.

```c++
#include <iostream>
using namespace std;
 
//Print array values
void print_ar (int ar[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    cout << ar[i] << " ";
  }
    cout << endl;
}
 
//Interpolation Search
int interpolation_search (int ar[], int value, int size)
{
  int low = 0;
  int high = size - 1;
  int mid;
 
  while (ar[low] <= value && ar[high] >= value)
  {
    mid = low + ((value - ar[low]) * (high - low)) / (ar[high] - ar[low]);
    if (ar[mid] < value)
    {
      low = mid + 1;
    }
    else if (ar[mid] > value)
    {
      low = mid - 1;
    }
    else
    {
      return mid;
    }
  }
 
  if (ar[low] == value)
  {
    return low;
  }
  else
  {
    return -1;
  }
}
 
//Driver Function
int main()
{
  int ar [] = {1, 2, 78, 18, 16, 30, 29, 2, 0, 199};
  int value, pos;
 
  cout << "Your Array : ";
  print_ar (ar, 10);
 
  cout << "Enter the value to search : ";
  cin >> value;
  pos = interpolation_search (ar, value, 10);
  if (pos != -1)
  {
    cout << "Value Found! at position : " << pos + 1 << endl;
  }
  else
  {
    cout << "Sorry, the value you searched for is not present." << endl;
  }
 
  return 0;
}
```

## Estructuras con funciones de Hash

El hash es una estructura de datos importante que está diseñada para usar una función especial llamada función Hash que se usa para mapear un valor dado con una clave particular para un acceso más rápido a los elementos. La eficiencia del mapeo depende de la eficiencia de la función hash utilizada.

Deje que una función hash H (x) mapee el valor x en el índice x%10 en una  arreglo4. Por ejemplo, si la lista de valores es [11,12,13,14,15], se almacenará en las posiciones {1,2,3,4,5} en la matriz o la tabla Hash, respectivamente.

Para matrices y listas enlazadas, necesitamos buscar de forma lineal, lo que puede resultar costoso en la práctica. Si usamos matrices y mantenemos los datos ordenados, entonces se puede buscar un número de teléfono en tiempo _O(Logn)_ usando la búsqueda binaria, pero las operaciones de inserción y eliminación se vuelven costosas ya que tenemos que mantener el orden ordenado. 
Con el árbol de búsqueda binario equilibrado, obtenemos tiempos de búsqueda, inserción y eliminación moderados. Se puede garantizar que todas estas operaciones se realicen en tiempo _O(Logn)_.

**Función hash**: una función que convierte un número de teléfono grande dado en un pequeño valor entero práctico. El valor entero mapeado se utiliza como índice en la tabla hash. En términos simples, una función hash asigna un número grande o una cadena a un entero pequeño que se puede usar como índice en la tabla hash.
Una buena función hash debería tener las siguientes propiedades
* Eficientemente computable.
* Debe distribuir uniformemente las teclas (cada posición de la mesa es igualmente probable para cada tecla)

Por ejemplo, para los números de teléfono, una función hash incorrecta es tomar los primeros tres dígitos. Una mejor función es considerar los últimos tres dígitos. Tenga en cuenta que esta puede no ser la mejor función hash. Puede haber mejores formas.

**Tabla hash**: una matriz que almacena punteros a registros correspondientes a un número de teléfono determinado. Una entrada en la tabla hash es NIL si ningún número de teléfono existente tiene un valor de función hash igual al índice de la entrada.

**Manejo de colisiones**: dado que una función hash nos da un número pequeño para una clave grande, existe la posibilidad de que dos claves den el mismo valor. La situación en la que una clave recién insertada se asigna a una ranura ya ocupada en la tabla hash se denomina colisión y debe manejarse utilizando alguna técnica de manejo de colisiones. Las siguientes son las formas de manejar las colisiones:

**Encadenamiento**: la idea es hacer que cada celda de la tabla hash apunte a una lista vinculada de registros que tengan el mismo valor de _función hash_. El encadenamiento es simple, pero requiere memoria adicional fuera de la _tabla_.
Direccionamiento abierto: en el direccionamiento abierto, todos los elementos se almacenan en la propia _tabla hash_. Cada entrada de la tabla contiene un registro o **NIL**. Al buscar un elemento, examinamos uno por uno los espacios de la tabla hasta que se encuentra el elemento deseado o hasta que queda claro que el elemento no está en la tabla.

```c++
/*
 *C++ Program to Implement Hash Tables
 */
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 128;
 
/*
 * HashEntry Class Declaration
 */
class HashEntry
{
    public:
        int key;
        int value;
        HashEntry(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
};
 
/*
 * HashMap Class Declaration
 */
class HashMap
{
    private:
        HashEntry **table;
    public:   
        HashMap()
	{
            table = new HashEntry * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++)
            {
                table[i] = NULL;
            }
        }
        /*
         * Hash Function
         */
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
        /*
         * Insert Element at a key
         */
	void Insert(int key, int value)
	{
            int hash = HashFunc(key);
            while (table[hash] != NULL && table[hash]->key != key)
            {
                hash = HashFunc(hash + 1);
            }
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
	}
        /*
         * Search Element at a key
         */
        int Search(int key)
	{
	    int  hash = HashFunc(key);
	    while (table[hash] != NULL && table[hash]->key != key)
	    {
	        hash = HashFunc(hash + 1);
	    }
	    if (table[hash] == NULL)
	        return -1;
	    else
	        return table[hash]->value;
        }
 
        /*
         * Remove Element at a key
         */
        void Remove(int key)
	{
	    int hash = HashFunc(key);
	    while (table[hash] != NULL)
	    {
	        if (table[hash]->key == key)
	            break;
	        hash = HashFunc(hash + 1);
	    }
            if (table[hash] == NULL)
	    {
                cout<<"No Element found at key "<<key<<endl;
                return;
            }
            else
            {
                delete table[hash];
            }
            cout<<"Element Deleted"<<endl;
        }
        ~HashMap()
	{
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (table[i] != NULL)
                    delete table[i];
                delete[] table;
            }
        }
};
/*
 * Main Contains Menu
 */
int main()
{
    HashMap hash;
    int key, value;
    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Delete element at a key"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
            cout<<"Enter key at which element to be inserted: ";
            cin>>key;
            hash.Insert(key, value);
            break;
        case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
            if (hash.Search(key) == -1)
            {
	        cout<<"No element found at key "<<key<<endl;
	        continue;
	    }
	    else
	    {
	        cout<<"Element at key "<<key<<" : ";
	        cout<<hash.Search(key)<<endl;
	    }
            break;
        case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>key;
            hash.Remove(key);
            break;
        case 4:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
