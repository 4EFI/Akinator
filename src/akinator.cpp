
#include "config.h"

#include <stdio.h>

#include "akinator.h"
#include "tree.h"
#include "my_assert.h"

//-----------------------------------------------------------------------------

Node* LoadAkinatorData( Node* node, FILE* file )
{
    ASSERT( node != NULL && file != NULL, NULL );
	
	char data[ MaxStrLen ] = "";
    
    char  curSym  = fgetc( file );
    Node* curNode = NULL; 

    if( curSym == '{' )
    {
        fscanf( file, "\"%[^\"]\"", data );

        //NodeCtor( curNode );
        //curNode->value = data; 
    }


    curSym = fgetc( file );

    if( curSym == '}' ) return curNode;
    if( curSym == '{' )
    {
        ungetc( curSym, file );
        TreeAddChild( LoadAkinatorData( node, file ), data, LEFT_SIDE ); 
    }


    curSym = fgetc( file );

    if( curSym == '}' ) return curNode;
    if( curSym == '{' )
    {
        ungetc( curSym, file );
        TreeAddChild( LoadAkinatorData( node, file ), data, RIGHT_SIDE ); 
    }

    return curNode;
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

