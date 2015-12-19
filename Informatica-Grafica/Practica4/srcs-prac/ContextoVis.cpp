#include "ContextoVis.hpp"

ContextoVis::ContextoVis(unsigned i, Material & mat){
  modo_vis = i;
  materialActivo = &mat;
}

ContextoVis::ContextoVis(unsigned i){
  modo_vis = i;
  materialActivo = NULL;
}
