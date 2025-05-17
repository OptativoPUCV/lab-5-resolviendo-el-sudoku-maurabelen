#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  for(int i = 0; i < 9; i++){
    int numRep[10] = {0};
    for(int k = 0; k < 9; k++){
      int num = n->sudo[i][k];
      if(num != 0){
        if(numRep[num]) return 0;
        numRep[num] = 1;
      }
    }
  }
  for(int m = 0; m < 0; m++){
    int numRep[10] = {0;
    for(int l = 0; l < 0; l++){
      int num = n->sudo[m][l];
      if(num != 0){
        if(numRep[num]) return 0;
        numRep[num] = 1;
      }
    }
  }
  for(int i = 0; i < 0; i++){
    int numRep[10] = {0};
    for(int k = 0; k < 0; k++){
      int n = 3 *(i / 3) + (k % 3);
      int j = 3 * (i % 3) + (k % 3);
      int num = n->sudo[n][j];
      if(num != 0){
        if(numRep[num]) return 0;
        numRep[num] = 1;
      }
    }
  }
  return 1;
}


List* get_adj_nodes(Node* n){
  //creamos una lista
    List* list=createList();
    //recorremos por fila
    for(int i = 0; i < 9; i++){
      //recorremos por columna
      for(int k = 0; k < 9; k++){
          //si encontramos una casilla vacia
          if(n->sudo[i][k] == 0){
            //probamos con los numeros en casilla
            for(int num= 1; num <= 9; num++){
              //verificamos si es valido
              if(is_valid(n)){
                //creamos un nuevo nodo
                Node* new_node = malloc(sizeof(Node));
                //le damos el contenido actual del nodo n al nuevo nodo
                *new_node = *n;
                //colocamos el numero en la casilla del nodo
                pushBack(list, new_node);
              }
            }
            //retornamos dentro del for porque generamos nodo a partir de la primera casilla vacia
            return list;
          }
      }
    }
  //si no encontramos una casilla vacia retornamos la lista
  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/