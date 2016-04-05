/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "dir.h"

typedef enum { false, true } bool;

diccionarios* dict = NULL;

estado *
ponerasociacion_1_svc(int arg1, clave arg2, valor arg3,  struct svc_req *rqstp){
	static estado  result;
	if(dict == NULL){
		diccionarios* d = (diccionarios*) malloc(sizeof(diccionarios));
		d->id = arg1;
		d->next = NULL;
		lista* list = (lista*) malloc(sizeof(lista));
		list->a.key = strdup(arg2);
		list->a.value = strdup(arg3);
		list->next = NULL;
		d->list = list;
		dict = d;
		result = Correcto;
		return &result;
	}
	else{
		diccionarios* dict2 = dict;
		while(dict2 != NULL){	
			if(dict2->id == arg1){
				lista* aux_lista = dict2->list;
				while(aux_lista != NULL){
					if(strcmp (aux_lista->a.key,arg2)==0){
						aux_lista->a.key = strdup(arg2);
						aux_lista->a.value = strdup(arg3);
						result = Sustituido;
						return &result;
					}else if(aux_lista->next != NULL)
						aux_lista = aux_lista->next;
					else{
						lista* list = (lista*) malloc(sizeof(lista));
						list->a.key = strdup(arg2);
						list->a.value = strdup(arg3);
						list->next = NULL;
						aux_lista->next = list;
						result = Correcto;
						return &result;
					}
				}
			}
			else if(dict2->next != NULL)
				dict2 = dict2->next;
			else{
				diccionarios* d = (diccionarios*) malloc(sizeof(diccionarios));
				d->id = arg1;
				d->next = NULL;
				lista* list = (lista*) malloc(sizeof(lista));
				list->a.key = strdup(arg2);
				list->a.value = strdup(arg3);
				list->next = NULL;
				d->list = list;
				dict2->next = d;
				result = Correcto;
				return &result;
			}	
		}
	}
}

resultado_obtener *
obtenerasociacion_1_svc(int arg1, clave arg2,  struct svc_req *rqstp)
{
	static resultado_obtener  result;

	diccionarios* dict2 = dict;
	while(dict2 != NULL){	
		if(dict2->id == arg1){
			lista* aux_lista = dict2->list;
			while(aux_lista != NULL){
				if(strcmp (aux_lista->a.key,arg2)==0){
					result.e = Correcto;
					result.resultado_obtener_u.v1 = strdup(aux_lista->a.value);
					return &result;
				}
				else
					aux_lista = aux_lista->next;
			}
			result.e = NoEncontrado;
			return &result;	
		}
		else
			dict2 = dict2->next;
	}
	result.e = NoEncontrado;
	return &result;		
}

estado *
borrarasociacion_1_svc(int arg1, clave arg2,  struct svc_req *rqstp)
{
	static estado  result;

	if(dict == NULL){
		result = NoEncontrado;
		return &result;
	}
	else{
		int posicion_dict = 0, posicion_list = 0;
		bool primer_dict = true, primer_lista = true;
		diccionarios* dict2 = dict;
		diccionarios* anterior_dict = dict;
		while(dict2 != NULL){
			if(dict2->id == arg1){
				lista* aux_lista = dict2->list;
				lista* anterior_lista = dict2->list;

				while(aux_lista != NULL){
					if(strcmp (aux_lista->a.key,arg2)==0){
						if(primer_lista==true){
							if(aux_lista->next == NULL){
								if(primer_dict==true){
									if(dict2->next == NULL){
										xdr_free ((xdrproc_t) xdr_diccionarios, (diccionarios *) dict);
										dict = NULL;
									}
									else{
										dict = dict2->next;
										xdr_free ((xdrproc_t) xdr_diccionarios, (diccionarios *) dict2);
									}
								}
								else if(dict2->next == NULL){
									xdr_free ((xdrproc_t) xdr_diccionarios, (diccionarios *) dict2);
									anterior_dict->next = NULL;
								}
								else{
									anterior_dict->next = dict2->next;
									dict2->next = NULL;
									xdr_free ((xdrproc_t) xdr_diccionarios, (diccionarios *) dict2);
								}
							}
							else{
								dict2->list = aux_lista->next;
								aux_lista->next = NULL;
								xdr_free ((xdrproc_t) xdr_lista, (lista *) aux_lista);
							}
						}
						else if(aux_lista->next == NULL){
							anterior_lista->next = NULL;
							xdr_free ((xdrproc_t) xdr_lista, (lista *) aux_lista);
						}
						else{
							anterior_lista->next = aux_lista->next;
							aux_lista->next = NULL;
							xdr_free ((xdrproc_t) xdr_lista, (lista *) aux_lista);
						}
						result = Correcto;
						return &result;
					}
					else{
						anterior_lista = aux_lista;
						aux_lista = aux_lista->next;
						primer_lista = false;
					}
				}
				
				result = NoEncontrado;
				return &result;	
			}
			else{
				anterior_dict = dict2;
				dict2 = dict2->next;
				primer_dict = false;
			}
		}
		
		result = NoEncontrado;
		return &result;
	}
}

resultado_enumerar *
enumerar_1_svc(int arg1,  struct svc_req *rqstp)
{
	static resultado_enumerar  result;
	diccionarios* dict2 = dict;

	while(dict2 != NULL){	
		if(dict2->id == arg1){
			result.resultado_enumerar_u.c = dict2;
			result.e = Correcto;
			return &result;
		}
		else
			dict2 = dict2->next;
	}
	
	result.e = NoEncontrado;
	return &result;	
}


