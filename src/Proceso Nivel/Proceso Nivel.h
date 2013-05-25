/*
 * Proceso Nivel.h
 *
 *  Created on: 30/04/2013
 *      Author: petauriel
 */

#ifndef PROCESO_NIVEL_H_
#define PROCESO_NIVEL_H_



//listaItems = Resources (al principio)
//PersonajeEnNivel = Allocation
//RecursoPendientePersonaje = Claim
// RECURSOSDISPONIBLES = Available


//creo estructura de datos para yo:Nivel poder tener el seguimiento del personaje en mi nivel



//ESTO SIRVE PARA DEADLOCK: RECURSOSDISPONIBLES (AVAILABLE)
typedef struct t_recursos{
	char idRecurso;
	int cant;
	struct t_recursos *sig;
}t_recursos;

typedef struct PersonajeEnNivel{
	char id;
	Posicion pos;
	t_recursos *recursos;
	struct PersonajeEnNivel *sig;
	int fd;
} PersonajeEnNivel;

typedef struct RecursoPendientePersonaje{
	char idPersonaje;
	char recursoPendiente;
	struct RecursoPendientePersonaje *sig;
}RecursoPendientePersonaje;

Posicion obtenerPosRecurso(char recurso);
t_recursos* liberarRecursos(char idPersonaje);
int validarPosYRecursos(char idPersonaje, char idRecurso);
void cargarPersonajeEnNivel(Personaje* miPersonaje);
void cargarPersonajeEnPendiente(char id);
void agregarRecursoAPersonaje(char idPersonaje,char recurso);
void borrarPersonajeEnNivel(char idPersonaje);
void borrarPersonajeEnPendiente(char idPersonaje);
void aumentarRecursos(t_recursos* recursosALiberar);
void modificarPosPersonaje(char idPersonaje, int posx, int posy);
PersonajeEnNivel* buscarPersonaje(char idPersonaje);
ITEM_NIVEL* buscarItem(char idRecurso);
void agregarAListaRecursosPendientes(char idPersonaje, char recurso);
void mandarRecursosLiberados(t_recursos* recursosALiberar, int fd);
void agregarRecursosAListaItems(char idRecurso, int cant);
void reasignarRecursos(Recursos* listaRecursos);
void quitarSolicitudesDeRecurso(char idPersonaje, char idRecurso);
char buscarPersonaje_byfd(int fd);


#endif /* PROCESO_NIVEL_H_ */
