#ifndef AKINATOR_H
#define AKINATOR_H

#include "config.h"

#include "tree.h"
#include "stack.h"

#include  <stdarg.h>

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

int DescribeCharacter( Node* nodeBegin, Node* nodeForDescription );

int PrintDifferencies( Tree* tree, const char* character1, const char* character2 );

int CreatePath( Tree* tree, Node* node, Stack* stk );

void SayWords (char* temp, ...);

int GuessMode       ( Tree* tree );
int DefinitionMode  ( Tree* tree );
int DifferenciesMode( Tree* tree );
int ShowDataMode    ( Tree* tree );

//-----------------------------------------------------------------------------

#endif