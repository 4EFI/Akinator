
#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "my_assert.h"
#include "stack"

#define FREE( ptr ) \
    free( ptr );    \
    ptr = NULL;

// Node functions
//-----------------------------------------------------------------------------

int NodeCtor( Node* node )
{
    ASSERT( node != NULL, 0 );

    node->value = NODE_POISON;
    node->left  = NULL;
    node->right = NULL;

    return 1;
}  

//-----------------------------------------------------------------------------

int NodeDtor( Node* node )
{
    ASSERT( node != NULL, 0 );
    
    node->value = NODE_POISON;
    
    FREE( node->left  );
    FREE( node->right );

    return 1;
}

//-----------------------------------------------------------------------------


// Tree functions
//-----------------------------------------------------------------------------

int TreeCtor( Tree* tree )
{
    ASSERT( tree != NULL, 0 );

    tree->isEmpty = true;

    NodeCtor( &tree->headNode );

    return 1;
}

//-----------------------------------------------------------------------------

int TreeDtor( Tree* tree )
{
    ASSERT( tree != NULL, 0 );
    
    // soon

    return 1;
}

//-----------------------------------------------------------------------------

int TreeAdd( Tree* tree, Elem_t val )
{
    ASSERT( tree != NULL, 0 );



    return 1;
}

//-----------------------------------------------------------------------------

int TreeSaveData( Tree* tree, const char* fileName, const char* fileTypeOpening )
{       
    ASSERT( tree != NULL && fileName != NULL && fileTypeOpening != NULL, 0 );

    if( tree->isEmpty ) return 0;



    return 1;
}

//-----------------------------------------------------------------------------

int TreeLoadData()
{
    // ASSERT(  );
    
    return 1;
}

//-----------------------------------------------------------------------------