#ifndef MALLAREVOL_HPP
#define MALLAREVOL_HPP
#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"
#include "MallaInd.hpp"

class MallaRevol : public MallaInd
{
   public:
      MallaRevol(const char * archivo, unsigned nperfiles, bool textura);
};
#endif
