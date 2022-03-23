#ifndef UTILIZADORES_H_INCLUDED
#define UTILIZADORES_H_INCLUDED

typedef struct _Login*Login;

/***********************************************
cria_Log - criaçao de uma estrutura associada a uma utilizador.
Parametros:
	mail - email do utilizador;
	nome - nome do utilizador;
	pass - palavra passe do utilizador;

Retorno: apontatdor para a instancia criada
Pre-condicoes:mail!=NULL && nome!=NULL && pass!=NULL
***********************************************/
Login cria_Log (char*mail,char*nome,char*pass);

/***********************************************
destroiUser - liberta a memoria alocada para o utilizador pedido, destruindo todos os seus dados.
Parametros:
	L - utilizador a destruir;

Retorno:
Pre-condicoes:L!=NULL
***********************************************/
void destroiUser(Login L);
/***********************************************
addViagemLogin - Adiciona a viagem dada ao utilizador, se não existir uma viagem com a mesma data no mesmo utilizador.
Parametros:
	L - utilizador;
	b - viagem a adicionar;

	Retorno: Retorna 1 se adicionar, e 0, caso contrário
Pre-condicoes: L != NULL && b != NULL && data!=NULL
***********************************************/
int addViagemLogin(Login L,viagens b,char*data);

/***********************************************
elementoViagemUser- retorna o a viagem no dicionario com a data dada
Parametros:
		L - utilizador;
		data - data da viagem;

Retorno: retorna o elemento
Pre-condicoes: L != NULL && data != NULL
***********************************************/
viagens elementoViagemUser(Login L,char*data);

/***********************************************
existeViagem – Indica se viagem com a data dada existe no utilizador.
Parametros:
	L – utilizador
	data – data
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes: d != NULL && ch != NULL
***********************************************/
int existeViagem(Login L,char *data);

/***********************************************
getemail - retorna o email de um utilizador.
Parametros:
	L - utilizador na qual se pretende o email;

Retorno: string com o email;
Pre-condicoes: b!=NULL
***********************************************/
char* getemail(Login L);

/***********************************************
getnome - retorna o nome de um utilizador.
Parametros:
	L - utilizador na qual se pretende o nome;

Retorno: string com o nome
Pre-condicoes: b!=NULL
***********************************************/
char* getnome(Login L);

/***********************************************
getpass - retorna ao utilizador a password de um utilizador.
Parametros:
	L - utilizador na qual se pretende password;

Retorno: string com a password
Pre-condicoes: b!=NULL
***********************************************/
char* getpass(Login L);

/***********************************************
compPass - compara a password dada com a password do utilizador
Parametros:
	pass - password dada;
	realpass - password do utlizador

Retorno: 1 se forem iguais, 0 se nao forem
Pre-condicoes: pass!=NULL realpass!=NULL
***********************************************/
int compPass(char *pass,char *realpass);

/***********************************************
itera - Cria e devolve um iterador para as viagens gardadas no utilizador.
Parametros:
        L - utiizador

Retorno: iterador dos elementos do utilizador
Pre-condicoes: d != NULL && vazioDicionario(d)!=1
***********************************************/
iterador iteraviagens(Login L);

/***********************************************
removeViagem - Remove a vigaem com a data dada, no utilizador.
Parametros:
	L – utilizador;
	data - data da viagem a remover;

Retorno: retorna 1 se remover, 0 se nao existir a viagem, 3 caso existam lugares ocupaados, 2 caso a data seja invalida
Pre-condicoes: L!= NULL && data!= NULL
***********************************************/
int removeViagem(Login L,char*data);

/***********************************************
numeroViagens - Devolve o numero de viagens do uilizador pedido.
Parametros:
	L – utilizador;

Retorno: retorna o numero de viagens;
Pre-condicoes: L!= NULL
***********************************************/
int numeroViagens(Login L);

/***********************************************
checkBoleiasUser - Verifica a existencia de uma boleia para o utilizador dado, na data pedida.
Parametros:
	L – utilizador;
	data - data pretendida

Retorno: 1 se existir, 0 se nao
Pre-condicoes: L!= NULL && data!=NULL
***********************************************/
int checkboleiasUser(Login L,char*data);

/***********************************************
aaBoleiasUser - adiciona uma boleia ao utilizador para a data pedida.
Parametros:
	L – utilizador;
	data - data pretendida

Retorno: 1 se adicionar, 0 se nao
Pre-condicoes: L!= NULL && data!=NULL
***********************************************/
int addBoleiaUser(Login L,char*data);

/***********************************************
numeroBoleias - Devolve o numero de boleias do uilizador pedido.
Parametros:
	L – utilizador;

Retorno: retorna o numero de viagens;
Pre-condicoes: L!= NULL
***********************************************/
int numeroBoleias(Login L);

/***********************************************
removeBoleiaUser - Remove a boleia com a data dada, do utilizador.
Parametros:
	L – utilizador;
	data - data da viagem a remover;

Retorno: retorna 1 se remover, 0 caso contrario
Pre-condicoes: L!= NULL && data!= NULL
***********************************************/
int removeBoleiaUser(Login L,char*data);
#endif // UTILIZADORES_H_INCLUDED
