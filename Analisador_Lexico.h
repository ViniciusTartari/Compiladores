# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#include <ctype.h>


typedef struct lista 
{
    char word[20];
    char token[20];
    struct lista *prox;
}Lista;


char *strlwr(char *str) //converte pra minuscula
{
  unsigned char *p = (unsigned char *)str;

  while (*p) 
  {
     *p = tolower(*p);
      p++;
  }

  return str;
}

Lista* inicializa_lista(void)
{
    return(0);
}

Lista* insere(Lista *t, char word[20], char token[20])
{
    Lista *nodo;
    nodo = (Lista*)malloc(sizeof(Lista));
    strcpy(nodo->word, word); 
    strcpy(nodo->token, token); 
    nodo->prox = t;
    return(nodo);
}

Lista* arruma(Lista *t)
{
    Lista *aux; 

    aux = inicializa_lista();

    Lista *p;

    for(p = t; p != NULL; p = p->prox)
        aux = insere(aux, p->word, p->token);
    return(aux);
}

void imprime_lista(Lista *t)
{
    Lista *l;
    for(l = t; l != NULL; l = l->prox)
        printf("<%s>", l->token);
    printf("\n\n");
}
