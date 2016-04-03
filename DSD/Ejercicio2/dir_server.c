/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "dir.h"

typedef enum { false, true } bool;

diccionarios* dic = NULL;

estado *
ponerasociacion_1_svc(int arg1, clave arg2, valor arg3,  struct svc_req *rqstp){
	static estado  result;
	if(dic == NULL){
		//Creamos diccionario
		diccionarios* d = (diccionarios*) malloc(sizeof(diccionarios));
		d->id = arg1;
		d->sig = NULL;
		lista* l = (lista*) malloc(sizeof(lista));
		l->a.c = strdup(arg2);
		l->a.v = strdup(arg3);
		l->sig = NULL;
		d->l = l;
		dic = d;
		result = OK;
		return &result;
	}
	else
	{
		diccionarios* aux_dic = dic;
		while(aux_dic != NULL)
		{	
			if(aux_dic->id == arg1)//Si el ID es igual a uno que ya existe
			{
				lista* aux_lista = aux_dic->l;
				while(aux_lista != NULL)//buscamos la clave
				{
					if(strcmp (aux_lista->a.c,arg2)==0)
					{
						aux_lista->a.c = strdup(arg2);
						aux_lista->a.v = strdup(arg3);
						result = Sustitucion;
						return &result;
					}
					else if(aux_lista->sig != NULL)
						aux_lista = aux_lista->sig;
					else
					{
						lista* l = (lista*) malloc(sizeof(lista));
						l->a.c = strdup(arg2);
						l->a.v = strdup(arg3);
						l->sig = NULL;
						aux_lista->sig = l;
						result = OK;
						return &result;
					}
				}

			}
			else if(aux_dic->sig != NULL)//Si no, avanzamos en la lista
				aux_dic = aux_dic->sig;
			else//En caso de no poder avanzar mas
			{
				//Creamos diccionario y lo enlazamos
				diccionarios* d = (diccionarios*) malloc(sizeof(diccionarios));
				d->id = arg1;
				d->sig = NULL;
				lista* l = (lista*) malloc(sizeof(lista));
				l->a.c = strdup(arg2);
				l->a.v = strdup(arg3);
				l->sig = NULL;
				d->l = l;
				aux_dic->sig = d;
				result = OK;
				return &result;
			}	
		}
	}
}

resultado_obtener *
obtenerasociacion_1_svc(int arg1, clave arg2,  struct svc_req *rqstp)
{
	static resultado_obtener  result;

	diccionarios* aux_dic = dic;
	while(aux_dic != NULL)
	{	
		if(aux_dic->id == arg1)//Si el ID es igual a uno que ya existe
		{
			lista* aux_lista = aux_dic->l;
			while(aux_lista != NULL)//buscamos la clave
			{
				if(strcmp (aux_lista->a.c,arg2)==0)
				{
					result.e = OK;
					result.resultado_obtener_u.v1 = strdup(aux_lista->a.v);
					return &result;
				}
				else
					aux_lista = aux_lista->sig;
			}
			result.e = NoEncontrado;
			return &result;	
		}
		else//Si no, avanzamos en la lista
			aux_dic = aux_dic->sig;
	}
	result.e = NoEncontrado;
	return &result;		
}

estado *
borrarasociacion_1_svc(int arg1, clave arg2,  struct svc_req *rqstp)
{
	static estado  result;

	if(dic == NULL)
	{
		result = NoEncontrado;
		return &result;
	}
	else
	{
		int posicion_dic = 0, posicion_list = 0;
		bool primer_dic = true, primer_lista = true;
		diccionarios* aux_dic = dic;
		diccionarios* anterior_dic = dic;
		while(aux_dic != NULL)//En caso de encontrar el id
		{
			if(aux_dic->id == arg1)//Si el ID es igual a uno que ya existe
			{
				lista* aux_lista = aux_dic->l;
				lista* anterior_lista = aux_dic->l;
				while(aux_lista != NULL)//buscamos la clave
				{
					if(strcmp (aux_lista->a.c,arg2)==0)
					{
						if(primer_lista==true)//El elemento esta en el primero
						{
							if(aux_lista->sig == NULL)//Es el único, hay que borrar todo el diccionario
							{
								if(primer_dic==true)//Es el primer diccionario
								{
									if(aux_dic->sig == NULL)//Es el único diccionario, borramos entero
									{
										printf("Vamos a elminar el unico diccionario ocn un elemento\n");
										xdr_free ((xdrproc_t) xdr_diccionarios, (diccionarios *) dic);
										dic = NULL;
									}
									else//Existe otro detrás
									{
										printf("Existe otro detras\n");
										dic = aux_dic->sig;//Asignamos el primero al siguiente del primero
										xdr_free ((xdrproc_t) xdr_diccionarios, (diccionarios *) aux_dic);//Liberamos
									}
								}
								else if(aux_dic->sig == NULL)//Es el último
								{
									printf("Ultimo elemento de un unico diccionario\n");
									xdr_free ((xdrproc_t) xdr_diccionarios, (diccionarios *) aux_dic);//Liberamos
									anterior_dic->sig = NULL;
								}
								else// Está en mitad
								{//AQUIIIIIIIIIIIIIII
									printf("Eliminamos un diccionario en mitad que tiene un solo elemento\n");
									anterior_dic->sig = aux_dic->sig;//Asignamos el sig del anterior al sig del que vamos a borrar
									aux_dic->sig = NULL;
									xdr_free ((xdrproc_t) xdr_diccionarios, (diccionarios *) aux_dic);//Liberamos
								}
							}
							else//Es el primero elemento de la lista, pero hay más
							{
								printf("Eliminamos el primer elemento de la lista y hay mas\n");
								aux_dic->l = aux_lista->sig;
								aux_lista->sig = NULL;
								xdr_free ((xdrproc_t) xdr_lista, (lista *) aux_lista);//Liberamos
							}
						}
						else if(aux_lista->sig == NULL)//Es el último elemento de la lista
						{
							printf("Ultimo elemento de la lista\n");
							anterior_lista->sig = NULL;
							xdr_free ((xdrproc_t) xdr_lista, (lista *) aux_lista);//Liberamos
						}
						else//En mitad de la lista
						{
							printf("Un elemento en mitad de la lista\n");
							anterior_lista->sig = aux_lista->sig;//Asignamos el sig del anterior al sig del que vamos a borrar
							aux_lista->sig = NULL;
							xdr_free ((xdrproc_t) xdr_lista, (lista *) aux_lista);//Liberamos
						}
						result = OK;
						return &result;
					}
					else
					{
						anterior_lista = aux_lista;
						aux_lista = aux_lista->sig;
						primer_lista = false;
					}
				}
				//Si la clave no existe pero el diccionario si
				result = NoEncontrado;
				return &result;	
			}
			else//Si no, avanzamos en la lista
			{
				anterior_dic = aux_dic;//Para borrar uno de en medio
				aux_dic = aux_dic->sig;
				primer_dic = false;
			}
		}
		//Si el ID no existe
		result = NoEncontrado;
		return &result;
	}
}

void
pintarLista()
{
	diccionarios* aux_dic = dic;
	while(aux_dic != NULL)
	{	
		printf("\n---Lista %i---\n", aux_dic->id);
		lista* aux_lista = aux_dic->l;
		while(aux_lista != NULL)
		{
			printf("El valor es: %s ; \n",aux_lista->a.c);
			aux_lista = aux_lista->sig;
		}
		aux_dic = aux_dic->sig;
	}
}

resultado_enumerar *
enumerar_1_svc(int arg1,  struct svc_req *rqstp)
{
	static resultado_enumerar  result;
	//pintarLista();
	diccionarios* aux_dic = dic;
	while(aux_dic != NULL)
	{	
		if(aux_dic->id == arg1)//Si el ID es igual a uno que ya existe
		{
			result.resultado_enumerar_u.c = aux_dic;
			result.e = OK;
			return &result;
		}
		else//Si no, avanzamos en la lista
			aux_dic = aux_dic->sig;
	}
	result.e = NoEncontrado;
	return &result;	
}


