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
int AddCharacter   ( Tree* tree, Node* Node );
int GuessCharacter ( Tree* tree, Node* Node );

int DescribeCharacter( Node* node, const char* character );

int ShowDataMode  ( Tree* tree );
int DefinitionMode( Tree* tree );
int GuessMode     ( Tree* tree );

//-----------------------------------------------------------------------------

#endif