/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "dir.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

estado *
ponerasociacion_1(int arg1, clave arg2, valor arg3,  CLIENT *clnt)
{
	ponerasociacion_1_argument arg;
	static estado clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	arg.arg3 = arg3;
	if (clnt_call (clnt, PonerAsociacion, (xdrproc_t) xdr_ponerasociacion_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_estado, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

resultado_obtener *
obtenerasociacion_1(int arg1, clave arg2,  CLIENT *clnt)
{
	obtenerasociacion_1_argument arg;
	static resultado_obtener clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, ObtenerAsociacion, (xdrproc_t) xdr_obtenerasociacion_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_resultado_obtener, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

estado *
borrarasociacion_1(int arg1, clave arg2,  CLIENT *clnt)
{
	borrarasociacion_1_argument arg;
	static estado clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, BorrarAsociacion, (xdrproc_t) xdr_borrarasociacion_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_estado, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

resultado_enumerar *
enumerar_1(int arg1,  CLIENT *clnt)
{
	static resultado_enumerar clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, Enumerar,
		(xdrproc_t) xdr_int, (caddr_t) &arg1,
		(xdrproc_t) xdr_resultado_enumerar, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
