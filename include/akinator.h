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

int SaveAkinatorData( Node* node, const char* fileName );
int LoadAkinatorData( Node* node, FILE* file, int side = 0 );

int PrintAkinatorMenu();
int GetAkinatorGameMode( int* gameMode );

int CheckUserAnswer();
int AddCharacter   ( Node* Node );
int GuessCharacter ( Node* node );

int ShowDataMode( Tree* tree );
int GuessMode   ( Tree* tree );

//-----------------------------------------------------------------------------

#endif