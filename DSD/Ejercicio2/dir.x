/* dir.x : Protocolo de listado de directorio remoto */

typedef string clave<10>;
typedef string valor<10>;

enum estado{
	OK = 0,
	Sustitucion = 1,
	NoEncontrado = 2
};

struct asociacion{
	clave c;
	valor v;
};

struct lista{
	asociacion a;
	lista* sig;
};

struct diccionarios{
	int id;
	lista* l;
	diccionarios* sig;	
};

union resultado_obtener 
switch (estado e) {
	case 0:
		valor v1;
	default:
		void;
};

union resultado_enumerar 
switch (estado e) {
	case 0:
		diccionarios* c;
	default:
		void;
};

program DIRPROG {
	version DIRVER {
		estado PonerAsociacion(int,clave,valor) = 1;
		resultado_obtener ObtenerAsociacion(int,clave) = 2;
		estado BorrarAsociacion(int,clave) = 3;
		resultado_enumerar Enumerar(int) = 4;
	} =1;
} = 0x20000155;



