#ifndef AKINATOR_H
#define AKINATOR_H

#include "config.h"

#include "tree.h"

//-----------------------------------------------------------------------------

int SaveAkinatorData( Tree* tree, const char* fileName );
int LoadAkinatorData( Tree* tree, const char* fileName );

//-----------------------------------------------------------------------------

#endif