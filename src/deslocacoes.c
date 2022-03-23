#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "iterador.h"
#include "chaves.h"
#include "tuplo.h"
#include "dicionario.h"
#include "dicionarioOrdenado.h"
#include "deslocacoes.h"
#include "utilizadores.h"
#include "fctboleia.h"

struct _viagens{
    char *origem;
    char *destino;
    int hora;
    int min;
    int duracao;
    int ocupantes;
    char data[10];
    int vagos;
    dicOrdenado emails;
    int num;
};

struct _boleia{
    int num;
    char email[50];
};


viagens cria_viagem (char*origem,char*destino,char*data,int hora, int minuto, int duracao, int lugares){

    viagens b = (viagens)malloc(sizeof(struct _viagens));
    if(b==NULL)
        return(NULL);

b->origem = (char*) malloc(sizeof(char)* (strlen(origem)+1));
    if (b->origem==NULL)
    {
        free(b);
        return NULL;
    }
    strcpy(b->origem, origem);

    b->destino = (char*) malloc(sizeof(char)* (strlen(destino)+1));
    if (b->destino==NULL)
    {
        free(b);
        return NULL;
    }
    strcpy(b->destino, destino);

    strcpy(b->data,data);
    b->hora=hora;
    b->min=minuto;
    b->duracao=duracao;
    b->ocupantes=lugares;
    b->vagos=lugares;
    b->emails=criaDicOrdenado(lugares,0);
    b->num=0;
    return b;
}

int getNum(boleia bo){
    return bo->num;
}

boleia cria_boleia(viagens b,char *email){
    boleia bo = (boleia)malloc(sizeof(struct _boleia));
    if(bo==NULL)
        return(NULL);

        bo->num=b->num;
        strcpy(bo->email,email);

        return bo;
}
void destroiBole(viagens b){

    destroiDicOrdenado(b->emails);
    free(b);

}


char* getorigem(viagens b){
    return b->origem;
}
char* getdestino(viagens b){
    return b->destino;
}
char* getdata(viagens b){
    return b->data;
}

int trata_horas(viagens b){
    //int h;
    //h=b->hora;

    return b->hora;
}

int trata_minutos(viagens b){
    //int h;
    //h=b->hora;

    return b->min;
}

int trata_dura(viagens b){
    //int h;
    //h=b->hora;

    return b->duracao;
}

int trata_lugar(viagens b){
    //int h;
    //h=b->hora;

    return b->ocupantes;

}




int checkLugares(viagens b){
    if (b->vagos>0)
        return b->vagos;
    return -1;
}

int checkboleias(viagens b,char*email){
int t=0;
int x;

    iterador it=iteraBoleias(b);
    for (x=0;temSeguinteIterador(it);x++)
    {
        boleia bo=(boleia)seguinteIterador(it);

        if(strcmp(bo->email,email)==0)
        {
            t++;
            return 1;
            break;
        }


    }
    destroiIterador(it);
    return 0;
}
int addBoleia(viagens b,boleia bo){

    b->num++;
    b->vagos--;
    int f=getNum(bo);
    int x= adicionaElemDicOrdenado(b->emails,&f,bo);
    return x;
}


int getvagos(viagens b){
    return b->vagos;
}

int checkRemoverViagem (viagens b){
    if(b->vagos==b->ocupantes)
        return 1;
    return 0;
}

iterador iteraBoleias(viagens b){

        iterador t=iteradorDicOrdenado(b->emails);
        return t;
}


void removeBoleia(viagens b,char*email){
int x;
int f;
   iterador it=iteraBoleias(b);
    for (x=0;temSeguinteIterador(it);x++)
    {
        boleia bo=(boleia)seguinteIterador(it);
        f=getNum(bo);
        if(strcmp(bo->email,email)==0)
        {
            removeElemDicOrdenado(b->emails,&f);
        }


    }
    destroiIterador(it);
    b->vagos++;

}

char * getMailBol(boleia bo){
    return bo->email;
}




