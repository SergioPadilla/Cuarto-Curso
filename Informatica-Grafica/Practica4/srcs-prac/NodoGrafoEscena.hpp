#ifndef NODOGRAFOESCENA_HPP
#define NODOGRAFOESCENA_HPP

#include <matrizg.hpp>
#include "Objeto3D.hpp"
#include <vector>
#include "matrices-tr.hpp"
#include "aux.hpp"

// Entrada del nodo del Grafo de Escena
struct EntradaNGE{
  unsigned char tipoE ; // 0=objeto, 1=transformacion, 2=material
  union{
    Objeto3D * objeto ; // ptr. a un objeto (propietario)
    Matriz4f * matriz ; // ptr. a matriz 4x4 transf. (prop.)
    Material * material; //ptr. a material
  };
  // constructores (uno por tipo)
  EntradaNGE(Objeto3D * pObjeto); // (copia solo puntero)
  EntradaNGE(const Matriz4f & pMatriz); // (crea copia)
  EntradaNGE(Material * pMaterial); // (copia solo puntero)
};

class NodoGrafoEscena : public Objeto3D{
  protected:
    std::vector<EntradaNGE> entradas; // vector de entradas
  public:
    // visualiza usando OpenGL
    virtual void visualizar(ContextoVis cv);
    // añadir una entrada (al final).
    void agregar(EntradaNGE * entrada); // genérica
    // construir una entrada y añadirla (al final)
    void agregar(Objeto3D * pObjeto); // objeto
    void agregar(const Matriz4f & pMatriz); // matriz
    void agregar(Material * pMaterial); // añadir material al final
};

#endif
