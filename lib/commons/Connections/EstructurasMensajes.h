#define HANDSHAKE 1
#define REQUEST_DATA_NIVEL 2
#define REQUEST_POS_RECURSO 3
#define POSICION_RECURSO 4
#define REQUEST_RECURSO 5
#define CONFIRMAR_RECURSO 6
#define TERMINE_NIVEL 7
#define RECURSOS_LIBERADOS 8
#define REQUEST_INTERBLOQUEO 10
#define REQUEST_MOVIMIENTO 11
#define PERSONAJE_BLOQUEADO 12
#define TERMINE_TURNO 13
#define MORISTE_PERSONAJE 14
#define DATANIVEL 16
#define MOVIMIENTO_PERMITIDO 17
#define RECURSOS_REASIGNADOS 18
#define NOMBRE_VICTIMA 19 //CHAR DE LA VICTIMA DE INTERBLOQUEO
#define GANE 20
#define REASIGNACION_FINALIZADA 21

//#include "commons/Connections/Mensajes.h"



typedef struct  c{
	char ID[20]; //es un string, para usar strcpy
	char IP[20];
	int PORT;
	int FD;
} __attribute__ ((__packed__)) Nivel;

typedef struct  b{
	char ID[3]; //es un string, para usar strcpy
	char IP[20];
	int PORT;
	int FD;
}__attribute__ ((__packed__)) Planificador;

typedef struct a {
	char ID[3]; //es un string, para usar strcpy
	char IP[20];
	int PORT;
	int FD;
}__attribute__ ((__packed__)) Personaje;

typedef struct {
	int POS_X;
	int POS_Y;
}__attribute__ ((__packed__)) Posicion;

typedef struct {
	char IP[20];
	int PORT;
}__attribute__ ((__packed__)) Direccion;

typedef struct {
	Nivel miNivel;
	Planificador miPlanificador;
}__attribute__ ((__packed__)) Data_Nivel;


typedef struct {
	char idRecurso;
	int cant;
	char idPersonaje;
}__attribute__ ((__packed__)) Recursos;

Posicion Pos (int x, int y);
int obtenerPosX(Posicion pos);
int obtenerPosY(Posicion pos);
