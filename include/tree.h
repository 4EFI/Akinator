#ifndef TREE_H
#define TREE_H

#include "config.h"

static const Elem_t NODE_POISON = ( Elem_t )0x5E32DEAD;

//-----------------------------------------------------------------------------

struct Node
{
    Elem_t value;

    Node* left;
    Node* right;
};

//-----------------------------------------------------------------------------

struct Tree
{
    Node headNode;

    bool isEmpty;
};

int TreeCtor( Tree* tree );
int TreeDtor( Tree* tree );

int TreeSaveData( Tree* tree, const char* fileName, const char* fileTypeOpening );

//-----------------------------------------------------------------------------

#endif