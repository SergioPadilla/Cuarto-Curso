#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica2.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "MallaBarrida.hpp"
#include "practica3.hpp"
#include "base.hpp"
#include "Figura.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static unsigned p3_grado_libertad_activo = 0;
static int g1=0;
static int g2=0;
static int g3=0;
static int tope1 = 10;
static int tope2 = 10;
static int tope3 = 10;
Figura * objeto = NULL;
//static nodoraiz = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void P3_Inicializar( int argc, char *argv[] ){
  objeto = new Figura(5);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool P3_FGE_PulsarTeclaNormal( unsigned char tecla ){
  bool usa = true ; // true si al acabar de procesar el evento resulta que es necesario redibujar
  switch (toupper(tecla))
  {
    case 'G' :
       p3_grado_libertad_activo = p3_grado_libertad_activo%3+1;
       break;
    case '<':
      switch (p3_grado_libertad_activo){
        case 1:
          if(g1 != 0)
            g1--;
          break;
        case 2:
          if(g2 != 0)
            g2--;
          break;
        case 3:
          if(g3 != 0)
            g3--;
          break;
      }
    case '>':
      switch (p3_grado_libertad_activo){
        case 1:
          if(g1 < tope1)
            g1++;
          break;
        case 2:
          if(g2 < tope2)
            g2++;
          break;
        case 3:
          if(g3 < tope3)
            g3++;
          break;
      }
    default:
       usa = false ;
  }
  return usa ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void P3_DibujarObjetos( unsigned modo ){
  objeto->visualizar(modo);
}
