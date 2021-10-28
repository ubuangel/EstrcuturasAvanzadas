/*
 * proyect.cpp
 *
 *  Created on: 21 ago. 2020
 *      Author: angel
 */


#include<iostream>
#include<vector>
#include <stdlib.h>
#include <stdio.h>
//#include <bits/>

//us//ading namespace std;
//using namespace std
//aver;

struct nodo{//para almacenar los vertices
	int vertice;
struct	nodo *siguiente;

};
struct nodo *crearnodo (int);

struct grafo{//para organizar los nodos
	int numVer;
	struct nodo **adjlist;//?ojo

};

struct nodo *crearnodo(int v){
	struct nodo*nuevonodo=malloc(sizeof(struct nodo));
	nuevonodo->vertice=v;
	nuevonodo->siguiente=NULL;
	return nuevonodo;
}
struct grafo *creargrafo(int vertices){
	struct grafo*graf=malloc(sizeof(struct grafo));
	graf->numVer=vertices;
	graf->adjlist=malloc(vertices*sizeof(struct nodo*));
	int i;
	for (i = 0; i < vertices; ++i) {
		graf->adjlist[i]=NULL;


	}
	return graf;
}
void agregararcos(struct grafo *graf,int s,int d){
	// agegar archo de s to d
	struct nodo *nuevonodo=crearnodo(d);
	nuevonodo->siguiente=graf->adjlist[s];
	graf->adjlist[s]=nuevonodo;

	//agregar  arco de d a s
	nuevonodo =crearnodo(s);
	nuevonodo->siguiente=graf->adjlist[d];
	graf->adjlist[d]=nuevonodo;





}
void cola(){

}
void encolar(){

}
void pop(){

}
//lista de adyacencia
void bfs(grafo graf,nodo s){
	//recorremos todos los vertices del grafo inicalizandolo en no visitado
	//distancia infinita y padre de cada nodoNULL;

	for (int i = 0;i<vertices;i++) {
		graf->adjlist[i]=NULL;

		estado[u]=Novisitado;
		distancia[u]=infinito;
		padre[u]=NULL;

	}

	estado[s]=visitado;
	distancia[s]=0;
	padre[s]=NULL;
	crearcola(Q);/*nos aseguramos que la cola este vacia*/
	encolar(Q,s);
	while(vacio Q){
		//extraeos el nodo q de la cola Q	 y exploramos todos sus nodos adyacentes
		u=extraer(Q);
		for v adjlist[u]{
			if estado[v]==novisitado;
					estadp[v]=Visitado;
			distancia[v]=distancia[v]+1;
			padre[v]=u;
			encolar(Q,v);

		}
	}
}





void imprimirgrafo(struct grafo* graf){
	int v;
	for (v = 0; v < graf->numVer; ++v) {
		struct nodo *temp=graf->adjlist[v];
		printf("\n numero de vertices %d\n",v);
		while(temp){
		printf("%d--->",temp->vertice);
		temp=temp->siguiente;


		}
		printf("\n");
	}

}

int main(){
struct grafo *graf=creargrafo(4);
agregararcos(graf,0,1);
agregararcos(graf,0,2);
agregararcos(graf,0,3);
agregararcos(graf,1,2);
imprimirgrafo(graf);

//	cout<< <<endl;
return 0;
	//cout<< <<"\n";

	}

