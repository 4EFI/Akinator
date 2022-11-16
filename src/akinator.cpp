
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

int GuessCharacter( Node* node )
{
    if( !node->left && !node->right )
    {
        printf( "Is it %s?\n", node->value );

        if ( CheckUserAnswer() ) 
        {
            printf( "I knew it!\n" );
        } 
        else
        {
            AddCharacter( node );
        }
    }
    else
    {
        printf( "%s?\n", node->value );

        if( CheckUserAnswer() ) GuessCharacter( node->left  );
        else                    GuessCharacter( node->right );
    }

    return 1;
}

//-----------------------------------------------------------------------------

int CheckUserAnswer()
{
    char answer[ MaxStrLen ] = "";

    scanf( "%s", answer );

    if/* */( stricmp( answer,  "no" ) == 0)
    {
        return 0;
    }
    else if( stricmp (answer, "yes" ) == 0)
    {    
        return 1;
    }
    
    printf( "Uncorrect answer, please enter yes or no...\n" );
        
    return CheckUserAnswer();
}

//-----------------------------------------------------------------------------

int AddCharacter( Node* node )
{  
    ASSERT( node != NULL, 0 );

    printf( "Sorry, I don't know who you are thinking about :(\n" );
    printf( "Tell me who was your character?\n" );

    char* newCharacter = ( char* )calloc( MaxStrLen, sizeof( char ) );
    gets( newCharacter );

    if( TreeSearch( node, newCharacter ) )
    {
        printf( "I already have this character in my database, but with another definition:\n" );
        
        // Deskribe (node->tree, answer);

        return 1;
    }

    printf( "Tell me whats the difference between %s and %s\n", newCharacter, node->value );

    char* difference = ( char* )calloc( MaxStrLen, sizeof( char ) );
    gets( difference );

    TreeAddChild( node, newCharacter, LEFT_SIDE  );
    TreeAddChild( node, node->value,  RIGHT_SIDE );

    node->value = difference;

    return 1;
}

//-----------------------------------------------------------------------------

int GuessMode( Tree* tree )
{
    ASSERT( tree != NULL, 0 );

    printf( "Think about any character and I will try to guess it\n" );
    printf( "Lets start!\n" );

    GuessCharacter( &tree->headNode );

    return 1;
}

//-----------------------------------------------------------------------------
