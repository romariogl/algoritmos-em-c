#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Lista{
int id;
int idade;
struct Lista* prox;
} lista;

typedef struct Fila {
lista *inicio;
lista *fim;
} fila;




void insere(fila *fila, int idid, int idadeidade) {
lista *novo = malloc(sizeof(lista));
novo->id=idid;
novo->idade=idadeidade;
novo->prox=NULL;

  if(fila->inicio==NULL)
      fila->inicio=novo;
  else
    fila->fim->prox=novo;

fila->fim=novo;
    
}

int remover(fila *fila) {
  lista *aux = fila->inicio;

  if(fila->inicio==NULL)
    return 0;
  else
    fila->inicio = aux->prox;

  free(aux);
  return 1;
}

void imprimir(fila *fila1, fila *fila2) {
  lista *p=fila1->inicio, *q=fila2->inicio;

  printf("fila de idosos:\n");

  if(p==NULL) {
    printf("fila vazia!\n");
}
  else {
    for(;p!=NULL;p=p->prox)
     printf("ID: %d IDADE: %d\n", p->id, p->idade);
}
     printf("fila de nao-idosos:\n");

  if(q==NULL) {
    printf("fila vazia!\n");
}
  else {
    for(;q!=NULL;q=q->prox)
     printf("ID: %d IDADE: %d\n", q->id, q->idade);
}
    printf("----------\n\n");
}


int main(){

    char escolha;
    int n, aux, id, idade;

    scanf("%d", &n);
    aux = n;
    fila *fila1 = malloc(sizeof(fila));
    fila *fila2 = malloc(sizeof(fila));
    fila1->inicio=NULL;
    fila1->fim=NULL;
    fila2->inicio=NULL;
    fila2->fim=NULL;

    scanf("%c", &escolha);

  while(escolha!='f') {
      switch(escolha) {
         case 'a':
           scanf("%d %d", &id, &idade);
           if(idade>60)
             insere(fila1, id, idade);
           else
             insere(fila2, id, idade);
           break;
         case 'r':
           if(aux>0) {
             if(remover(fila1))
             aux--;
             else
             remover(fila2);
             }
           else {
             if(remover(fila2))
             aux=n;
             else
             remover(fila1);
           }
           break;
         case 'i':
           imprimir(fila1, fila2);
           break;
         case 'f':
           break;
     }
     scanf("%c", &escolha);
     }
    return 0;
    }