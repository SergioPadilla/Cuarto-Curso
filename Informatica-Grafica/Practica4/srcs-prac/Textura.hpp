#ifndef TEXTURA_HPP
#define TEXTURA_HPP

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"
#include "jpg_imagen.hpp"

class Textura{
public:
  GLuint id_text;    // identificador OpenGL de la textura
  jpg::Imagen * img; // puntero a imagen con los texels
  unsigned mgct;     // modo de gen. cc.tt. (0 = desactivado, 1 = objeto, 2 = camara)
  float cs[4],ct[4]; // coeficientes para generación de coords. de textura

  void activar();    // activa textura en el cauce fijo de OpenGL
  Textura(const std::string & archivoJPG, unsigned n); // crea un textura a partir de un archivo
};

#endif
