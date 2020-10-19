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




| FE nodo actual | FE del nodo derecho | FE del nodo izquierdo | Rotación
| ------------- | ------------- | ------------- | ------------- |
| -2  | No Importa  | -1 | RSD
| -2  | No Importa  | 1 | RDD
| 2  | -1  | No Importa | RDI
| 2  | 1  | No Importa | RSI




```c++

```






## License
[MIT](https://choosealicense.com/licenses/mit/)
