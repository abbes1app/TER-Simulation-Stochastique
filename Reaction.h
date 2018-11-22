
#ifndef reac_H_INCLUDED
#define reac_H_INCLUDED
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "TypeMolecule.h"


using namespace std;

class Reaction

{

public:

  TypeMolecule *A ;
  TypeMolecule *B ;
  TypeMolecule *C ;
  TypeMolecule *D ;
  float proba ;

Reaction();
};
#endif
