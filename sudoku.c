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
    for(int i=0; i<9; i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  //recorremos cada fila
  for(int i = 0; i < 9; i++){
    //se crea el arreglo para regristrar un numero del 1 al 9
    int numRep[10] = {0};
    //recorre cada calumna de la fila actual
    for(int k = 0; k < 9; k++){
      //obtenemos el numero de la celda
      int num = n->sudo[i][k];
      //si la celda no esta vacia
      if(num != 0){
        //si el numero ya aparecio en esta fila, es invalido
        if(numRep[num]) return 0;
        //marcamos el nunero como visto
        numRep[num] = 1;
      }
    }
  }
  //recorremos las columnas 
  for(int m = 0; m < 9; m++){
    //creamos un arreglo 
    int numRep[10] = {0};
    //recorremos las filas de la columna
    for(int l = 0; l < 9; l++){
      int num = n->sudo[l][m];
      //si el numero no es 0
      if(num != 0){
        if(numRep[num]) return 0;
        numRep[num] = 1;
      }
    }
  }
  //recorremos los 9 cuadrados, cada uno es un indice 
  for(int i = 0; i < 9; i++){
    int numRep[10] = {0};
    //creamo un arreglo para ver si un numero ya aparecio en el subcuadro
    for(int k = 0; k < 9; k++){
      //creamos m y j que son la fila y columna dentro del tablero 
      int m = 3 *(i / 3) + (k / 3); // fila
      int j = 3 * (i % 3) + (k % 3); //columna
      //obtenemos la posicion en el sudoku
      int num = n->sudo[m][j];
      //si ya esta en el subcuadro, el sudoku es invalido
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
              //creamos un nuevo nodo
              Node* new_node = malloc(sizeof(Node));
              //le damos el contenido actual del nodo n al nuevo nodo
              *new_node = *n;
              //colocamos el numero en la casilla del nodo
              new_node->sudo[i][k] = num;
              // Verificamos si el nuevo nodo es válido
              if (is_valid(new_node)) {
              pushBack(list, new_node);
              } else {
              free(new_node); // si no es válido, liberamos la memoria
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
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (n->sudo[i][j] == 0) return 0; // aún hay celdas vacías
    }
  }
  return 1; // no hay ceros, es un nodo final
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