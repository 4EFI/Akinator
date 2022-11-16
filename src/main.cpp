
#include "config.h"

#include <stdio.h>
    
#include "tree.h"
#include "akinator.h"

//-----------------------------------------------------------------------------

void ClearBuffer();

//-----------------------------------------------------------------------------

int main()
{
    const char* fileAkinatorName =  "akinator_data.txt"; 
    
    Tree akinatorTree = { 0 };
    TreeCtor( &akinatorTree );

    FILE* file = fopen( fileAkinatorName, "r" );
    if(  !file  ) return 0;

    LoadAkinatorData( &akinatorTree.headNode, file ); // Load akinator data
    fclose( file );

    // Start game
    while( true )
    {
        PrintAkinatorMenu();
        
        int gameMode = -1;
        GetAkinatorGameMode( &gameMode );

        bool isExit = false;

        switch( gameMode )
        {
        case GUESS_MODE:
            //GuessMode( &akinatortree );
            break;

        case DEFINITION_MODE:
            //DefinitionMode( &akinatortree );
            break;

        case DIFFERENCIES_MODE:
            //DifferenciesMode( &akinatortree );
            break;

        case SHOWDATA_MODE:
            ShowDataMode( &akinatorTree );
            break;

        case EXIT:
            isExit = true;
            break;
        
        default:
            ClearBuffer();
            printf( "Invalid input, please try again...\n" );
            break;
        }

        if( isExit ) break; 
    }   

    TreeGraphDump( &akinatorTree );

    SaveAkinatorData( &akinatorTree.headNode, fileAkinatorName );
    
    TreeDtor( &akinatorTree );
    return 1;
}

//-----------------------------------------------------------------------------

void ClearBuffer()
{
    while( getchar() != '\n' ) {;}
}

//-----------------------------------------------------------------------------


    