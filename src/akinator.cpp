
#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#include "akinator.h"
#include "tree.h"
#include "LOG.h"
#include "my_assert.h"

//-----------------------------------------------------------------------------

Node* LoadAkinatorData( Node* node, FILE* file )
{
    ASSERT( node != NULL, NULL );
    ASSERT( file != NULL, NULL );
	
	char* data = ( char* )calloc( MaxStr, sizeof( char ) );
    
    char curSym = fgetc( file );

    if( curSym == '{' )
    {
        fscanf( file, " \"%[^\"]\" ", data );

        TreeSetNodeValue( node, data );
    }


    // Adding left child
    while( curSym = fgetc( file ) ) 
    {
        if( curSym != ' ' ) break; // skip spaces
    }    

    if( curSym == '}' ) return node;
    if( curSym == '{' )
    {
        ungetc( curSym, file );
        LoadAkinatorData( TreeAddChild( node, "", LEFT_SIDE ), file ); 
    }


    // Adding right child
    while( curSym = fgetc( file ) ) 
    {
        if( curSym != ' ' ) break; // skip spaces
    }

    if( curSym == '}' ) return node;
    if( curSym == '{' )
    {   
        ungetc( curSym, file );
        LoadAkinatorData( TreeAddChild( node, "", RIGHT_SIDE ), file );  
    }

    return node;
}

//-----------------------------------------------------------------------------

int SaveAkinatorData( Node* node, const char* fileName )
{  
    ASSERT( node != NULL && fileName != NULL, 0 );    
    
    FILE* file = fopen( fileName, "w" );
    if(  !file  ) return 0;

    PrintPreorderNodes( node, file );

    fclose( file );
    return  1;
}

//-----------------------------------------------------------------------------

