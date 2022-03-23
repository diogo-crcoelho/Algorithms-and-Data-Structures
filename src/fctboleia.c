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

struct _app{

dicOrdenado utilizadores;
char logado[50];

};

app criaAplicacao(){

  app ap = (app)malloc(sizeof(struct _app));
    if(ap==NULL)
        return(NULL);

        ap->utilizadores=criaDicOrdenado(100000,1);

    return ap;
}

void destroiAplicacao(app ap){

destroiAllUser(ap);
free(ap);

}

int adicionaUtilizador(app ap,Login L){

int x=adicionaElemDicOrdenado(ap->utilizadores,getemail(L),L);
return x;

}

int existeUser(app ap,char*email){

    int x=existeElemDicOrdenado(ap->utilizadores,email);
    return x;
}

Login elementoUtilizador(app ap,char*email){

Login L=elementoDicOrdenado(ap->utilizadores,email);
return L;

}

void registaLogado(app ap,char*email){

 strcpy(ap->logado,email);

}

char*getLogado(app ap){

return ap->logado;
}

int codificador(char*comando, char*parametro,int log)
{
    int cod=0;

    if (strcmp(comando,"AJUDA")==0 && strcmp(parametro,"")==0)
        if (log==0)
            cod=1;
        else
            cod=2;

    else if (strcmp(comando,"TERMINA")==0&& strcmp(parametro,"")==00&&log==0)
        cod=3;
    else if (strcmp(comando,"REGISTA")==0 && strcmp(parametro,"")!=0&&log==0)
        cod=4;
    else if (strcmp(comando,"ENTRADA")==0&& strcmp(parametro,"")!=00&&log==0)
        cod=5;
    else if (strcmp(comando,"SAI")==0&& strcmp(parametro,"")==00&&log==1)
        cod=6;
    else if (strcmp(comando,"NOVA")==0&& strcmp(parametro,"")==00&&log==1)
        cod=7;
    else if (strcmp(comando,"LISTA")==0&& strcmp(parametro,"minhas")==00&&log==1)
        cod=8;
    else if (strcmp(comando,"REMOVE")==0&& strcmp(parametro,"")!=00&&log==1)
        cod=9;
    // else if
    else if (strcmp(comando,"BOLEIA")==0&& strcmp(parametro,"")!=00&&log==1)
        cod=10;
    else if(strcmp(comando,"LISTA")==0&&strcmp(parametro,"boleias")==00&&log==1)
        cod=11;
    else if(strcmp(comando,"LISTA")==0&&strcmp(parametro,"")!=00&&log==1)
        cod=12;

        else if(strcmp(comando,"RETIRA")==0&&strcmp(parametro,"")!=00&&log==1)
        cod=13;
    return cod;

}


int checkpass(char *pass)

{
    int i,x;
    int k;


    if(strlen(pass)>=4&&strlen(pass)<=6)
    {



        for(i=0; i<strlen(pass); i++)
        {
            if(isalnum(pass[i])==0)
          return 0;
        }
            for(x=0;x<strlen(pass);x++)
                if (isdigit(pass[x]))
                {
                    for(k=0; k<strlen(pass); k++)
                    {

                        if(isalpha(pass[k]))
                            return 1;
                    }
                    if (k==strlen(pass))
                        return 0;




        }
        if(i==strlen(pass))
            return 0;

    }
    return 0;


}

char * Maiusculas(char*comando)
{
    int i;
    for(i=0; i<strlen(comando); i++)
    {
        comando[i]=toupper(comando[i]);
    }
    return comando;
}

void clearbuffer(char*comando,char*parametro)
{
    comando[0]='\0';
    parametro[0]='\0';
}


int checktime(int horas,int minuto)
{
    if(horas>=0&&horas<24)
    {
        if(minuto>=0&&minuto<60)
            return 1;
    }

    return 0;

}

int checkDuraPass(int lugares,int duracao)
{
    if(duracao>0&&lugares>0)
        return 1;
    else
        return 0;
}


int checkdia(char*data)
{
    int dia,mes,ano;
    sscanf(data,"%d-%d-%d",&dia,&mes,&ano);
    return dia;

}

int checkmes(char*data)
{
    int dia,mes,ano;
    sscanf(data,"%d-%d-%d",&dia,&mes,&ano);
    return mes;


}

int checkano(char*data)
{
    int dia,mes,ano;
    sscanf(data,"%d-%d-%d",&dia,&mes,&ano);
    return ano;

}


int checkdata(char* data)
{
    int kapa;
    if(checkano(data) % 4 == 0)
        kapa=2;
    if(checkano(data) % 4 != 0)
        kapa=1;

    if(checkano(data)>0)
    {
        if(checkmes(data)>0&&checkmes(data)<13)
        {

            if(checkmes(data)==2&&checkdia(data)>0)
            {
                if (kapa==1&&checkdia(data)<29)
                    return 1;
                else if (kapa==2&&checkdia(data)<30)
                    return 1;
                else
                    return 0;
            }
            else if(checkmes(data)<8&&checkdia(data)>0)
            {

                if(checkmes(data)%2==0)
                {
                    if (checkdia(data)<31)
                        return 1;
                    else
                        return 0;
                }
                else if (checkmes(data)%2!=0)
                {
                    if (checkdia(data)<32)
                        return 1;
                    else
                        return 0;
                }
            }
            else if(checkmes(data)>7&&checkdia(data)>0)
            {


                if(checkmes(data)%2==0&&checkdia(data)>0)
                {
                    if (checkdia(data)<32)
                        return 1;
                    else
                        return 0;
                }

                else if (checkmes(data)%2!=0&&checkdia(data)>0)
                {
                    if (checkdia(data)<31)
                        return 1;
                    else
                        return 0;
                }
            }
        }
    }
    return 0;

}




int checkdados(char*data,int lugares,int duracao,int horas,int minutos)
{
    int x=checkDuraPass(lugares,duracao);
    int k=checktime(horas,minutos);
    int y=checkdata(data);

    if(x==1&&k==1&&y==1)
        return 1;
    else
        return 0;

}


iterador iteraUsers(app ap)
{
    iterador t=iteradorDicOrdenado(ap->utilizadores);
    return t;

}

int sortr(char*parametro)

{
    int k;
    for(k=0; k<strlen(parametro); k++)
    {

        if(isalpha(parametro[k]))
            return 1;
    }
    return 0;
}


void destroiAllUser(app ap)
{
    int k;
    iterador it=iteraUsers(ap);
    for(k=0;temSeguinteIterador(it);k++)
    {
        Login L=seguinteIterador(it);
        destroiUser(L);
    }
    destroiIterador(it);
}
