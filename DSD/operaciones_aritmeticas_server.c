/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "operaciones_aritmeticas.h"

int *
suma_1_svc(int arg1, int arg2,  struct svc_req *rqstp)
{

	static int  result;

	result = arg1 + arg2;

	return(&result);
}

int *
resta_1_svc(int arg1, int arg2,  struct svc_req *rqstp)
{

	static int  result;

	result = arg1 - arg2;

	return(&result);
}

int *
multiplicacion_1_svc(int arg1, int arg2,  struct svc_req *rqstp)
{

	static int  result;

	result = arg1 * arg2;

	return(&result);
}

int *
division_1_svc(int arg1, int arg2,  struct svc_req *rqstp)
{

	static int  result;

	result = arg1 / arg2;

	return(&result);
}
