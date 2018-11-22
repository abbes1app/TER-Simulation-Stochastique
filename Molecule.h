#ifndef mol_H_INCLUDED
#define mol_H_INCLUDED
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "TypeMolecule.h"


using namespace std;

class Molecule
{
public:


TypeMolecule *typMol;

struct Position
    {
        double x;
        double y;
        double z;
    };


    Position p;

Molecule();

};
#endif
