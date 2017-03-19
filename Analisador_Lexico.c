#include "Analisador_Lexico.h"

int main()
{
    char numeros[20], palavra[20], caractere;
    int i, j, carac_loko = 0, flag = 0, lin = 1, col = 1;

    FILE *fp;

    Lista *l;

    l = inicializa_lista();

    fp = fopen("source_code.txt", "r");

    if(fp == NULL)
        printf("\n\nErro 0x0000: Nao foi possivel abrir o arquivo.\n\n");
    else{
        caractere = fgetc(fp);
        while(!feof(fp))
        {
            if(caractere == '\n')
            {
                lin++;
                col = 1;
            }
            while((caractere == '{' || caractere == ' ') && caractere != EOF)
            {
                if(caractere == '{')
                    while(caractere != '}' && caractere != EOF)
                    {
                        caractere = fgetc(fp);
                        if(caractere == '\n')
                        {
                            lin++;
                            col = 1;
                        }
                    }
                while(caractere == ' ' && caractere != EOF)
                    caractere = fgetc(fp);
                col++;
            }
            if(caractere != EOF)
            {
                i = j = 0;
                if ((caractere >= '!' && (int)caractere <= 39) || (caractere >= '^' && caractere <= '`') || caractere == '|' || caractere == '~' || caractere == '@')
                {
                    printf("\nErro 0x0004 em (%d %d): Identificador invalido.\n",lin,col);
                    l = insere(l, palavra, "ERROR");
                    flag = 1;
                    while(caractere != ' ')
                    {
                        caractere = fgetc(fp);
                        col++;
                    }
                }
                else if(caractere >= '0' && caractere <= '9')
                {
                    col++;
                    numeros[i] = caractere;
                    i++;
                    caractere = fgetc(fp);

                    while(caractere >= '0' && caractere <= '9')
                    {
                        col++;
                        numeros[i] = caractere;
                        i++;
                        caractere = fgetc(fp);
                    }
                    if (caractere == '.' || caractere == ',')
                    {
                        printf("\nErro 0x0002 em (%d %d): Formato de numero invalido (somente inteiros).\n",lin,col-2);
                        l = insere(l, palavra, "ERROR");
                        while(caractere != ' ')
                        {
                            caractere = fgetc(fp);
                            col++;
                        }
                        flag = 1;
                    }
                    else
                    {
                        numeros[i] = '\0';
                        l = insere(l, numeros, "NUM");
                    }
                }
                else if((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z'))
                {
                    if ((caractere >= '!' && (int)caractere <= 39) || (caractere >= '^' && caractere <= '`') || caractere == '|' || caractere == '~' || caractere == '@')
                    {
                        printf("\nErro 0x0004 em (%d %d): Identificador invalido.\n",lin,col);
                        l = insere(l, palavra, "ERROR");
                        flag = 1;
                        while(caractere != ' ')
                        {
                            caractere = fgetc(fp);
                            col++;
                        }
                    }
                    col++;
                    palavra[j] = caractere;
                    j++;
                    caractere = fgetc(fp);

                    while((caractere >= '0' && caractere <='9') || (caractere >='A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z'))
                    {
                        col++;
                        palavra[j] = caractere;
                        j++;
                        caractere = fgetc(fp);
                        if ((caractere >= '!' && (int)caractere <= 39) || (caractere >= '^' && caractere <= '`') || caractere == '|' || caractere == '~' || caractere == '@')
                        {
                            printf("\nErro 0x0004 em (%d %d): Identificador invalido.\n",lin,col);
                            l = insere(l, palavra, "ERROR");
                            flag = 1;
                            while(caractere != ' ')
                            {
                                caractere = fgetc(fp);
                                col++;
                            }
                        }
                    }

                    palavra[j] = '\0';

                    if(strcmp(strlwr(palavra),"then") == 0)
                    {
                        l = insere(l, palavra, "THEN");
                        flag = 1;
                    }
                    else if(strcmp(strlwr(palavra),"if") == 0)
                    {
                        l = insere(l, palavra, "IF");
                        flag = 1;
                    }
                    else if(strcmp(strlwr(palavra),"else") == 0)
                    {
                        l = insere(l, palavra, "ELSE");
                        flag = 1;
                    }
                    else if(strcmp(strlwr(palavra),"end") == 0)
                    {
                        l = insere(l, palavra, "END");
                        flag = 1;
                    }
                    else if(strcmp(strlwr(palavra),"repeat") == 0)
                    {
                        l = insere(l, palavra, "REPEAT");
                        flag = 1;
                    }
                    else if(strcmp(strlwr(palavra),"until") == 0)
                    {
                        l = insere(l, palavra, "UNTIL");
                        flag = 1;
                    }
                    else if(strcmp(strlwr(palavra),"read") == 0)
                    {
                        l = insere(l, palavra, "READ");
                        flag = 1;
                    }
                    else if(strcmp(strlwr(palavra),"write") == 0)
                    {
                        l = insere(l, palavra, "WRITE");
                        flag = 1;
                    }
                    if(flag == 0)
                        l = insere(l, palavra, "ID");
                }

                else if(caractere == '+')
                    l = insere(l, "+", "PLUS");
                else if(caractere == '-')
                {
                    caractere = fgetc(fp);
                    col++;
                    if(caractere >= '0' && caractere <= '9')
                    {
                        printf("\nErro 0x0003 em (%d %d): Formato de numero invalido (valor negativo).\n",lin,col-2);
                        l = insere(l, palavra, "ERROR");
                        while(caractere != ' ')
                        {
                            caractere = fgetc(fp);
                            col++;
                        }
                        col++;
                    }
                    else
                        l = insere(l, "-", "MINUS");
                }
                else if(caractere == '*')
                    l = insere(l, "*", "TIMES");
                else if(caractere == '/')
                    l = insere(l, "/", "DIV");
                else if(caractere == '=')
                    l = insere(l, "=", "EQUAL");
                else if(caractere == '<')
                    l = insere(l, "<", "LESS");
                else if(caractere == '(')
                    l = insere(l, "(", "LBRACKET");
                else if(caractere == ')')
                    l = insere(l, ")", "RBRACKET");
                else if(caractere == ';')
                    l = insere(l, ";", "DOTCOMA");
                else if(caractere == ':')
                {
                    caractere = fgetc(fp);
                    col++;
                    if(caractere == '=')
                        {l = insere(l, ":=", "ATRIB"); col++;}
                }
                else
                {
                    caractere = fgetc(fp);
                    carac_loko = 1;
                }
                col++;
            }

            if(carac_loko == 0 )
                caractere = fgetc(fp);
            carac_loko = 0;

            flag = 0;
        }

        fclose(fp);
        l = arruma(l);
        imprime_lista(l);
    }
    return(0);
}
