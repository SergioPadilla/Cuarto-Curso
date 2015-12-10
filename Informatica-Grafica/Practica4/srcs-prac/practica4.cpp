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
static int g2=1;
static int g3=0;
static int tope1 = 360;
static int tope2 = 5;
static int tope3 = 7;
static Figura * objeto = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void P4_Inicializar( int argc, char *argv[] ){
  objeto = new Figura(g1,g2,g3);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool P4_FGE_PulsarTeclaNormal( unsigned char tecla ){
  bool usa = true ; // true si al acabar de procesar el evento resulta que es necesario redibujar
  switch (toupper(tecla))
  {
    case 'G' :
       p3_grado_libertad_activo = p3_grado_libertad_activo%3+1;
       if(p3_grado_libertad_activo == 1)
          cerr << "Rotando base" << endl;
       else if(p3_grado_libertad_activo == 2)
          cerr << "Cambiando la altura del cilindro" << endl;
       else if(p3_grado_libertad_activo == 3)
          cerr << "Desplazando la pieza" << endl;
       break;
    case '<':
      switch (p3_grado_libertad_activo){
        case 1:
          if(g1 > 0){
            g1-=20;
            objeto->fijarAlpha(g1);
          }
          break;
        case 2:
          if(g2 > 1){
            g2--;
            objeto->fijarh(g2);
          }
          break;
        case 3:
          if(g3 > 0){
            g3--;
            objeto->fijart(g3);
          }
          break;
      }
      break;
    case '>':
      switch (p3_grado_libertad_activo){
        case 1:
          if(g1 < tope1){
            g1+=20;
            objeto->fijarAlpha(g1);
          }
          break;
        case 2:
          if(g2 < tope2){
            g2++;
            objeto->fijarh(g2);
          }
          break;
        case 3:
          if(g3 < tope3){
            g3++;
            objeto->fijart(g3);
          }
          break;
      }
      break;
    default:
       usa = false ;
  }
  return usa ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void P4_DibujarObjetos( unsigned modo ){
  objeto->visualizar(modo);
}
