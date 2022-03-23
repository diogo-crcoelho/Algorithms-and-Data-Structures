#ifndef DESLOCACOES_H_INCLUDED
#define DESLOCACOES_H_INCLUDED

typedef struct _viagens*viagens;

typedef struct _boleia *boleia;


/***********************************************
cria_viagem - criaçao de uma estrutura associada a uma viagem.
Parametros:
	origem - local de origem;   destino - local de destino;
	data - data da deslocacao;  hora - hora da viagem;
	minuto - minutos associados a hora; duracao - duracao prevista da viagemm;
	lugares - numero de lugares disponiveis no total;

Retorno: apontador para a instancia criada
Pre-condicoes: origem!=NULL && destino!=NULL && data!=NULL && hora!=NULL && minuto!=NULL && duracao!=NULL && lugares!=NULL
***********************************************/
viagens cria_viagem (char*origem,char*destino,char*data,int hora, int minuto, int duracao, int lugares);

/***********************************************
cria_boleia - criaçao de uma estrutura associada a uma boleia.
Parametros:
	emai - email do utilizador que regista a boleia;
	b - viagem onde e para adicionar a boleia;

Retorno: apontador para a instancia criada
Pre-condicoes: b!=NULL && email!=NULL
***********************************************/
boleia cria_boleia(viagens b,char *email);

/***********************************************
getorigem - retorna ao utilizador a origem de uma dada viagem.
Parametros:
	b - viagem na qual se pretende a origem;

Retorno: string com a origem da viagem
Pre-condicoes: b!=NULL
***********************************************/
char* getorigem(viagens b);

/***********************************************
getdestino - retorna ao utilizador o destino de uma dada viagem.
Parametros:
	b - viagem na qual se pretende o destino;

Retorno: string com a destino da viagem
Pre-condicoes: b!=NULL
***********************************************/
char* getdestino(viagens b);

/***********************************************
getdata - retorna ao utilizador a data de uma dada viagem.
Parametros:
	b - viagem na qual se pretende a data;

Retorno: string com a data da viagem
Pre-condicoes: b!=NULL
***********************************************/
char* getdata(viagens b);

/***********************************************
trata_horas - retorna ao utilizador a hora de uma dada viagem.
Parametros:
	b - viagem na qual se pretende a hora;

Retorno: inteiro com o valor da hora da viagem
Pre-condicoes: b!=NULL
***********************************************/
int trata_horas(viagens b);

/***********************************************
trata_minutos - retorna ao utilizador os minutos de uma dada viagem.
Parametros:
	b - viagem na qual se pretende os minutos;

Retorno: inteiro com o valor dos minutos da viagem
Pre-condicoes: b!=NULL
***********************************************/
int trata_minutos(viagens b);

/***********************************************
trata_dura - retorna ao utilizador a duracao prevista de uma dada viagem.
Parametros:
	b - viagem na qual se pretende a duracao;

Retorno: inteiro com o valor da duracao da viagem
Pre-condicoes: b!=NULL
***********************************************/
int trata_dura(viagens b);

/***********************************************
trata_lugar - retorna ao utilizador os lugares disponiveis para boleia de uma dada viagem.
Parametros:
	b - viagem na qual se pretende os lugares;

Retorno: inteiro com o valor dos lugares da viagem
Pre-condicoes: b!=NULL
***********************************************/
int trata_lugar(viagens b);

/***********************************************
checkboleias – Indica se a boleia associada a um dado email existe na viagem dada.
Parametros:
	b – viagem que se pretende verificar;
	email - email a verificar;
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes: d != NULL && ch != NULL
***********************************************/
int checkboleias(viagens b,char*email);

/***********************************************
addBoleia - Adiciona a boleia na viagem dada..
Parametros:
	b - viagem para adicionar;
	bo - boleia a adicionar;

	Retorno: Retorna 1 se adicionar, e 0, caso contrário
Pre-condicoes: L != NULL && b != NULL && data!=NULL
***********************************************/
int addBoleia(viagens b,boleia bo);

/***********************************************
checkRemoverViagem - verifica se o numero de lugares vagos e igual ao numero de lugares disponiveis,que verifica a possibilidade de remover a deslocacao.
Parametros:
	b - viagem na qual se pretende os lugares;

Retorno: 1 - se for igual, 0 - caso contrario
Pre-condicoes: b!=NULL
***********************************************/
int checkRemoverViagem (viagens b);

/***********************************************
itera - Cria e devolve um iterador para as boleias gardadas na viagem.
Parametros:
        b - utiizador

Retorno: iterador dos elementos da viagem
Pre-condicoes: d != NULL && vazioDicionario(d)!=1
***********************************************/
iterador iteraBoleias(viagens b);

/***********************************************
getvagos - retorna ao utilizador os lugares vagos de uma dada viagem.
Parametros:
	b - viagem na qual se pretende os lugares vagos;

Retorno: inteiro com o valor dos lugares vagos da viagem
Pre-condicoes: b!=NULL
***********************************************/
int getvagos(viagens b);

/***********************************************
getvagos - Verifica se ainda existem lugares livres.
Parametros:
	b - viagem na qual se pretende sabes se existem lugares;

Retorno: inteiro com o valor dos lugares vagos da viagem, -1 se nao houverem
Pre-condicoes: b!=NULL
***********************************************/
int checkLugares(viagens b);

/***********************************************
removeBoleia - Remove a boleia com do utilizador na viagem dada.
Parametros:
	b – viagem onde se pretende remover a boleia;
	email - email do utilizador a remove a remover;

Retorno:
Pre-condicoes: b!= NULL && email!= NULL
***********************************************/
void removeBoleia(viagens b,char*email);

/***********************************************
destroiBole - liberta a memoria alocada para para as boleias de uma dada viagem.
Parametros:
	b - viagem ode onde se pretende destruir as boleias;

Retorno:
Pre-condicoes:b!=NULL
***********************************************/
void destroiBole(viagens b);

/***********************************************
getemail - retorna o email de uma boleia.
Parametros:
	bo - boleia da qual se pretende o email;

Retorno: string com o email;
Pre-condicoes: bo!=NULL
***********************************************/
char *getMailBol(boleia bo);



#endif // DESLOCACOES_H_INCLUDED
