#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore{
    struct Arvore* esquerda;
    int info;
    struct Arvore* direita;
    struct Arvore* lateral;
}arvore;

void ordenacao(arvore *raiz) {
  arvore *p, *q;
  if(raiz==NULL) return;

  if(raiz->esquerda!=NULL&&raiz->direita!=NULL) {
    p=raiz->esquerda;
    p->lateral=raiz->direita;

    p=raiz->direita;
    q=raiz->lateral;

    if(q==NULL) {
      p->lateral=NULL;

      ordenacao(raiz->direita);
      ordenacao(raiz->esquerda);

      return;

      }
    else {
      while(q!=NULL&&q->esquerda==NULL&&q->direita==NULL)
        q=q->lateral;

      if(q==NULL)
         p->lateral=NULL;
      else {
      if(q->esquerda!=NULL)
        p->lateral=q->esquerda;
      else if(q->direita!=NULL)
        p->lateral=q->direita;
        }
     ordenacao(raiz->direita);
     ordenacao(raiz->esquerda);

      return;
}}


  if(raiz->esquerda!=NULL&&raiz->direita==NULL) {
    p=raiz->esquerda;
    q=raiz->lateral;
    if(q==NULL) {
        p->lateral=NULL;

        ordenacao(raiz->direita);
        ordenacao(raiz->esquerda);

        return;
     }
    else {
      while(q!=NULL&&q->esquerda==NULL&&q->direita==NULL)
        q=q->lateral;
      if(q==NULL)
         p->lateral=NULL;
      else {
        if(q->esquerda!=NULL)
          p->lateral=q->esquerda;
        else if(q->direita!=NULL)
          p->lateral=q->direita;
}
        ordenacao(raiz->direita);
        ordenacao(raiz->esquerda);
        return;
}}

  if(raiz->esquerda==NULL&&raiz->direita!=NULL) {
    p=raiz->direita;
    q=raiz->lateral;
    if(q==NULL) {
      p->lateral=NULL;
      ordenacao(raiz->direita);
      ordenacao(raiz->esquerda);
      return;
}




    else {
       p=raiz->direita;
       q=raiz->lateral;
      while(q!=NULL&&q->esquerda==NULL&&q->direita==NULL)
        q=q->lateral;
      if(q==NULL)
         p->lateral=NULL;
      else {
        if(q->esquerda!=NULL)
          p->lateral=q->esquerda;
        else if(q->direita!=NULL)
          p->lateral=q->direita;
}
        ordenacao(raiz->direita);
        ordenacao(raiz->esquerda);

        return;
}}}

arvore *insere(arvore *raiz, int n) {
  arvore *novo;

  if(raiz==NULL) {
    novo=malloc(sizeof(arvore));
    novo->info=n;
    novo->direita=NULL;
    novo->esquerda=NULL;
    novo->lateral=NULL;
    raiz=novo;
          }

  else {
    if(n<raiz->info)
     raiz->esquerda = insere(raiz->esquerda, n);
    else if(n>raiz->info)
      raiz->direita = insere(raiz->direita, n);
    else if(n==raiz->info&&raiz->esquerda==NULL) raiz->esquerda = insere(raiz->esquerda, n);
}   return raiz;
  }

arvore *remover(arvore *raiz, int n) {
  arvore **p, *q, **r, *a;
  int aux;

  if(raiz==NULL) return raiz;
  if(n<raiz->info) raiz->esquerda = remover(raiz->esquerda, n);
  if(n>raiz->info)  raiz->direita = remover(raiz->direita, n);

   if(raiz->info==n){

    if(raiz->esquerda==NULL&&raiz->direita==NULL) {
       p=&raiz;
       a=raiz;
       *p=NULL;
       free(a);
       }

    else if(raiz->esquerda!=NULL&&raiz->direita==NULL) {
        p=&raiz;
        a=raiz;
        *p=raiz->esquerda;
        free(a);
         }

    else if(raiz->esquerda==NULL&&raiz->direita!=NULL) {
         p=&raiz;
         a=raiz;
         *p=raiz->direita;
         free(a);
            }

    else if(raiz->esquerda!=NULL&&raiz->direita!=NULL) {
      p=&raiz;
      q=raiz->direita;
      r=&raiz->direita;
      while(q->esquerda!=NULL) {
        r=&q->esquerda;
        q=q->esquerda;
              }
        aux=q->info;
      if(q->direita==NULL) {
         *r=NULL;
         free(q);
}
       else if (q->direita!=NULL){
        (*r)=q->direita;
        free(q);
        }
       (*p)->info=aux;
          }}
 return raiz;
}

void pre_ordem(arvore *raiz) {
  if(raiz!=NULL) {
    printf("%d ", raiz->info);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}}

void nivel(arvore *raiz) {
  int i=1;
  arvore *p, *q;
    while(raiz!=NULL) {
      printf("nivel %d:\n", i);
      for(p=raiz; p!=NULL; p=p->lateral)
        printf("%d ", p->info);
      printf("\n");
      i++;
      q=raiz;
      while(q!=NULL&&q->esquerda==NULL&&q->direita==NULL)
        q=q->lateral;
      if(q==NULL)
        raiz=NULL;
      else if(q->esquerda!=NULL)
        raiz=q->esquerda;
      else if(q->direita!=NULL)
        raiz=q->direita;
        }

    }

int main(){
    char escolha='w';
    int n;
    arvore *raiz=NULL;

    while(escolha!='q') {
      scanf("%c", &escolha);
      switch(escolha)
      {
         case 'i':
           scanf("%d", &n);
           raiz=insere(raiz, n);
           ordenacao(raiz);
           printf("pre-ordem:");
           pre_ordem(raiz);
           printf("\n");
           nivel(raiz);
           printf("\n");
           break;
         case 'r':
           scanf("%d", &n);
           raiz=remover(raiz, n);
           ordenacao(raiz);
           printf("pre-ordem:");
           pre_ordem(raiz);
           printf("\n");
           nivel(raiz);
           printf("\n");
           break;
         case 'q':
           scanf("%d", &n);
           break;

}}
    return 0;
}