
#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "akinator.h"
#include "tree.h"
#include "LOG.h"
#include "my_assert.h"

//-----------------------------------------------------------------------------

int LoadAkinatorData( Node* node, FILE* file, int side )
{
    ASSERT( node != NULL, 0 );
    ASSERT( file != NULL, 0 );
	
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

    if( curSym == '}' && side == LEFT_SIDE ) return 1;
    if( curSym == '{' )
    {
        ungetc( curSym, file );
        LoadAkinatorData( TreeAddChild( node, "", LEFT_SIDE ), file, LEFT_SIDE ); 
    }


    // Adding right child
    while( curSym = fgetc( file ) ) 
    {
        if( curSym != ' ' ) break; // skip spaces
    }

    if( curSym == '}' && side == RIGHT_SIDE ) return 1;
    if( curSym == '{' )
    {   
        ungetc( curSym, file );
        LoadAkinatorData( TreeAddChild( node, "", RIGHT_SIDE ), file, RIGHT_SIDE );  
    }

    return 1;
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

int PrintAkinatorMenu()
{
    printf("Enter the number of mode...\n");

    printf("[%d] for guessing the character\n", GUESS_MODE);
    printf("[%d] for definition character\n",   DEFINITION_MODE);
    printf("[%d] for differencies mode\n",      DIFFERENCIES_MODE);
    printf("[%d] for showing the database\n",   SHOWDATA_MODE);
    printf("[%d] for exiting the game\n",       EXIT);     

    return 1;
}

//-----------------------------------------------------------------------------

int GetAkinatorGameMode( int* gameMode )
{
    ASSERT( gameMode != NULL, 0 );

    scanf( "%d", gameMode );

    return 1;
}

//-----------------------------------------------------------------------------

// Akinator Game Modes
//-----------------------------------------------------------------------------

int ShowDataMode( Tree* tree )
{
    ASSERT( tree != NULL, 0 );
    
    TreeGraphDump( tree );
    
    char cmd[ MaxStrLen ] = "";
    sprintf( cmd, "\"C://Program Files/Google/Chrome/Application/chrome\" "
                    "C:/Users/kvv20/Documents/Akinator/%s", FileTreeDumpName );
    
    system( cmd );

    return 1;
}

//-----------------------------------------------------------------------------
