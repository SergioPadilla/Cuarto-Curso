#include "base.hpp"

Base::Base(){
  nombre_obj = "Base";
  Tupla3f a(-1,0,1), b(-1,0,-1), c(1,0,-1), d(1,0,1), e(-1,0.5,1), f(-1,0.5,-1), g(1,0.5,-1), h(1,0.5,1);
  vertices.push_back(a);
  vertices.push_back(b);
  vertices.push_back(c);
  vertices.push_back(d);
  vertices.push_back(e);
  vertices.push_back(f);
  vertices.push_back(g);
  vertices.push_back(h);
  Tupla3i i1(0,7,4), i2(0,3,7), i3(3,6,7), i4(3,2,6), i5(2,5,6), i6(2,1,5), i7(1,4,5), i8(1,0,4), i9(4,6,7), i10(4,6,5),
            i11(0,2,1),i12(0,3,2);
  caras.push_back(i1);
  caras.push_back(i2);
  caras.push_back(i3);
  caras.push_back(i4);
  caras.push_back(i5);
  caras.push_back(i6);
  caras.push_back(i7);
  caras.push_back(i8);
  caras.push_back(i9);
  caras.push_back(i10);
  caras.push_back(i11);
  caras.push_back(i12);
}
