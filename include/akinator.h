#ifndef AKINATOR_H
#define AKINATOR_H

#include "config.h"

#include "tree.h"

//-----------------------------------------------------------------------------

int   SaveAkinatorData( Node* node, const char* fileName );
Node* LoadAkinatorData( Node* node, FILE* file );

//-----------------------------------------------------------------------------

#endif