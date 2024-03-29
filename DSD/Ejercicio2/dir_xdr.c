/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "dir.h"

bool_t
xdr_clave (XDR *xdrs, clave *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, 10))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_valor (XDR *xdrs, valor *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, 10))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_estado (XDR *xdrs, estado *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_asociacion (XDR *xdrs, asociacion *objp)
{
	register int32_t *buf;

	 if (!xdr_clave (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_valor (xdrs, &objp->value))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_lista (XDR *xdrs, lista *objp)
{
	register int32_t *buf;

	 if (!xdr_asociacion (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->next, sizeof (lista), (xdrproc_t) xdr_lista))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_diccionarios (XDR *xdrs, diccionarios *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->list, sizeof (lista), (xdrproc_t) xdr_lista))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->next, sizeof (diccionarios), (xdrproc_t) xdr_diccionarios))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_resultado_obtener (XDR *xdrs, resultado_obtener *objp)
{
	register int32_t *buf;

	 if (!xdr_estado (xdrs, &objp->e))
		 return FALSE;
	switch (objp->e) {
	case 0:
		 if (!xdr_valor (xdrs, &objp->resultado_obtener_u.v1))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_resultado_enumerar (XDR *xdrs, resultado_enumerar *objp)
{
	register int32_t *buf;

	 if (!xdr_estado (xdrs, &objp->e))
		 return FALSE;
	switch (objp->e) {
	case 0:
		 if (!xdr_pointer (xdrs, (char **)&objp->resultado_enumerar_u.c, sizeof (diccionarios), (xdrproc_t) xdr_diccionarios))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_ponerasociacion_1_argument (XDR *xdrs, ponerasociacion_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_clave (xdrs, &objp->arg2))
		 return FALSE;
	 if (!xdr_valor (xdrs, &objp->arg3))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_obtenerasociacion_1_argument (XDR *xdrs, obtenerasociacion_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_clave (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_borrarasociacion_1_argument (XDR *xdrs, borrarasociacion_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_clave (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}
