// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (declaraciones públicas)
// **
// *********************************************************************

#ifndef IG_PRACTICA1_HPP
#define IG_PRACTICA1_HPP

#include "MallaInd.hpp"

void P1_Inicializar( int argc, char *argv[] ) ;
bool P1_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P1_DibujarObjetos( unsigned modo ) ;

class Cubo : public MallaInd {
    public:
      Cubo(); //Crea tablas del cubo y le da nombre
};

class Tetraedro : public MallaInd {
    public:
      Tetraedro(); //Crea tablas del Tetraedro y le da nombre
};

class Cono : public MallaInd {
    public:
      Cono(int num); //Crea tablas del Cono y le da nombre
};

class Cilindro : public MallaInd {
    public:
      Cilindro(int num); //Crea tablas del Cono y le da nombre
};

#endif
