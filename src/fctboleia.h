#ifndef FCTBOLEIA_H_INCLUDED
#define FCTBOLEIA_H_INCLUDED

typedef struct _app *app;

/***********************************************
criaAplicacao - criaçao de uma estrutura associada a aplicacao que contri os dados dos utilizadores.
Parametros:

Retorno: apontatdor para a instancia criada
Pre-condicoes:
***********************************************/
app criaAplicacao();

/***********************************************
destroiAplocacao - Liberta a memoria ocupada pela instancia da estrutura associada aplicacao.
Parametros:
        a - aplicacao a destruir;

Retorno:
Pre-condicoes: a!= NULL
***********************************************/
void destroiAplicacao(app a);

/***********************************************
addUtilizador - Adiciona um utilizador a aplicacao.
Parametros:
        a - aplicacao;
        L - utilizador a adicionar a aplicacao;

Retorno: 1 se adiconar; 0 caso contrario
Pre-condicoes: L!=NULL && a!=NULL
***********************************************/
int adicionaUtilizador(app ap,Login L);

/***********************************************
existeUser - Verifica se existe um dado utilizador na aplicacao.
Parametros:
        a - aplicacao;
        email - email do utilizador a verificar;

Retorno: 1 se adiconar; 0 caso contrario
Pre-condicoes: a!=NULL && email!=NULL
***********************************************/
int existeUser(app ap,char*email);

/***********************************************
elementoUtilizador - Devolve um utilizador da aplicacao.
Parametros:
        a - aplicacao;
        email - utilizador a devolver;

Retorno: o utilizador  pedido
Pre-condicoes: L!=NULL && a!=NULL
***********************************************/
Login elementoUtilizador(app ap,char*email);

/***********************************************
registaLogado - Regista na aplicacao o email do utilizador comm sessao iniciada.
Parametros:
        a - aplicacao;
        email - utilizador com sessao inicada;

Retorno:
Pre-condicoes: email!=NULL && a!=NULL
***********************************************/
void registaLogado(app ap,char*email);

/***********************************************
getLogado - Devolve o email do utilizador comm sessao iniciada.
Parametros:
        a - aplicacao;

Retorno: o utilizador com sessao iniciada
Pre-condicoes: a!=NULL
***********************************************/
char*getLogado(app ap);

/***********************************************
codificador - Codifica os comandos, para utilizacao no interpretador;
Parametros:
        comando - comando a executar;
        parametro - parametro de entrada para certos comandos,como o regista;
        log - define se o utiliar esta em modo sessao iniciada;

Retorno:Consoante o comando:
         1 - comando ajuda sem sesao iniciada;2 - comando ajuda com sessao inicada;
         3 - comando termina;4 - comando regista;5 - comando entrada;6 - comando sai;
         7 - comando nova;8 - comando listar minhas;9 - comando remove;10 - comando boleia;
         11 - comando lista boleias; 12 - comando lista data/utilizador;13 - comando retira;
         0 - caso seja comando invalido
Pre-condicoes: comando!=NULL && log!=NULL
***********************************************/
int codificador(char*comando, char*parametro,int log);

/***********************************************
Maiusculas - Transforma a string de entrada numa igual, em letras maiusculas.
Parametros:
        comando - string a transformar;

Retorno: apontador para a string transformada
Pre-condicoes: comando!=NULL
***********************************************/
char* Maiusculas(char*comando);

/***********************************************
clearbuffer - Apaga o conteudo de duas strings dadas.
Parametros:
        comando - 1a string a apagar;
        parametro -2a string a apaga;

Retorno:
Pre-condicoes: comando!=NULL && parametro!=NULL
***********************************************/
void clearbuffer(char*comando,char*parametro);

/***********************************************
checkpass - Verifca se a password verifica as condicoes necessarias
Parametros:
        pass - password a verificar;

Retorno: 1 se verificar 2 se nao
Pre-condicoes: pass!=NULL
***********************************************/
int checkpass(char *pass);

/***********************************************
checkdata - Verifca se a data verifica as condicoes necessarias
Parametros:
        data - data a verificar;

Retorno: 1 se verificar 2 se nao
Pre-condicoes: data!=NULL
***********************************************/
int checkdata(char* data);

/***********************************************
checkdados - Verifca se todos os dados para o registo de uma viagem verificam as condicoe necessarias
Parametros:
        data - data a verificar;
        lugares - numero de lugares a verificar;
        duracao - valor previsto da duracao, a verificar;
        horas - horas a verificar
        minutos - minutos a verificar

Retorno: 1 se verificar 2 se nao
Pre-condicoes: data!=NULL && lugares!=NULL && duracao!=NULL && horas!=NULL && minutos!=NULL
***********************************************/
int checkdados(char*data,int lugares,int duracao,int horas,int minutos);

/***********************************************
iteradorUsers - Cria e devolve um iterador para os utilizdores guardados na aplicacao.
Parametros:
        a - aplicacao a iterar;

Retorno: iterador dos elementos do dicionario
Pre-condicoes: a != NULL && vazioDicionario(a->utilizadores)!=1
***********************************************/
iterador iteraUsers(app a);

/***********************************************
sortr - verifica se a string contem alguma letra, para a destincao entre uma data e um email.
Parametros:
        parametro - string a verificar;

Retorno: 1 se tiver, 2 se nao
Pre-condicoes: d != NULL && vazioDicionario(d)!=1
***********************************************/
int sortr(char*parametro);

/***********************************************
destroiAllUser - destroi os dados de todos os utilizadores dentro da aplicacao.
Parametros:
    a - aplicacao

Retorno:
Pre-condicoes: d != NULL
***********************************************/
void destroiAllUser(app a);


#endif // FCTBOLEIA_H_INCLUDED
