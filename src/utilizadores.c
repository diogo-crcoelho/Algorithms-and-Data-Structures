
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "iterador.h"
#include "chaves.h"
#include "tuplo.h"
#include "dicionario.h"
#include "deslocacoes.h"
#include "utilizadores.h"
#include "dicionarioOrdenado.h"
#include "fctboleia.h"

struct _Login
{
    char email[50];
    char nome[50];
    char password[6];
    dicOrdenado viagens;
    dicionario boleia;
} ;



Login cria_Log (char *mail,char *nome, char *pass)
{

    Login L = (Login)malloc(sizeof(struct _Login));
    if(L==NULL)
        return(NULL);


    strcpy(L->email,mail);
    strcpy(L->nome,nome);
    strcpy(L->password,pass);
    L->viagens=criaDicOrdenado(5000,1);
    L->boleia=criaDicionario(5000,1);

    return L;
}

void destroiUser(Login L)
{
    int k;
    destroiDicionario(L->boleia);
    iterador it=iteraviagens(L);
    for (k=0;temSeguinteIterador(it);k++)
    {
        viagens vi=seguinteIterador(it);
        destroiBole(vi);
    }
    destroiDicOrdenado(L->viagens);
    destroiIterador(it);
    free (L);
}

int addViagemLogin(Login L,viagens b,char*data)
{

int x=adicionaElemDicOrdenado(L->viagens,getdata(b),b);
    return x;

}

viagens elementoViagemUser(Login L,char*data)
{

        viagens b=elementoDicOrdenado(L->viagens,data);
        return b;

}

int existeViagem(Login L,char *data)
{
    int x;
    x=existeElemDicOrdenado(L->viagens,data);
    return x;


}


char* getemail(Login L)
{
    return L->email;
}

char* getnome(Login L)
{
    return L->nome;
}

char* getpass(Login L)
{
    return L->password;
}

int compPass(char *pass,char *realpass)
{
    if(strcmp(pass,realpass)!=0)
        return 0;
    else
        return 1;
}

iterador iteraviagens(Login L)
{
    iterador t=iteradorDataOrdenada(L->viagens);
    return t;

}

int removeViagem(Login L,char*data)
{
    viagens b;
    if (checkdata(data)==1)
    {


        if(existeViagem(L,data)==1)
        {
            b=elementoViagemUser(L,data);
            if(checkRemoverViagem(b)==1)
            {
                removeElemDicOrdenado(L->viagens,data);
                return 1;
            }
            else
                return 3;
        }
        else
            return 0;
    }

    return 2;

}

int numeroViagens(Login L)
{

    return tamanhoDicOrdenado(L->viagens);
}

int checkboleiasUser(Login L,char*data)

{
    if(existeElemDicionario(L->boleia,data)==1)
        return 1;
    return 0;
}

int addBoleiaUser(Login L,char*data)
{
    int x= adicionaElemDicionario(L->boleia,data,data);
    return x;
}
int numeroBoleias(Login L)
{

    return tamanhoDicionario(L->boleia);
}

int removeBoleiaUser(Login L,char*data)
{
    removeElemDicionario(L->boleia,data);
    return 1;
}

