#ifndef AKINATOR_H
#define AKINATOR_H

#include "config.h"

#include "tree.h"

//-----------------------------------------------------------------------------

enum AkinatorGameModes
{
    GUESS_MODE,
    DEFINITION_MODE,
    DIFFERENCIES_MODE,
    SHOWDATA_MODE,
    EXIT
};

//-----------------------------------------------------------------------------

int   SaveAkinatorData( Node* node, const char* fileName );
Node* LoadAkinatorData( Node* node, FILE* file, int side = 0 );

void PrintAkinatorMenu();

//-----------------------------------------------------------------------------

#endif