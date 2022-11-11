#ifndef TREE_H
#define TREE_H

#include "config.h"

static const Elem_t NODE_POISON = ( Elem_t )0x5E32DEAD;

enum NodeSides
{
    LEFT_SIDE  = -1,
    RIGHT_SIDE =  1
};

//-----------------------------------------------------------------------------

struct Node
{
    Elem_t value;

    Node* left;
    Node* right;
};

int NodeCtor( Node* node );
int NodeDtor( Node* node );

int GraphVizNodes( Node* node, FILE* dotFile, int* nodeNum );

//-----------------------------------------------------------------------------

struct Tree
{
    Node headNode;

    bool isEmpty;
};

int TreeCtor( Tree* tree );
int TreeDtor( Tree* tree );

int TreeAddChild( Tree* tree, Node* node, Elem_t val, int side );

FILE* TreeCreateDotDumpFile( Node* node, const char* fileName );

int TreeGraphDump( Tree* tree );

int TreeSaveData( Tree* tree, const char* fileName, const char* fileTypeOpening );

//-----------------------------------------------------------------------------

int CreateGraphVizImg( const char* dotFileName, const char* fileName, const char* fileType );

//-----------------------------------------------------------------------------

#endif