#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>

#define MAX 10

//GENERICO---GENERICO---GENERICO---GENERICO---GENERICO---GENERICO---GENERICO---GENERICO---GENERICO
//-----------------------------------------------------------------------------------------------*/
typedef struct Item
{
    char palavra[MAX];
}TItem;

//-----------------------------------------------------------------------------------------------*/

typedef struct Nodo
{
    char palavra[MAX];
    struct Nodo *prox;
}Nodo;

/*-----------------------------------------------------------------------------------------------*/

Nodo* cria_nodo (char *palavra)
{

    Nodo *nodo;

    nodo = (Nodo*) malloc (sizeof(Nodo));

    strcpy(nodo->palavra, palavra);
    nodo->prox = NULL;

    return (nodo);
}
/*-----------------------------------------------------------------------------------------------*/
//FILA---FILA---FILA---FILA---FILA---FILA---FILA---FILA---FILA---FILA---FILA---FILA
/*-----------------------------------------------------------------------------------------------*/
typedef struct Fila
{
    Nodo *inicio;
    Nodo *final;
}Fila;

/*-----------------------------------------------------------------------------------------------*/

void inicializa_fila (Fila *f) 
{
    f->inicio = NULL;
    f->final = NULL;

}

/*-----------------------------------------------------------------------------------------------*/

void enfilera (Fila *f, Nodo *novo) 
{
    if (novo == NULL)
        printf("Fila Cheia, não há memória disponível!\n");
    else {

        if (f->final == NULL) 
        {
            f->inicio = novo;
            f->final = novo;
        }
        else 
        {
            f->final->prox = novo;
            f->final = novo;
        }
    }
}

/*-----------------------------------------------------------------------------------------------*/

void desenfilera (Fila *f) 
{
    Nodo* t;

    if (f->inicio == NULL)
        printf("Fila vaziaa\n");
    else 
    {
        t = f->inicio;
        f->inicio = f->inicio->prox;

        if (f->inicio == NULL)
            f->final = NULL;
        free(t);
        t = NULL;
    }
}

/*-----------------------------------------------------------------------------------------------*/

void imprime_fila (Fila *f) 
{
    Nodo *t;
    
    t = f->inicio;
    
    if (t == NULL)
        printf("Fila Vazia!\n");
    else 
    {
        while(t!= f->final)
        {
            printf("%s ", t->palavra);
            t = t->prox;
        }
        printf("%s ", t->palavra);
    }
}

/*-------------------------------------------------------------------------------------------------*/

void imprime_first (Fila *f) 
{
    printf("%s ", f->inicio->palavra);
}

/*-------------------------------------------------------------------------------------------------*/

void imprime_end (Fila *f) 
{
    printf("%s ", f->final->palavra);
}

//-----------------------------------------------------------------------------------------------*/
//PILHA---PILHA---PILHA---PILHA---PILHA---PILHA---PILHA---PILHA---PILHA---PILHA---PILHA---PILHA
//-----------------------------------------------------------------------------------------------*/

typedef struct Pilha
{
    Nodo *topo;
}Pilha;

//-----------------------------------------------------------------------------------------------*/

void inicializa_pilha (Pilha *p)
{
    p->topo = NULL;
}

//-----------------------------------------------------------------------------------------------

void empilha (Pilha *p, Nodo *novo)
{

    if (novo == NULL)
        printf("Pilha Cheia, não há memória disponível!\n");
    else
    {
        if (p->topo == NULL)
            p->topo = novo;
        else 
        {
            novo->prox = p->topo;
            p->topo = novo;
        }
    }

}

//-----------------------------------------------------------------------------------------------

void desempilha (Pilha *p)
{
    Nodo* t;

    if (p->topo == NULL)
        printf("Pilha vazia\n");
    else
    {
        t = p->topo;
        p->topo = p->topo->prox;

        free(t);
        t = NULL;
    }
}

//--------------------------------------------------------------------------------------------

void imprime_topo (Pilha *p)
{

    if (p->topo == NULL)
        printf("Pilha Vazia!\n");
    else 
    {
        printf("%s ", p->topo->palavra);
        //printf("------------------------------------\n");
    }
}

//-----------------------------------------------------------------------------------------------
/*
void imprime_pilha (Pilha p)//teste
{
    Pilha aux;
    int i;
    aux = p;
    imprime_topo(aux);
    for(; aux.topo != NULL; imprime_topo(aux))
        desempilha(&aux);
}
*/