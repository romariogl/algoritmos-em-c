#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Lista{
    int info;
    struct Lista* prox;
}lista;

int chaves(int k, int m) {
return k%m;
}

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
    if((novo->info)<=(p->info)) {
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

lista *remover(lista *ref, int n, int *qtd) {
lista *p, *ant;

for(p=ref, ant=NULL; p!=NULL; ant=p, p=p->prox) {
  if((p->info)==n){
      *qtd=(*qtd)-1;
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
         }
  if((p->info)>n) break;

}
return ref;
         }

void imprimir(lista *ref) {
lista *p=ref;
if(p==NULL) {
printf("Lista vazia!\n");
}
else {
  for(p=ref;p!=NULL;p=p->prox)
     printf("%d=>", p->info);
  printf("\n");
  }
  }

void procurar(lista *ref, int valor, int qtd_ele_tab) {
int elementos=0;
lista *p=ref;

if(p==NULL) {
     printf("BUSCA POR %d\n", valor);
     printf("numero de elementos da tabela hash: %d\n", qtd_ele_tab);
     printf("elemento nao encontrado!\n");
     printf("numero de elementos acessados na tabela hash: %d\n", elementos);
     return;
}
  elementos=1;

  while((p!=NULL)&&(p->info!=valor)) {
   elementos++;
   p=p->prox;
}
    if(p==NULL) {
     printf("BUSCA POR %d\n", valor);
     printf("numero de elementos da tabela hash: %d\n", qtd_ele_tab);
     printf("elemento nao encontrado!\n");
     printf("numero de elementos acessados na tabela hash: %d\n", elementos-1);
     return;
}
    if((p->info)==valor) {
     printf("BUSCA POR %d\n", valor);
     printf("numero de elementos da tabela hash: %d\n", qtd_ele_tab);
     printf("elemento %d encontrado!\n", valor);
     printf("numero de elementos acessados na tabela hash: %d\n", elementos);
}}

int main(){
    lista** tabela;
    char escolha='w';
    int m, i, j, k, qtd_ele_tab=0;
    scanf("%d", &m);
    tabela = (lista**)malloc(sizeof(lista*)*m);

    for(i=0;i<m;i++)
      tabela[i] = NULL;

    while(escolha!='f') {
      scanf("%c", &escolha);
      switch(escolha)
      {
         case 'a':
           scanf("%d", &k);
           tabela[chaves(k, m)]=insere(tabela[chaves(k, m)], k);
           qtd_ele_tab++;
           break;
         case 'r':
           scanf("%d", &k);
           tabela[chaves(k, m)]=remover(tabela[chaves(k, m)], k, &qtd_ele_tab);
           break;
         case 'i':
           printf("imprimindo tabela hash:\n");
           for(j=0; j<m; j++) {
              printf("[%d]:", j);
              imprimir(tabela[j]);
              }
           break;
         case 'p':
           scanf("%d", &k);
           procurar(tabela[chaves(k, m)], k, qtd_ele_tab);
           break;
}}
    return 0;
}