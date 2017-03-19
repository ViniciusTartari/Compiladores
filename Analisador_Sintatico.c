//Nao otimizado
#include "Analisador_Sintatico.h"

int main ()
{

    char palavra[MAX], caractere;
    int i;

    FILE *fp;

    Fila f;
    Pilha p;
    Nodo *novo;

    inicializa_fila(&f);
    inicializa_pilha(&p);

    fp = fopen("saida_lexico.txt", "r");

    if(fp == NULL)
        printf("\n\nErro 0x0000: Nao foi possivel abrir o arquivo.\n\n");
    else
    {
        //tratamento lexico - empilhar tudo
        while (!feof(fp))
        {
            caractere = fgetc(fp);
            if (caractere == '<')
            {
                i = 0;
                caractere = fgetc(fp);
                while(caractere != '>')
                {
                    palavra[i] = caractere;
                    caractere = fgetc(fp);
                    i++;
                }
                palavra[i] = '\0';
                if (strcmp(palavra, "ATRIB")==0)//gambiarra pra arrumar a entrada pro sintatico;
                {
                    novo = cria_nodo (":");
                    enfilera (&f, novo);
                    novo = cria_nodo ("=");
                    enfilera (&f, novo);
                }
                else
                {
                    novo = cria_nodo (palavra);
                    enfilera (&f, novo);
                }
            }
        }
        novo = cria_nodo("$");
        enfilera(&f,novo);
        //imprime_fila(&f);
        //printf("\n");
        //imprime_first(&f); //verifica inicio
        //imprime_end(&f);   //verifica final
        //ta funcionando ate ak
        //----------------------------------------------------------------------------------------------
        //tratamento sintatico
        novo = cria_nodo("0"); //comeco da pilha
        empilha(&p,novo);
        //imprime_topo(&p); //verifica topo
        int iif = 0;
        int loko = 1;
        while(loko)
        {
            if (strcmp(p.topo->palavra, "1")==0 && strcmp(f.inicio->palavra, "$")==0)
            {
                printf("AC\n");
                loko = 0;
                return (0);
            }
            else if (strcmp(f.inicio->palavra, "ID")==0)
            {
                //Empilhas - 14
                if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                    strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("11");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                else if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "34")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("21");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                else if (strcmp(p.topo->palavra, "12")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("24");
                    empilha(&p, novo);
                    desenfilera(&f);
                }

                //Reduz - 6 - 18,19,22,23,26,27
                //r18 M-> <
                else if (strcmp(p.topo->palavra, "30")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0)
                    {
                        novo = cria_nodo("M");
                        empilha(&p, novo);
                        novo = cria_nodo("28");
                        empilha(&p, novo);
                    }
                }

                //r19 M-> =
                else if (strcmp(p.topo->palavra, "31")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0)
                    {
                        novo = cria_nodo("M");
                        empilha(&p, novo);
                        novo = cria_nodo("28");
                        empilha(&p, novo);
                    }
                }

                //r22 K->+
                else if (strcmp(p.topo->palavra, "32")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0 || strcmp(p.topo->palavra, "41")==0)
                    {
                        novo = cria_nodo("K");
                        empilha(&p, novo);
                        novo = cria_nodo("29");
                        empilha(&p, novo);
                    }
                }

                //r23 K->-
                else if (strcmp(p.topo->palavra, "33")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0 || strcmp(p.topo->palavra, "41")==0)
                    {
                        novo = cria_nodo("K");
                        empilha(&p, novo);
                        novo = cria_nodo("29");
                        empilha(&p, novo);
                    }
                }

                //r26 N->*
                else if (strcmp(p.topo->palavra, "35")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "17")==0 || strcmp(p.topo->palavra, "42")==0)
                    {
                        novo = cria_nodo("N");
                        empilha(&p, novo);
                        novo = cria_nodo("34");
                        empilha(&p, novo);
                    }
                }

                //r27 N->/
                else if (strcmp(p.topo->palavra, "36")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "17")==0 || strcmp(p.topo->palavra, "42")==0)
                    {
                        novo = cria_nodo("N");
                        empilha(&p, novo);
                        novo = cria_nodo("34");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "NUM")==0)
            {
                //Empilhas - 8
                if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                    strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "34")==0 ||
                    strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("21");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 6 - 18,19,22,23,26,27
                //r18 M-> <
                else if (strcmp(p.topo->palavra, "30")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0)
                    {
                        novo = cria_nodo("M");
                        empilha(&p, novo);
                        novo = cria_nodo("28");
                        empilha(&p, novo);
                    }
                }

                //r19 M-> =
                else if (strcmp(p.topo->palavra, "31")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0)
                    {
                        novo = cria_nodo("M");
                        empilha(&p, novo);
                        novo = cria_nodo("28");
                        empilha(&p, novo);
                    }
                }

                //r22 K->+
                else if (strcmp(p.topo->palavra, "32")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0 || strcmp(p.topo->palavra, "41")==0)
                    {
                        novo = cria_nodo("K");
                        empilha(&p, novo);
                        novo = cria_nodo("29");
                        empilha(&p, novo);
                    }
                }

                //r23 K->-
                else if (strcmp(p.topo->palavra, "33")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0 || strcmp(p.topo->palavra, "41")==0)
                    {
                        novo = cria_nodo("K");
                        empilha(&p, novo);
                        novo = cria_nodo("29");
                        empilha(&p, novo);
                    }
                }

                //r26 N->*
                else if (strcmp(p.topo->palavra, "35")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "17")==0 || strcmp(p.topo->palavra, "42")==0)
                    {
                        novo = cria_nodo("N");
                        empilha(&p, novo);
                        novo = cria_nodo("34");
                        empilha(&p, novo);
                    }
                }

                //r27 N->/
                else if (strcmp(p.topo->palavra, "36")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "17")==0 || strcmp(p.topo->palavra, "42")==0)
                    {
                        novo = cria_nodo("N");
                        empilha(&p, novo);
                        novo = cria_nodo("34");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "LBRACKET")==0)
            {
                //Empilhas - 8
                if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                    strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "34")==0 ||
                    strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("19");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 6 - 18,19,22,23,26,27
                //r18 M-> <
                else if (strcmp(p.topo->palavra, "30")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0)
                    {
                        novo = cria_nodo("M");
                        empilha(&p, novo);
                        novo = cria_nodo("28");
                        empilha(&p, novo);
                    }
                }

                //r19 M-> =
                else if (strcmp(p.topo->palavra, "31")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0)
                    {
                        novo = cria_nodo("M");
                        empilha(&p, novo);
                        novo = cria_nodo("28");
                        empilha(&p, novo);
                    }
                }

                //r22 K->+
                else if (strcmp(p.topo->palavra, "32")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0 || strcmp(p.topo->palavra, "41")==0)
                    {
                        novo = cria_nodo("K");
                        empilha(&p, novo);
                        novo = cria_nodo("29");
                        empilha(&p, novo);
                    }
                }

                //r23 K->-
                else if (strcmp(p.topo->palavra, "33")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "16")==0 || strcmp(p.topo->palavra, "41")==0)
                    {
                        novo = cria_nodo("K");
                        empilha(&p, novo);
                        novo = cria_nodo("29");
                        empilha(&p, novo);
                    }
                }

                //r26 N->*
                else if (strcmp(p.topo->palavra, "35")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "17")==0 || strcmp(p.topo->palavra, "42")==0)
                    {
                        novo = cria_nodo("N");
                        empilha(&p, novo);
                        novo = cria_nodo("34");
                        empilha(&p, novo);
                    }
                }

                //r27 N->/
                else if (strcmp(p.topo->palavra, "36")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "17")==0 || strcmp(p.topo->palavra, "42")==0)
                    {
                        novo = cria_nodo("N");
                        empilha(&p, novo);
                        novo = cria_nodo("34");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "RBRACKET")==0)
            {
                //Empilhas - 1
                if (strcmp(p.topo->palavra, "37")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("44");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 9 - 16,17,20,21,24,25,28,29,30 
                //r16 I->JMJ
                else if (strcmp(p.topo->palavra, "41")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r17 I->J
                else if (strcmp(p.topo->palavra, "16")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "TIMES")==0)
            {
                //Empilhas - 2
                if (strcmp(p.topo->palavra, "17")==0 || strcmp(p.topo->palavra, "42")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("35");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 5 - 24,25,28,29,30
                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }
                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "DIV")==0)
            {
                //Empilhas - 2
                if (strcmp(p.topo->palavra, "17")==0 || strcmp(p.topo->palavra, "42")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("36");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 7 - 20,21,24,25,28,29,30
                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "PLUS")==0)
            {
                //Empilhas - 2
                if (strcmp(p.topo->palavra, "16")==0 || strcmp(p.topo->palavra, "41")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("32");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 7 - 20,21,24,25,28,29,30
                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "MINUS")==0)
            {
                //Empilhas - 2
                if (strcmp(p.topo->palavra, "16")==0 || strcmp(p.topo->palavra, "41")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("33");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 7 - 20,21,24,25,28,29,30
                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "LESS")==0)
            {
                //Empilhas - 1
                if (strcmp(p.topo->palavra, "16")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("30");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 7 - 20,21,24,25,28,29,30
                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "=")==0 || strcmp(f.inicio->palavra, "EQUAL")==0)
            {
                //Empilhas - 2
                if (strcmp(p.topo->palavra, "16")==0 || strcmp(p.topo->palavra, "23")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("39");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 7 - 20,21,24,25,28,29,30
                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, ":")==0) 
            {
                //Empilhas - 
                if (strcmp(p.topo->palavra, "11")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("23");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
            }
            else if (strcmp(f.inicio->palavra, "IF")==0)
            {
                //Empilhas - 5
                if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 ||
                    strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("9");
                    empilha(&p, novo);
                    desenfilera(&f);
                    iif++;
                }
            }
            else if (strcmp(f.inicio->palavra, "THEN")==0)
            {
                //Empilhas - 1
                if (strcmp(p.topo->palavra, "15")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("27");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 16 - 2,3,4,5,6,7,8,16,17,20,21,24,25,28,29,30
                //r2 B->B;C
                else if (strcmp(p.topo->palavra, "26")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r3 B->C
                else if (strcmp(p.topo->palavra, "3")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r4 C->D
                else if (strcmp(p.topo->palavra, "4")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r5 C->E
                else if (strcmp(p.topo->palavra, "5")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r6 C->F
                else if (strcmp(p.topo->palavra, "6")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r7 C->G
                else if (strcmp(p.topo->palavra, "7")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r8 C->H
                else if (strcmp(p.topo->palavra, "8")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r16 I->JMJ
                else if (strcmp(p.topo->palavra, "41")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r17 I->J
                else if (strcmp(p.topo->palavra, "16")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "ELSE")==0)
            {
                //Empilhas - 1
                if (strcmp(p.topo->palavra, "40")==0)
                {
                    if (iif > 0) //empilhar
                    {
                        novo = cria_nodo(f.inicio->palavra);
                        empilha(&p, novo);
                        novo = cria_nodo("48");
                        empilha(&p, novo);
                        desenfilera(&f);
                        iif--;
                    }
                    else //reduz
                    {
                        //r10 X->vazio
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }
                //Reduz - 23- 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,21,24,25,28,29,30
                //r2 B->B;C
                else if (strcmp(p.topo->palavra, "26")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r3 B->C
                else if (strcmp(p.topo->palavra, "3")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r4 C->D
                else if (strcmp(p.topo->palavra, "4")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r5 C->E
                else if (strcmp(p.topo->palavra, "5")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r6 C->F
                else if (strcmp(p.topo->palavra, "6")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r7 C->G
                else if (strcmp(p.topo->palavra, "7")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r8 C->H
                else if (strcmp(p.topo->palavra, "8")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r9 D->ifIthemBX
                else if (strcmp(p.topo->palavra, "47")==0)
                {
                    for(i=0;i<10;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("D");
                        empilha(&p, novo);
                        novo = cria_nodo("4");
                        empilha(&p, novo);
                    }
                }

                //r11 X->elseBend
                else if (strcmp(p.topo->palavra, "50")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "40")==0)
                    {
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }

                //r12 E->repeatBuntilI
                else if (strcmp(p.topo->palavra, "45")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("E");
                        empilha(&p, novo);
                        novo = cria_nodo("5");
                        empilha(&p, novo);
                    }
                }

                //r13 F->id:=I  
                else if (strcmp(p.topo->palavra, "46")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p); //ak arrumar

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("F");
                        empilha(&p, novo);
                        novo = cria_nodo("6");
                        empilha(&p, novo);
                    }
                }

                //r14 G->read id
                else if (strcmp(p.topo->palavra, "24")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("G");
                        empilha(&p, novo);
                        novo = cria_nodo("7");
                        empilha(&p, novo);
                    }
                }

                //r15 H->writeI
                else if (strcmp(p.topo->palavra, "25")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("H");
                        empilha(&p, novo);
                        novo = cria_nodo("8");
                        empilha(&p, novo);
                    }
                }

                //r16 I->JMJ
                else if (strcmp(p.topo->palavra, "41")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r17 I->J
                else if (strcmp(p.topo->palavra, "16")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else if (strcmp(f.inicio->palavra, "END")==0)
            {
                //Empilhas - 1
                if (strcmp(p.topo->palavra, "49")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("50");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 23- 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,21,24,25,28,29,30
                //r2 B->B;C
                else if (strcmp(p.topo->palavra, "26")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r3 B->C
                else if (strcmp(p.topo->palavra, "3")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r4 C->D
                else if (strcmp(p.topo->palavra, "4")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r5 C->E
                else if (strcmp(p.topo->palavra, "5")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r6 C->F
                else if (strcmp(p.topo->palavra, "6")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r7 C->G
                else if (strcmp(p.topo->palavra, "7")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r8 C->H
                else if (strcmp(p.topo->palavra, "8")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r9 D->ifIthemBX
                else if (strcmp(p.topo->palavra, "47")==0)
                {
                    for(i=0;i<10;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("D");
                        empilha(&p, novo);
                        novo = cria_nodo("4");
                        empilha(&p, novo);
                    }
                }

                //r10 X->vazio
                else if (strcmp(p.topo->palavra, "40")==0)
                {
                    if (strcmp(p.topo->palavra, "40")==0)
                    {
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }

                //r11 X->elseBend
                else if (strcmp(p.topo->palavra, "50")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "40")==0)
                    {
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }

                //r12 E->repeatBuntilI
                else if (strcmp(p.topo->palavra, "45")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("E");
                        empilha(&p, novo);
                        novo = cria_nodo("5");
                        empilha(&p, novo);
                    }
                }

                //r13 F->id:=I  
                else if (strcmp(p.topo->palavra, "46")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p); //ak arrumar

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("F");
                        empilha(&p, novo);
                        novo = cria_nodo("6");
                        empilha(&p, novo);
                    }
                }

                //r14 G->read id
                else if (strcmp(p.topo->palavra, "24")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("G");
                        empilha(&p, novo);
                        novo = cria_nodo("7");
                        empilha(&p, novo);
                    }
                }

                //r15 H->writeI
                else if (strcmp(p.topo->palavra, "25")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("H");
                        empilha(&p, novo);
                        novo = cria_nodo("8");
                        empilha(&p, novo);
                    }
                }

                //r16 I->JMJ
                else if (strcmp(p.topo->palavra, "41")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r17 I->J
                else if (strcmp(p.topo->palavra, "16")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }


            }
            else if (strcmp(f.inicio->palavra, "REPEAT")==0)
            {
                //Empilhas - 5
                if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 ||
                    strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("10");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
            }
            else if (strcmp(f.inicio->palavra, "UNTIL")==0)
            {
                //Empilhas - 1
                if (strcmp(p.topo->palavra, "22")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("38");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
                //Reduz - 23- 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,21,24,25,28,29,30
                //r2 B->B;C
                else if (strcmp(p.topo->palavra, "26")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r3 B->C
                else if (strcmp(p.topo->palavra, "3")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r4 C->D
                else if (strcmp(p.topo->palavra, "4")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r5 C->E
                else if (strcmp(p.topo->palavra, "5")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r6 C->F
                else if (strcmp(p.topo->palavra, "6")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r7 C->G
                else if (strcmp(p.topo->palavra, "7")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r8 C->H
                else if (strcmp(p.topo->palavra, "8")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r9 D->ifIthemBX
                else if (strcmp(p.topo->palavra, "47")==0)
                {
                    for(i=0;i<10;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("D");
                        empilha(&p, novo);
                        novo = cria_nodo("4");
                        empilha(&p, novo);
                    }
                }

                //r10 X->vazio
                else if (strcmp(p.topo->palavra, "40")==0)
                {
                    if (strcmp(p.topo->palavra, "40")==0)
                    {
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }

                //r11 X->elseBend
                else if (strcmp(p.topo->palavra, "50")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "40")==0)
                    {
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }

                //r12 E->repeatBuntilI
                else if (strcmp(p.topo->palavra, "45")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("E");
                        empilha(&p, novo);
                        novo = cria_nodo("5");
                        empilha(&p, novo);
                    }
                }

                //r13 F->id:=I  
                else if (strcmp(p.topo->palavra, "46")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p); 

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("F");
                        empilha(&p, novo);
                        novo = cria_nodo("6");
                        empilha(&p, novo);
                    }
                }

                //r14 G->read id
                else if (strcmp(p.topo->palavra, "24")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("G");
                        empilha(&p, novo);
                        novo = cria_nodo("7");
                        empilha(&p, novo);
                    }
                }

                //r15 H->writeI
                else if (strcmp(p.topo->palavra, "25")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("H");
                        empilha(&p, novo);
                        novo = cria_nodo("8");
                        empilha(&p, novo);
                    }
                }

                //r16 I->JMJ
                else if (strcmp(p.topo->palavra, "41")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r17 I->J
                else if (strcmp(p.topo->palavra, "16")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }


            }
            else if (strcmp(f.inicio->palavra, "READ")==0)
            {
                //Empilhas - 5
                if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 ||
                    strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("12");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
            }
            else if (strcmp(f.inicio->palavra, "WRITE")==0)
            {
                //Empilhas - 5
                if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 ||
                    strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("13");
                    empilha(&p, novo);
                    desenfilera(&f);
                }
            }
            else if (strcmp(f.inicio->palavra, "DOTCOMA")==0)
            {
                //Empilhas - 4
                if (strcmp(p.topo->palavra, "2")==0 || strcmp(p.topo->palavra, "22")==0 || strcmp(p.topo->palavra, "49")==0)
                {
                    novo = cria_nodo(f.inicio->palavra);
                    empilha(&p, novo);
                    novo = cria_nodo("14");
                    empilha(&p, novo);
                    desenfilera(&f);
                }

                else if (strcmp(p.topo->palavra, "40")==0)
                {
                    if (iif > 0) //empilhar
                    {
                        novo = cria_nodo(f.inicio->palavra);
                        empilha(&p, novo);
                        novo = cria_nodo("14");
                        empilha(&p, novo);
                        desenfilera(&f);
                        iif--;
                    }
                    else //reduz
                    {
                        //r10 X->vazio
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }
                //Reduz - 23- 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,21,24,25,28,29,30
                //r2 B->B;C
                else if (strcmp(p.topo->palavra, "26")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r3 B->C
                else if (strcmp(p.topo->palavra, "3")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r4 C->D
                else if (strcmp(p.topo->palavra, "4")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r5 C->E
                else if (strcmp(p.topo->palavra, "5")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r6 C->F
                else if (strcmp(p.topo->palavra, "6")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r7 C->G
                else if (strcmp(p.topo->palavra, "7")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r8 C->H
                else if (strcmp(p.topo->palavra, "8")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r9 D->ifIthemBX
                else if (strcmp(p.topo->palavra, "47")==0)
                {
                    for(i=0;i<10;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("D");
                        empilha(&p, novo);
                        novo = cria_nodo("4");
                        empilha(&p, novo);
                    }
                }

                //r10 X->vazio
                else if (strcmp(p.topo->palavra, "40")==0)
                {
                    if (strcmp(p.topo->palavra, "40")==0)
                    {
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }

                //r11 X->elseBend
                else if (strcmp(p.topo->palavra, "50")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "40")==0)
                    {
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }

                //r12 E->repeatBuntilI
                else if (strcmp(p.topo->palavra, "45")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("E");
                        empilha(&p, novo);
                        novo = cria_nodo("5");
                        empilha(&p, novo);
                    }
                }

                //r13 F->id:=I
                else if (strcmp(p.topo->palavra, "46")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p); 

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("F");
                        empilha(&p, novo);
                        novo = cria_nodo("6");
                        empilha(&p, novo);
                    }
                }

                //r14 G->read id
                else if (strcmp(p.topo->palavra, "24")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("G");
                        empilha(&p, novo);
                        novo = cria_nodo("7");
                        empilha(&p, novo);
                    }
                }

                //r15 H->writeI
                else if (strcmp(p.topo->palavra, "25")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("H");
                        empilha(&p, novo);
                        novo = cria_nodo("8");
                        empilha(&p, novo);
                    }
                }

                //r16 I->JMJ
                else if (strcmp(p.topo->palavra, "41")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r17 I->J
                else if (strcmp(p.topo->palavra, "16")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }


            }
            else if (strcmp(f.inicio->palavra, "$")==0)
            {
                //Reduz - 24 - 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,21,24,25,28,29,30
                //r1 A->B
                if (strcmp(p.topo->palavra, "2")==0)
                {
                    //for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "2")==0)
                    {
                        novo = cria_nodo("A");
                        empilha(&p, novo);
                        novo = cria_nodo("1");
                        empilha(&p, novo);
                    }
                }

                //r2 B->B;C
                else if (strcmp(p.topo->palavra, "26")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r3 B->C
                else if (strcmp(p.topo->palavra, "3")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "10")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("22");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "27")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("40");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("B");
                        empilha(&p, novo);
                        novo = cria_nodo("49");
                        empilha(&p, novo);
                    }
                }

                //r4 C->D
                else if (strcmp(p.topo->palavra, "4")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r5 C->E
                else if (strcmp(p.topo->palavra, "5")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r6 C->F
                else if (strcmp(p.topo->palavra, "6")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r7 C->G
                else if (strcmp(p.topo->palavra, "7")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r8 C->H
                else if (strcmp(p.topo->palavra, "8")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "27")==0 ||
                        strcmp(p.topo->palavra, "48")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("3");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "14")==0)
                    {
                        novo = cria_nodo("C");
                        empilha(&p, novo);
                        novo = cria_nodo("26");
                        empilha(&p, novo);
                    }
                }

                //r9 D->ifIthemBX
                else if (strcmp(p.topo->palavra, "47")==0)
                {
                    for(i=0;i<10;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("D");
                        empilha(&p, novo);
                        novo = cria_nodo("4");
                        empilha(&p, novo);
                    }
                }

                //r10 X->vazio
                else if (strcmp(p.topo->palavra, "40")==0)
                {
                    if (strcmp(p.topo->palavra, "40")==0)
                    {
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }

                //r11 X->elseBend
                else if (strcmp(p.topo->palavra, "50")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "40")==0)
                    {
                        novo = cria_nodo("X");
                        empilha(&p, novo);
                        novo = cria_nodo("47");
                        empilha(&p, novo);
                    }
                }

                //r12 E->repeatBuntilI
                else if (strcmp(p.topo->palavra, "45")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("E");
                        empilha(&p, novo);
                        novo = cria_nodo("5");
                        empilha(&p, novo);
                    }
                }

                //r13 F->id:=I
                else if (strcmp(p.topo->palavra, "46")==0)
                {
                    for(i=0;i<8;i++) desempilha(&p); //ak arrumar

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("F");
                        empilha(&p, novo);
                        novo = cria_nodo("6");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "22")==0)
                    {
                        desempilha(&p);
                        novo = cria_nodo("2");
                        empilha(&p, novo);
                    }
                }

                //r14 G->read id
                else if (strcmp(p.topo->palavra, "24")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("G");
                        empilha(&p, novo);
                        novo = cria_nodo("7");
                        empilha(&p, novo);
                    }
                }

                //r15 H->writeI
                else if (strcmp(p.topo->palavra, "25")==0)
                {
                    for(i=0;i<4;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "0")==0 || strcmp(p.topo->palavra, "10")==0 || strcmp(p.topo->palavra, "14")==0 || 
                        strcmp(p.topo->palavra, "27")==0 || strcmp(p.topo->palavra, "48")==0 )
                    {
                        novo = cria_nodo("H");
                        empilha(&p, novo);
                        novo = cria_nodo("8");
                        empilha(&p, novo);
                    }
                }

                //r16 I->JMJ
                else if (strcmp(p.topo->palavra, "41")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r17 I->J
                else if (strcmp(p.topo->palavra, "16")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("15");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "13")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("25");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "19")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("37");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "38")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("45");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("I");
                        empilha(&p, novo);
                        novo = cria_nodo("46");
                        empilha(&p, novo);
                    }
                }

                //r20 J->JKL
                else if (strcmp(p.topo->palavra, "42")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r21 J->L
                else if (strcmp(p.topo->palavra, "17")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("16");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "28")==0)
                    {
                        novo = cria_nodo("J");
                        empilha(&p, novo);
                        novo = cria_nodo("41");
                        empilha(&p, novo);
                    }
                }

                //r24 L->LNO
                else if (strcmp(p.topo->palavra, "43")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r25 L->O
                else if (strcmp(p.topo->palavra, "18")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "38")==0 || strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("17");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "29")==0)
                    {
                        novo = cria_nodo("L");
                        empilha(&p, novo);
                        novo = cria_nodo("42");
                        empilha(&p, novo);
                    }
                }

                //r28 O->(I)
                else if (strcmp(p.topo->palavra, "44")==0)
                {
                    for(i=0;i<6;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r29 O->num
                else if (strcmp(p.topo->palavra, "20")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

                //r30 O->id
                else if (strcmp(p.topo->palavra, "21")==0)
                {
                    for(i=0;i<2;i++) desempilha(&p);

                    if (strcmp(p.topo->palavra, "9")==0 || strcmp(p.topo->palavra, "13")==0 || strcmp(p.topo->palavra, "19")==0 ||
                        strcmp(p.topo->palavra, "28")==0 || strcmp(p.topo->palavra, "29")==0 || strcmp(p.topo->palavra, "38")==0 || 
                        strcmp(p.topo->palavra, "39")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("18");
                        empilha(&p, novo);
                    }
                    else if (strcmp(p.topo->palavra, "34")==0)
                    {
                        novo = cria_nodo("O");
                        empilha(&p, novo);
                        novo = cria_nodo("43");
                        empilha(&p, novo);
                    }
                }

            }
            else
            {
                printf("ERRO\n");
                loko = 0;
                return(0);
            }
        
        }
    }
    return(0);
}
