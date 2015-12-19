#ifndef CONTEXTOVIS_HPP
#define CONTEXTOVIS_HPP

#include "aux.hpp"
#include "Material.hpp"


class ContextoVis{
public:
  unsigned modo_vis ; // modo de visualización (alambre, solido,...)
  Material * materialActivo;

  ContextoVis(unsigned i, Material & mat);
  ContextoVis(unsigned i);
};

#endif
