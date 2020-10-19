# Codigo ejemplo para Estructuras de Datos IC2001

Toda la información aqui colocada es parte de las prácticas que se desarrollan, se deben complementar y requieren guías para hacerlo que son proporcionadas por el profesor. No intenta ser un sitio con información completa más halla de fines académicos para el curso de Estructuras de Datos.


## XML como estructura gerarquica
Especificación para diseñar lenguajes de marcado, que permite definir etiquetas personalizadas para descripción y organización de datos.

Permite representar información estructurada en la web (todos documentos), de modo que esta información pueda ser almacenada, transmitida, procesada, visualizada e impresa, por muy diversos tipos de aplicaciones y dispositivos.

Ventajas del XML:

* Fácilmente procesable
* Separa radicalmente el contenido y el formato de presentación
* Diseñado para cualquier lenguaje y alfabeto

### Estructura de un documento XML
Un documento XML está formado por datos de caracteres y marcado, el marcado lo forman las etiquetas:

![XML Estructura](/Codigo/Semana%208/img/img_2.jpg)

**Estructura**

```xml
<autor pais= "Costa Rica"> Rogelio Gonzalez </autor>
```

__autor__ nombre de elemento

__pais__ Nombre de Atributo

__"Costa Rica"__ Valor de Atributo

__Rogelio Gonzalez__ Contenido del Elemento
__</autor>__ Etiqueta de Fin

### Componentes de un documento XML
En un documento XML existen los siguientes componentes:

* **Elementos** Pieza lógica del marcado, se representa con una cadena de texto(dato) encerrada entre etiquetas. Pueden existir elementos vacíos (<br/>). Los elementos pueden contener atributos.
* **Instrucciones** Ordenes especiales para ser utilizadas por la aplicación que procesa

```xml
<?xml-stylesheet type=“text/css” href=“estilo.css”>
```

* **Las instrucciones XML**  Comienzan por <? Y terminan por ?>
* **Comentarios**  Información que no forma parte del documento. Comienzan por <!-- y terminan por -->
* **Declaraciones de tipo** Especifican información acerca del documento

```xml
<!DOCTYPE persona SYSTEM “persona.dtd”>
```

* **Secciones CDATA** Se trata de un conjunto de caracteres que no deben ser interpretados por el procesador

```xml
<![CDATA[ Aquí se puede meter cualquier carácter, como <, &, >, ... Sin que sean interpretados como marcación]]>
```

![XML Estructura](/Codigo/Semana%208/img/img_6.jpg)

Pueden descargar el XML Explorer para manejar XML de hasta 300 Megas. [Enlace](https://archive.codeplex.com/?p=xmlexplorer) para descarga.

## Algoritmo Minimax
Minimax es una especie de algoritmo de retroceso que se utiliza en la toma de decisiones y la teoría del juego para encontrar el movimiento óptimo para un jugador, asumiendo que su oponente también juega de manera óptima. Es ampliamente utilizado en juegos por turnos para dos jugadores como Tic-Tac-Toe, Backgammon, Mancala, Chess, etc.

En Minimax, los dos jugadores se denominan maximizador y minimizador. El maximizador intenta obtener la puntuación más alta posible mientras que el minimizador intenta hacer lo contrario y obtener la puntuación más baja posible.

Cada estado del tablero tiene un valor asociado. En un estado dado, si el maximizador tiene ventaja, la puntuación del tablero tenderá a ser algún valor positivo. Si el minimizador tiene la ventaja en ese estado del tablero, tenderá a ser un valor negativo. Los valores del tablero se calculan mediante algunas heurísticas que son únicas para cada tipo de juego.

El espacio de estados se representa mediante árboles alternados, donde:
* **Nodo** Representa una situación del juego
* **Sucesores de un nodo** Situaciones del juego a las que se accede por movimientos legales aplicando sus reglas
* **Nivel** Contiene todas las situaciones posibles para uno de los jugadores

El algoritmo Minimax es un procedimiento recursivo y el corte de la recursión está dado por alguna de las siguientes condiciones

* Gana algún jugador
* Se han explorado N capas, siendo N el límite establecido
* Se ha agotado el tiempo de exploración
* Se ha llegado a una situación estática donde no hay grandes cambios de un nivel a otro

### Pasos del Algoritmo Minimax

Generación del árbol de juego. Se generarán todos los nodos hasta llegar a un estado terminal

Cálculo de los valores de la función de utilidad para cada nodo terminal

Calcular el valor de los nodos superiores a partir del valor de los inferiores. Alternativamente se elegirán los valores mínimos y máximos representando los movimientos del jugador y del oponente, de ahí el nombre de **Minimax**.

Elegir la jugada valorando los valores que han llegado al nivel superior

El algoritmo explorará los nodos del árbol asignándoles un valor numérico mediante una función de utilidad, empezando por los nodos terminales y subiendo hacia la raíz. 

Colocar 0 ó 1 en los nodos terminales dependiendo si gana MIN o MAX.

La función de utilidad definirá lo buena que es la posición para un jugador cuando la alcanza.

Se requiere de una estrategia que garantice llegar a estados terminales ganadores independientemente de lo que haga el oponente.

Un valor positivo indica la ventaja de un jugador y uno negativo la ventaja del otro.

El jugador que espera valores positivos se conoce como **maximizador**.

El jugador que espera valores negativos se conoce como **minimizador**.

El __maximizador__ busca movimientos que lo conduzcan al mayor número positivo.

El __minimizador__ busca movimientos que lo conduzcan al menor número negativo.

### Ejemplo práctico
El algoritmo de minimax en simples palabras consiste en la elección del mejor movimiento para el computador, suponiendo que el contrincante escogerá uno que lo pueda perjudicar, para escoger la mejor opción este algoritmo realiza un árbol de búsqueda con todos los posibles movimientos, luego recorre todo el árbol de soluciones del juego a partir de un estado dado, es decir, según las casillas que ya han sido rellenadas. Por tanto, minimax se ejecutará cada vez que le toque mover a la IA.

Estado inicial: Es una configuración inicial del juego, es decir, un estado en el que se encuentre el juego. Para nuestro ejemplo sería:

![EstadoInicial](/Codigo/Semana%208/img/imagen1.png)

Operadores: Corresponden a las jugadas legales que se pueden hacer en el juego, en el caso del tres en raya no puedes marcar una casilla ya antes marcada.

![EstadoInicial](/Codigo/Semana%208/img/imagen3.png)

Condición Terminal: Determina cuando el juego se acabó, en nuestro ejemplo el juego termina cuando un jugador marca tres casillas seguidas iguales, ya se horizontalmente, verticalmente o en diagonal, o se marcan todas las casillas (empate).

![EstadoInicial](/Codigo/Semana%208/img/imagen4.png)

Función de Utilidad: Da un valor numérico a una configuración final de un juego. En un juego en donde se puede ganar, perder o empatar, los valores pueden ser 1, 0, o -1.

![EstadoInicial](/Codigo/Semana%208/img/imagen5.png)

Implementación Minimax: Los pasos que sigue minimax pueden variar, pero lo importante es tener una idea clara de cómo es su funcionamiento, los pasos a seguir son:

El algoritmo primero generar un árbol de soluciones completo a partir de un nodo dado. veamos el siguiente ejemplo

![EstadoInicial](/Codigo/Semana%208/img/imagen6.png)

Para cada nodo final, buscamos la función de utilidad de estos. En nuestro ejemplo usaremos un 0 para las partidas que terminen en empate, un 1 para las que gane la IA y un -1 para las que gane el jugador humano.

![EstadoInicial](/Codigo/Semana%208/img/imagen7.png)

Y lo que hará el algoritmo Minimax cuando vaya regresando hacia atrás, será comunicarle a la llamada recursiva superior cuál es el mejor nodo hoja alcanzado hasta el momento. Cada llamada recursiva tiene que saber a quién le toca jugar, para analizar si el movimiento realizado pertenece a la IA o al otro jugador, ya que cuando sea el turno de la IA nos interesa MAXIMIZAR el resultado, y cuando sea el turno del rival MINIMIZAR su resultado.

![EstadoInicial](/Codigo/Semana%208/img/imagen8.png)

Al final el algoritmo nos devolverá la jugada que debe realizar la máquina para maximizar sus posibilidades y bloquear las posibilidades del rival.

**Como práctica implemente su algoritmo de MiniMax para TicTacToe**


## License
[MIT](https://choosealicense.com/licenses/mit/)
