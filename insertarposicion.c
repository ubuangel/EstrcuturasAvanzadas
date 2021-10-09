
/*Insert a node at a specific position in a linked list */

/*https://www.youtube.com/watch?v=0hGxILnKvJk*/
#include<stdio.h>

#include<stdlib.h>

struct nodo{

 int dato;

 struct nodo *link;

};



    struct nodo *agregar_pos_final(struct nodo *ptr, int dato){

    struct nodo *temp= malloc(sizeof(struct nodo));

 temp->dato = dato;

 temp->link = NULL;

    ptr->link = temp;

    return temp;

}

void agregar_pos(struct nodo **head, int dato, int pos){

 struct nodo *ptr = *head;

 struct nodo *ptr2 = malloc (sizeof(struct nodo));

 ptr2->dato = dato;

 ptr2->link = NULL;

 if(pos==1)

 {

     ptr2->link=ptr;

     *head=ptr2;

 }

 else {

     pos--;

 while(pos != 1){

  ptr = ptr->link;

  pos--;

 }

 ptr2->link = ptr->link;

 ptr->link = ptr2;

}

 }

int main()

{

  struct nodo *head = malloc(sizeof(struct nodo));

 head->dato = 45;

 head->link = NULL;

 struct nodo *ptr = head;

 ptr= agregar_pos_final(ptr, 98);

 ptr= agregar_pos_final(ptr, 3);

 ptr= agregar_pos_final(ptr, 88);

 ptr = head;

    int dato = 76, posicion =1;

 agregar_pos(&head, dato, posicion);

 struct nodo *ptr1 = head;

 while(ptr1 != NULL){

        printf("%d ", ptr1->dato);

        ptr1=ptr1->link;

 }

 return 0;

}
