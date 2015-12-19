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
static double g1=0;
static double g2=1;
static double g3=0;
static double tope1 = 360;
static double tope2 = 5;
static double tope3 = 8;
Figura * objeto = NULL;
static double v1 = 0;
static double v2 = 0;
static double v3 = 0;
static double topev = 5;
static double topev2 = 0.3;
static double topev3 = 0.25;
static bool max1 = false;
static bool max2 = false;
static bool max3 = false;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void P3_Inicializar( int argc, char *argv[] ){
  objeto = new Figura(g1,g2,g3);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool P3_FGE_PulsarTeclaNormal( unsigned char tecla ){
  bool usa = true ; // true si al acabar de procesar el evento resulta que es necesario redibujar
  if(tecla == 'v'){
    switch (p3_grado_libertad_activo){
      case 1:
        if(v1 > 1){
          v1-=1;
          cerr << "Disminuyendo velocidad de rotación de la base a: " << v1 << endl;
        }
        break;
      case 2:
        if(v2 > 0.04){
          v2-=0.02;
          cerr << "Disminuyendo velocidad de altura de la base a: " << v2 << endl;
        }
        break;
      case 3:
        if(v3 > 0.02){
          v3-=0.01;
          cerr << "Disminuyendo velocidad de desplazamiento de la pieza a: " << v3 << endl;
        }
        break;
    }
  }
  else{
    switch (toupper(tecla)){
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
    case 'V':
      switch (p3_grado_libertad_activo){
        case 1:
          if(v1 < topev){
            v1+=1;
            cerr << "Aumentando velocidad de rotación de la base a: " << v1 << endl;
          }
          break;
        case 2:
          if(v2 < topev2){
            v2+=0.02;
            cerr << "Aumentando velocidad de altura de la base a: " << v2 << endl;
          }
          break;
        case 3:
          if(v3 < topev3){
            v3+=0.01;
            cerr << "Aumentando velocidad de desplazamiento de la pieza a: " << v3 << endl;
          }
          break;
      }
      break;
    case 'C':
      switch (p3_grado_libertad_activo){
        case 1:
          v1 = 0;
          cerr << "velocidad de rotación de la base: " << v1 << endl;
          break;
        case 2:
          v2 = 0;
          cerr << "velocidad de altura de la base: " << v2 << endl;
          break;
        case 3:
          v3 = 0;
          cerr << "velocidad de desplazamiento de la pieza: " << v3 << endl;
          break;
      }
      break;
    default:
       usa = false ;
  }
  }
  return usa;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void P3_DibujarObjetos( unsigned modo ){
  objeto->visualizar(modo);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void idle(){
  //Cambio grado 1
  if(!max1){
    g1+=v1;

    if(g1 >= tope1)
      max1 = true;
  }
  else{
    g1-=v1;

    if(g1 <= 0)
      max1 = false;
  }

  //Cambio grado 2
  if(!max2){
    g2+=v2;

    if(g2 >= tope2)
      max2 = true;
  }
  else{
    g2-=v2;

    if(g2 <= 1)
      max2 = false;
  }

  //Cambio grado 3
  if(!max3){
    g3+=v3;

    if(g3 >= tope3)
      max3 = true;
  }
  else{
    g3-=v3;

    if(g3 <= 0)
      max3 = false;
  }

  objeto->fijarAlpha(g1);
  objeto->fijarh(g2);
  objeto->fijart(g3);
  glutPostRedisplay();
 }
