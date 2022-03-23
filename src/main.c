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


/***********************************************
trataTermina - trata de terminar o programa, apagando todas as instancias de memoria alocadas.
Parametros:
	a - aplicacao onde estao todos os dados a apagar;

Retorno:
Pre-condicoes: a!=NULL
***********************************************/
void trataTermina(app a){

    printf("Obrigado. Ate a proxima.\n");
    destroiAplicacao(a);
    exit(0);
}

/***********************************************
trataRegista - trata de registar um novo utilizador na aplicacao.
Parametros:
	a - aplicaçao onde estao todos os dados;
    email - email do utilizador a registar

Retorno:
Pre-condicoes: a!=NULL email"=NULL
***********************************************/
void trataRegista(app a,char*email){

    Login User;
    char nome[50];
    char passe[6];
    char nome2[50];
    int k=existeUser(a,email);
    if(k==0)
    {

        printf("nome (maximo 50 caracteres): ");
        fgets(nome,50,stdin);
        nome[strlen(nome)-1]='\0';
        //printf("nome guardado e:%s\n",nome);
        strcpy(nome2,nome);
        int tentativa=0;
        while(tentativa<3)
        {

            printf("password (entre 4 e 6 caracteres - digitos e letras): ");
            scanf("%s",passe);
            getchar();

            int s=checkpass(passe);

            if(s==0)
            {

                printf("Password incorrecta.\n");
                tentativa++;
            }
            else if(s==1)
            {

                printf("Registo efetuado.\n");
                User=cria_Log(email,nome2,passe);
                adicionaUtilizador(a,User);

                break;
            }
            if (tentativa==3)
            {

                printf("Registo nao efetuado.\n");
                break;
            }
        }
    }
    if (k==1)
        printf("Utilizador ja existente.\nRegisto nao efetuado.\n");

}

/***********************************************
trataEntrada - trata de iniciar sessao do utilizador pretendido.
Parametros:
	a - aplicaçao onde estao os dados ;
	email - email do utilizador a iniciar sessao

Retorno: 1 se der entrada; 0 se nao der
Pre-condicoes: a!=NULL email!=NULL
***********************************************/
int trataEntrada(app a,char*email){

    Login User;
    char passe[6];
    int k=existeUser(a,email);
    if(k==1)
    {

        User=elementoUtilizador(a,email);
        int tentativa=0;
        while(tentativa<3)
        {

            printf("password: ");
            scanf("%s",passe);
            getchar();
            int s=compPass(passe,getpass(User));

            if(s==0)
            {

                printf("Password incorrecta.\n");
                tentativa++;
            }
            else if(s==1)

                return 1;

            if (tentativa==3)
            {

                break;
            }
        }
    }
    else
        printf("Utilizador nao existente.\n");
    return 0;
}

/***********************************************
trataViagem - trata de adicionar uma viagem ao utilizador com sessao iniciada.
Parametros:
	a - aplicaçao onde estao os dados;
	logado - email do utilizador com sessao iniciada;

Retorno:
Pre-condicoes: a!=NULL logado!=NULL
***********************************************/
void trataViagem(app a,char *logado){

    Login User;
    viagens vi;
    char data[10];
    char origem[50];
    char destino[50];
    int hora,min,lugares,duracao;
    int f;
    {


        fgets(origem,50,stdin);
        origem[strlen(origem)-1]='\0';
        fgets(destino,50,stdin);
        destino[strlen(destino)-1]='\0';
        scanf("%s %d:%d %d %d",data,&hora,&min,&duracao,&lugares);
        getchar();

        User=elementoUtilizador(a,logado);
        f=existeViagem(User,data);

        if(checkdados(data,lugares,duracao,hora,min)==1)
        {
            if (f==0)
            {
                vi=cria_viagem(origem,destino,data,hora,min,duracao,lugares);
                addViagemLogin(User,vi,data);
                printf("Deslocacao registada. Obrigado %s.\n",getnome(User));
            }
            else if(f==1)
            {
                printf("%s ja tem uma deslocacao registada nesta data.\nDeslocacao nao registada.\n",getnome(User));
            }
        }
        else
            printf("Dados invalidos.\nDeslocacao nao registada.\n");




    }
}

/***********************************************
trataRemoveViagem - trata de remover uma viagem de uma dada data ao utilizador com sessao iniciada.
Parametros:
	a - aplicaçao onde estao os dados;
	logado - email do utilizador com sessao iniciada;
	data - data da viagem a remover

Retorno:
Pre-condicoes: a!=NULL logado!=NULL data!=NULL
***********************************************/
void trataRemoveViagem(app a, char*logado,char*data){

    Login User;

    User=elementoUtilizador(a,logado);
    int x=removeViagem(User,data);
    if (x==1)
        printf("Deslocacao removida.\n");
    else if(x==2)
        printf("Data invalida.\n");
    else if (x==0)
        printf("%s nesta data nao tem registo de deslocacao.\n",getnome(User));
    else if (x==3)
        printf("%s ja nao pode eliminar esta deslocacao.\n",getnome(User));
}

/***********************************************
impimirViagem- imprime os dados de uma deslocaçao.
Parametros:
	vi - viagem a imprimir;
	L - utilizador detentor da deslocaçao;
	boleias - numero de boleias dentro da viagem;

Retorno:
Pre-condicoes: vi!=NULL L!=NULL boleias!=NULL
***********************************************/
void imprimirViagem(viagens vi,Login User,int boleias){

    int f=0;
    int k;

    printf("%s\n%s\n%s\n%s %d:%d %d %d\nLugares vagos: %d\n",getemail(User),getorigem(vi),getdestino(vi),getdata(vi),trata_horas(vi),trata_minutos(vi),trata_dura(vi),trata_lugar(vi),getvagos(vi));

    if (checkRemoverViagem(vi)==1)
        printf("Sem boleias registadas.\n");
    else
    {
        iterador itt=iteraBoleias(vi);
        printf("Boleias: ");

        for (k=0; temSeguinteIterador(itt); k++)
        {
            boleia bo=seguinteIterador(itt);
            printf("%s",getMailBol(bo));
            if(f<boleias-1)
                printf("; ");
            f++;
        }

        printf("\n");
        destroiIterador(itt);
    }

}

/***********************************************
trataListarMinhas - trata de listar as viagens do utilizador com sessao iniciada.
Parametros:
	a - aplicaçao onde estao os dados;
	logado - email do utilizador com sessao iniciada;


Retorno:
Pre-condicoes: a!=NULL logado!=NULL
***********************************************/
void trataListarMinhas(app a,char*logado){

    int i;
    Login User;
    viagens vi;
    int boleias;

    User=elementoUtilizador(a,logado);
    iterador it=iteraviagens(User);

    if(numeroViagens(User)!=0)
    {
        for (i=0; temSeguinteIterador(it)==1; i++)
        {
            vi=(viagens)seguinteIterador(it);
            boleias=trata_lugar(vi)-getvagos(vi);

            imprimirViagem(vi,User,boleias);
            printf("\n");
        }
    }

    else
        printf("%s nao tem deslocacoes registadas.\n",getnome(User));

    destroiIterador(it);
}

/***********************************************
trataListarUser - trata de listar as viagens do utilizador pedido.
Parametros:
	a - aplicaçao onde estao os dados;
	email - email do utilizador a listar;

Retorno:
Pre-condicoes: a!=NULL email!=NULL
***********************************************/
void trataListarUser(app a,char*email){

    Login User;


    if(existeUser(a,email)==1)
    {
        User=elementoUtilizador(a,email);
        if (numeroViagens(User)!=0)
            trataListarMinhas(a,email);
        else
            printf("Nao existem deslocacoes registadas para esse utilizador.\n");
    }

    else
        printf("Nao existe o utilizador dado.\n");
}

/***********************************************
trataListarData - trata de listar as viagens da data pedida.
Parametros:
	a - aplicaçao onde estao os dados;
	data - data a listar;

Retorno:
Pre-condicoes: a!=NULL data!=NULL
***********************************************/
void tratalistarData(app a,char*data,char*logado){

    int i;
    Login User;
    viagens vi;
    int boleias;
    int t=0;

    if(checkdata(data)==1)
    {
        iterador it=iteraUsers(a);
        for(i=0; temSeguinteIterador(it); i++)
        {
            User=(Login)seguinteIterador(it);
            if(numeroViagens(User)!=0)
            {
                if(existeViagem(User,data)==1)
                {
                    vi=elementoViagemUser(User,data);
                    boleias=trata_lugar(vi)-getvagos(vi);
                    t++;
                    imprimirViagem(vi,User,boleias);

                    printf("\n");
                }
            }
        }
        destroiIterador(it);

    }
    else
        printf("Data invalida.\n");
    if(t==0)
    {
        Login Aux=elementoUtilizador(a,logado);

        printf("%s nao existem deslocacoes registadas para %s.\n",getnome(Aux),data);
    }
}

/***********************************************
trataListarBoleias - trata de listar as boleias do utilizador com sessao iniciada.
Parametros:
	a - aplicaçao onde estao os dados;
	logado - utilizador com sessao iniciada;

Retorno:
Pre-condicoes: a!=NULL logado!=NULL
***********************************************/
void trataListarBoleias(app a,char*logado){

    int i,k;
    Login User;
    Login Aux;
    viagens vi;
    int boleias;

    iterador ittt=iteraUsers(a);
    Aux=elementoUtilizador(a,logado);

    if(numeroBoleias(Aux)!=0)
    {
        for (i=0; temSeguinteIterador(ittt); i++)
        {
            User=(Login)seguinteIterador(ittt);

            if(strcmp(getemail(User),logado)!=0)
            {
                iterador itt=iteraviagens(User);
                for(k=0; temSeguinteIterador(itt); k++)
                {
                    vi=(viagens)seguinteIterador(itt);
                    boleias=trata_lugar(vi)-getvagos(vi);

                    if(checkboleias(vi,logado)==1)
                    {
                        imprimirViagem(vi,User,boleias);
                        printf("\n");
                    }
                }
                destroiIterador(itt);
            }
        }
        destroiIterador(ittt);

    }

    else
        printf("%s nao tem boleias registadas.\n",getnome(Aux));

}

/***********************************************
trataBoleia - trata de adicionar uma boleia do utilizador com sessao iniciada na viagem com a data pedida.
Parametros:
	a - aplicaçao onde estao os dados;
	data - data da viagem a pedir boleia;
    email - utilizador do qual se pretende boleia;
    logado - utilizador com seesao iniciada;

Retorno:
Pre-condicoes: a!=NULL data!=NULL email!=NULL logado!=NULL
***********************************************/
void trataBoleia(app a,char*email, char*data,char*logado){

    Login User;
    viagens vi;
    Login Aux;
    boleia b;

    if(existeUser(a,email)==1)
    {
        if(checkdata(data)==1)
        {
            User=elementoUtilizador(a,email);
            if(strcmp(email,logado)!=0)
            {
                if(existeViagem(User,data)==1)
                {
                    vi=elementoViagemUser(User,data);
                    Aux=elementoUtilizador(a,logado);
                    if(checkboleiasUser(Aux,data)==0)
                    {


                        if(checkLugares(vi)!=-1)
                        {
                            b=cria_boleia(vi,logado);
                            addBoleia(vi,b);
                            addBoleiaUser(Aux,data);
                            printf("Boleia registada.\n");
                        }
                        else
                            printf("%s nao existe lugar. Boleia nao registada.\n",getnome(Aux));
                    }
                    else
                        printf("%s ja registou uma boleia nesta data. Boleia nao registada.\n",getnome(Aux));
                }
                else
                    printf("Deslocacao nao existe.\n");
            }
            else
                printf("%s nao pode dar boleia a si proprio. Boleia nao registada.\n",getnome(User));
        }
        else
            printf("Data invalida.\n");
    }
    else
        printf("Utilizador nao existente.\n");
}

/***********************************************
trataRemoveBolea - trata de remover uma boleia do utilizador com sessao iniciada da viagem com a data pedida.
Parametros:
	a - aplicaçao onde estao os dados;
	data - data a listar;
    logado - utilizador com sessao iniciada;

Retorno:
Pre-condicoes: a!=NULL data!=NULL logado!=NULL
***********************************************/
void trataRemoveBoleia(app a,char*data,char*logado){

    int x,i;

    Login User=elementoUtilizador(a,logado);
    if(checkdata(data)==1)
    {
        if(checkboleiasUser(User,data)==1)
        {
            iterador it=iteraUsers(a);
            for(x=0; temSeguinteIterador(it); x++)
            {
                Login Aux=(Login)seguinteIterador(it);
                iterador itt=iteraviagens(Aux);
                for(i=0; temSeguinteIterador(itt); i++)
                {
                    viagens vi=(viagens)seguinteIterador(itt);
                    if (strcmp(getdata(vi),data)==0)
                    {
                        if(checkboleias(vi,logado)==1)
                        {
                            removeBoleiaUser(User,data);
                            removeBoleia(vi,getemail(User));
                            printf("%s boleia retirada.\n",getnome(User));
                            break;
                        }
                        break;
                    }
                }
                destroiIterador(itt);
            }
            destroiIterador(it);
        }
        else
            printf("%s nesta data nao tem registo de boleia.\n",getnome(User));
    }
    else
        printf("Data invalida.\n");
}

/***********************************************
interpretador - trata de interpretar os comandos, e executar a respetiva acao consoante o comando dado.
Parametros:
	a - aplicaçao onde estao os dados;

Retorno:
Pre-condicoes: a!=NULL
***********************************************/
void interpretador(app a){

    Login User;

    char comando[10];
    char parametro [50];
    char linha[70];
    char datateste [10];
    int log=0;
    int codigo;
    while((1))
    {

        if (log==1)
        printf("%s",getLogado(a));
        printf("> ");
        datateste[0]='\0';
        clearbuffer(comando,parametro);
        fgets(linha,70,stdin);
        sscanf(linha,"%s %s %s", comando, parametro, datateste);
       // strcpy(mailteste,parametro);
        datateste[10]='\0';
        strcpy(comando,Maiusculas(comando));
        codigo=codificador(comando,parametro,log);

        switch(codigo)
        {
        case 1:
        {
            printf("ajuda - Mostra os comandos existentes\ntermina - Termina a execucao do programa\nregista - Regista um novo utilizador no programa\nentrada - Permite a entrada (\"login\") dum utilizador no programa\n");
            break;
        }
        case 2:
        {
            printf("ajuda - Mostra os comandos existentes\nsai - Termina a sessao deste utilizador no programa\nnova - Regista uma nova deslocacao\nlista - Lista todas ou algumas deslocacoes registadas\nboleia - Regista uma boleia para uma dada deslocacao\nretira - Retira uma dada boleia\nremove - Elimina uma dada deslocacao\n");
            break;
        }

        case 3:
        {
            trataTermina(a);
        }

        case 4:
        {
            trataRegista(a,parametro);
            break;
        }
        case 5:
        {
            if(trataEntrada(a,parametro)==1)
            {
                registaLogado(a,parametro);
                log=1;
            }

            break;
        }
        case 6:
        {
            User=elementoUtilizador(a,getLogado(a));
            printf("Fim de sessao. Obrigado %s.\n",getnome(User));
            log=0;
            break;
        }
        case 7:
        {
            trataViagem(a,getLogado(a));
            break;
        }
        case 8:
        {
            trataListarMinhas(a,getLogado(a));
            break;
        }
        case 9:
        {
            trataRemoveViagem(a,getLogado(a),parametro);
            break;
        }
        case 10:
        {
            trataBoleia(a,parametro,datateste,getLogado(a));
            break;
        }
        case 11:
        {
            trataListarBoleias(a,getLogado(a));
            break;
        }
        case 12:
        {
            if (sortr(parametro)==1)
                trataListarUser(a,parametro);
            else
                tratalistarData(a,parametro,getLogado(a));
            break;
        }
        case 13:
        {
            trataRemoveBoleia(a,parametro,getLogado(a));
            break;
        }
        default:
        {
            printf("Comando inexistente.\n");
            clearbuffer(comando,parametro);
            break;
        }
        }
    }
}


int main(){

    app a=criaAplicacao();
    interpretador(a);
    destroiAplicacao(a);
}
