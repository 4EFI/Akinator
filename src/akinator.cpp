
#include "config.h"

#include <stdio.h>

#include "akinator.h"
#include "tree.h"
#include "my_assert.h"

//-----------------------------------------------------------------------------

int LoadAkinatorData( Tree* tree, const char* fileName )
{
    ASSERT( tree != NULL && fileName != NULL, 0 );

    

    return 1;
}

//-----------------------------------------------------------------------------

int SaveAkinatorData( Tree* tree, const char* fileName )
{  
    ASSERT( tree != NULL && fileName != NULL, 0 );    
    
    FILE* file = fopen( fileName, "w" );
    if(  !file  ) return 0;

    PrintPreorderNodes( &tree->headNode, file );

    fclose( file );
    return  1;
}

//-----------------------------------------------------------------------------

