#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Lista{
int info;
struct Lista* prox;
} lista;

lista *insere(lista *ref, int n) {
lista *novo = malloc(sizeof(lista));
novo->info=n;
lista *p, *ant;
if(ref==NULL){
novo->prox=NULL;
ref=novo;
}

else {
  for(p=ref, ant=NULL; p!=NULL; ant=p, p=p->prox) {
    if((novo->info)<(p->info)) {
      if(p==ref){
      novo->prox=ref;
      ref=novo;
      break;
    }
      else{
      novo->prox=p;
      ant->prox=novo;
      break;
      }}}

      if(p==NULL){
      ant->prox=novo;
      novo->prox=NULL;
      }}
return ref;
}

lista *remover(lista *ref, int n) {
lista *p, *ant;

for(p=ref, ant=NULL; p!=NULL; ant=p, p=p->prox) {
  if((p->info)==n){
      if(p==ref){
         ref=p->prox;
         free(p);
         break;
         }
      else {
         ant->prox=p->prox;
         free(p);
         break;
         }
         }}
return ref;
         }

lista *remove_maior(lista *ref, int n) {
int i=0;
lista *q, *p, *ant;
for(q=ref; q!=NULL; q=q->prox) {
if((q->info)>n) i++;
}

while(i!=0) {
for(p=ref, ant=NULL; p!=NULL; ant=p, p=p->prox) {
  if((p->info)>n){
      if(p==ref){
         ref=p->prox;
         free(p);
         break;
         }
      else {
         ant->prox=p->prox;
         free(p);
         break;
         }
         }}
i--;
         }
         return ref;
         }

void imprimir(lista *ref) {
lista *p=ref;
printf("Imprimindo a lista:\n");
if(p==NULL) {
printf("Lista vazia!\n");
}
else {
  for(p=ref;p!=NULL;p=p->prox)
     printf("%d=>", p->info);
  printf("\n");
    
}}


int main(){

    char escolha;
    int n;
    scanf("%c", &escolha);
    lista *ref=NULL;
    while(escolha!='f') {
      switch(escolha)
      {
         case 'a':
           scanf("%d", &n);
           ref=insere(ref, n);
           break;
         case 'r':
           scanf("%d", &n);
           ref=remover(ref, n);
           break;
         case '>':
           scanf("%d", &n);
           ref=remove_maior(ref, n);
           break;
         case 'i':
           imprimir(ref);
           break;
         case 'f':
           break;
     }
     scanf("%c", &escolha);
     }
    return 0;
    }