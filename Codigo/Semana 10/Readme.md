# Algoritmos de rutas cortas

## Algortimo de PRIM

   Prim (Grafo G)
       /* Inicializamos todos los nodos del grafo. 
       La distancia la ponemos a infinito y el padre de cada nodo a NULL
        Encolamos, en una cola de prioridad 
                  donde la prioridad es la distancia, 
               todas las parejas <nodo,distancia> del grafo*/
       por cada u en V[G] hacer
           distancia[u] = INFINITO
           padre[u] = NULL
           Añadir(cola,<u,distancia[u]>)
       distancia[u]=0
       mientras !esta_vacia(cola) hacer
           // OJO: Se entiende por mayor prioridad aquel nodo cuya distancia[u] es menor.
           u = extraer_minimo(cola) //devuelve el minimo y lo elimina de la cola.
           por cada v adyacente a 'u' hacer
               si ((v ∈ cola) && (distancia[v] > peso(u, v)) entonces
                   padre[v] = u
                   distancia[v] = peso(u, v)
                   Actualizar(cola,<v,distancia[v]>)


```c++
// Dados un grafo G, sus pesos W y el número de nodos n devuelve el coste del árbol mínimo
// generador usando el algoritmo de Prim
int Prim (vvi& G, vvi& W, int n){
    vector <bool> vis(n, false); //nodos visitados, inicialmente ninguno
    priority_queue <ii> Q; //cola de prioridad de parejas de enteros (-distancia del nodo a F, nodo)
    Q.push({-0,0}); //introducimos un nodo cualquiera (a distancia 0 de él mismo)
    int answer = 0; 

    while (not Q.empty()){
        ii arc = Q.top() //arco con menor peso desde F hasta G\F 
        Q.pop(); //lo quitamos de la cola

        int v = arc.second; //vértice de Q a menor distancia de F
        int p = -arc.first; //distancia entre F y v

        if (not vis[v]){ //si no lo hemos visitado
            vis[v] = true;
            answer += p;

            for (int i = 0; i < G[v].size(); ++i){ //miramos sus vecinos
                int u = G[v][i];
                int w = W[v][i];

                Q.push({-w, u}); // añadimos los vecinos conectados con u
            }
        }   
    }

    return answer; // devolvemos el coste
}
```


## Algortimo de Kruscal

### Implementación en C++

```c++
#include <iostream>
#include <cstdlib>


using namespace std;

struct arco {
    //char destino;
    struct vertice *destino;
    int costo;
    bool perteneceAEM;//=false;
    struct arco *sigA;
};

struct vertice{
    char ciudad;
    struct vertice *sigV;
    struct arco *sigA;
    bool visitado;
}*grafo;

struct lista{
    char origen;
    struct arco* enlace;
    struct lista* sig;
}*primero;

int contV=0;

void imprimir(){
    cout<<endl;
    struct lista * temp= primero;
        while(temp!=NULL){
            cout<<temp->enlace->costo <<" ";
            temp=temp->sig;
        }
    cout<<endl<<"Cantidad de vertices: "<< contV;
}
//inserta ordenado la lista de arcos de menor a mayor
void insertarOrdenado(char O, struct arco *parco){

    struct lista *nnl = new lista();
    nnl->origen= O;
    nnl->enlace= parco;
    nnl->sig=NULL;

    if(primero ==NULL){
        primero = nnl;
    }
    else{
            if(parco->costo<=primero->enlace->costo){
                nnl->sig = primero;
                primero = nnl;
            }
            else{
                struct lista * temp = primero;
                struct lista * ant = NULL;
                while (temp != NULL){
                    if(temp->enlace->costo > parco->costo){
                        ant = temp;
                        temp = temp->sig;
                    }
                    else break;

                }
                if(ant!=NULL)
                ant->sig= nnl;
                if(temp!=NULL)
                nnl->sig=temp;
            }
    }
}

//insercion de vertices
//insercion al inicio de la lista
void insertar(char pciudad){

struct vertice *nnv = new vertice();
nnv->ciudad=pciudad;
nnv->visitado =false;

nnv->sigV=grafo;
grafo =nnv;
}
//busca un vertice
struct vertice* buscar(char pciudad){

    struct vertice *tempV = grafo;
    while(tempV!=NULL){

        if(tempV->ciudad==pciudad)
            return tempV;

        tempV=tempV->sigV;

    }
    return NULL;
}
//////////////inserta ARCOS///////////

//insercion al inicio de la sublista del vertice origen
void insertar(char porigen,char pdestino, int pcosto){

    struct vertice *origen =buscar (porigen);
    struct vertice *destino =buscar (pdestino);
    if((origen ==NULL )||(destino ==NULL)){
        cout << "Datos inconsistentes\n";
        return;
    }

    struct arco *nna = new arco();
    nna->destino=destino;
    nna->costo=pcosto;
    nna->sigA =origen->sigA;
    origen->sigA=nna;
}
void amplitud(){
    if(grafo==NULL)
    {  cout<<"No hay grafo";
        return;
    }
    struct vertice *tempV=grafo;
    struct arco *tempA;
    while(tempV!=NULL)
    {
        contV++;
        tempA=tempV->sigA;
        while(tempA!=NULL)
        {
            insertarOrdenado(tempV->ciudad, tempA);
            cout <<tempV->ciudad <<tempA->destino->ciudad <<tempA->costo <<" ";
            tempA=tempA->sigA;

        }
        tempV=tempV->sigV;
    }
}

void imprimeArbolEM(){
    if(grafo==NULL)
    {  cout<<"No hay grafo";
        return;
    }
    struct vertice *tempV=grafo;
    struct arco *tempA;
    while(tempV!=NULL)
    {

        tempA=tempV->sigA;
        while(tempA!=NULL)
        {
            if(tempA->perteneceAEM)
                cout <<tempV->ciudad <<tempA->destino->ciudad <<tempA->costo <<" ";
            tempA=tempA->sigA;

        }
        tempV=tempV->sigV;
    }
}
//recorrido en profundidar (por rutas)

void profundidad(struct vertice * grafo){

    if(grafo==NULL)
        return;

    if(grafo->visitado==true)
        return;

    grafo->visitado =true;

    struct arco *tempA=grafo->sigA;

    while (tempA!=NULL){
        cout <<grafo->ciudad <<tempA->destino->ciudad <<tempA->costo <<" ";
        profundidad(tempA->destino);
        tempA=tempA->sigA;
    }
}
bool e=false;

void existe_ruta(struct vertice *vorigen,struct vertice *vdestino){
    if((vorigen==NULL)||(vorigen->visitado ==true))
        return;

    if (vorigen==vdestino){
        e=true;
        return;
    }


    vorigen->visitado=true;
    struct arco *tempA=vorigen->sigA;
    while(tempA!=NULL){
        if(tempA->perteneceAEM==true)
            existe_ruta(tempA->destino,vdestino);
        tempA=tempA->sigA;

    }

}
//buscar ruta
bool ruta(char porigen, char pdestino){
    struct vertice *vorigen =buscar(porigen);
    struct vertice *vdestino =buscar(pdestino);
    if((vorigen ==NULL )||(vdestino ==NULL)){
            cout << "Datos inconsistentes\n";
            return false;
        }

    existe_ruta(vorigen,vdestino);
   /* if(e ==true)
        cout <<"Si existe ruta\n";
    else
        cout <<"No existe ruta\n";
        */
return e;
}
void desmarcar(){
struct vertice *tempV = grafo;

    while(tempV!=NULL){
        tempV->visitado=false;
        tempV=tempV->sigV;

    }
}

void kruskal(){
    int i=1;
    while(i<contV){

        while(true){
            desmarcar();
            if(primero==NULL)
                return;
            e=false;
            if(ruta(primero->origen, primero->enlace->destino->ciudad)){
                primero =primero->sig;
                //arco descartado
            }
            else{
                    primero->enlace->perteneceAEM=true;
                    cout<<primero->origen<<primero->enlace->destino->ciudad<<primero->enlace->costo<<" ";
                    primero=primero->sig;
                    break;
            }
        }
    i++;
    }

}

int main()
{
    insertar('H');
    insertar('F');
    insertar('E');
    insertar('D');
    insertar('C');
    insertar('B');
    insertar('A');
    insertar('A','C',8);
    insertar('A','D',7);
    insertar('A','B',8);

    insertar('B','C',4);

    insertar('C','D',3);
    insertar('D','E',1);
    insertar('D','H',2);
    insertar('E','F',0);
    insertar('F','H',0);


    cout<<"\n \n ////////////Amplitud/////////// \n";
    amplitud();
    imprimir();
    cout<<"\n \n ////////////Arbol expansion minima/////////// \n";
    kruskal();
    //imprimeArbolEM();
   // desmarcar();

    cout << "" << endl;
    system("pause");
    return 0;
}

```

### Algortimo de Dijkstra

```c++
//Dijkstra
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

#define N 5 //maximo numero de vértices
#define nodo pair< int , int > //definimos el nodo como un par( first , second ) donde first es el vertice adyacente y second el peso de la arista
#define INF 99

using namespace std;
//La cola de prioridad de C++ por default es un max-Heap (elemento de mayor valor en el tope)
//por ello es necesario realizar nuestro comparador para que sea un min-Heap
struct cmp {
    bool operator() ( const nodo &a , const nodo &b ) {
        return a.second > b.second;
    }
};

int matriz[N][N]; //matriz de adyacencia
bool visitado[N];      //para vértices visitados
int distancia[N];
priority_queue< nodo , vector<nodo> , cmp > Q; //priority queue propia del c++, usamos el comparador definido para que el de menor valor este en el tope

void cargarDatos(){
	for(int i=0; i< N; i++)
		for(int j= 0; j < N; j++)
			matriz[i][j]= INF;
	
	matriz[2][3] = 5;
	matriz[1][2] = 2;
	matriz[2][1] = 14;
	matriz[0][2] = 8;
	matriz[0][1] = 3;
	matriz[3][4] = 4;
	matriz[4][1] = 1;
	matriz[3][1] = 4;
}
//función de inicialización
void inicializar(){
    for( int i = 0 ; i <= N ; ++i ){
        distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
        visitado[ i ] = false; //inicializamos todos los vértices como no visitados  
    }
}
void Dijkstra( int inicio){
	inicializar();
	
	Q.push( nodo( inicio , 0 ) ); //Insertamos el vértice inicial en la Cola de Prioridad
    distancia[ inicio ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    int actual , adyacente , peso;
    while( !Q.empty() ){                   //Mientras cola no este vacia
        actual = Q.top().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        Q.pop();                           //Sacamos el elemento de la cola
        if( visitado[ actual ] ) 
			continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        
		visitado[ actual ] = true;         //Marco como visitado el vértice actual

        for( int i = 0 ; i < N ; ++i ){ //reviso sus adyacentes del vertice actual
            if(matriz[actual][i] != INF){
	            peso = matriz[actual][i]  ;        //peso de la arista que une actual con adyacente ( actual , adyacente )
	            if( !visitado[ i ] ){        //si el vertice adyacente no fue visitado
	               
	            	if( distancia[ actual ] + matriz[actual][i] < distancia[ i ] ){
				        distancia[ i ] = distancia[ actual ] + matriz[actual][i];  //relajamos el vertice actualizando la distancia
				        Q.push( nodo( i , distancia[ i ] ) ); //agregamos adyacente a la cola de prioridad
    				}
				
				}
        	}
        }
    }

}
void imprimir(){
	
	int i,j;
	for(i=0; i< N; i++){
		for(j= 0; j < N; j++)
			cout<<matriz[i][j]<<"  ";
		cout<<endl;
	
	}
}
void imprimirDistancias(){
	for(int i=0; i< N; i++)
		cout<<distancia[ i ] <<", ";
}
int main(int argc, char** argv) {
	cargarDatos();
	cout<<"Grafo............\n";
	imprimir();
	
	int inicio = 0;
	Dijkstra(inicio);
	cout<<"Grafo.ruta corta...........\n";
	imprimirDistancias();
	return 0;
}
```



## License
[MIT](https://choosealicense.com/licenses/mit/)
