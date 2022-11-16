
#include "config.h"

#include <stdio.h>
    
#include "tree.h"
#include "akinator.h"

int main()
{
    const char* fileAkinatorName =  "akinator_data.txt"; 
    
    Tree akinatorTree = { 0 };
    TreeCtor( &akinatorTree );

    FILE* file = fopen( fileAkinatorName, "r" );
    if(  !file  ) return 0;
    
    //LoadAkinatorData( &akinatorTree.headNode, file );

    fclose( file );

    TreeSetHead(  &akinatorTree,          "Main" );
    TreeAddChild( &akinatorTree.headNode, "Vlados", LEFT_SIDE );
    TreeAddChild( &akinatorTree.headNode, "Vla", RIGHT_SIDE );

    TreeGraphDump( &akinatorTree );

    SaveAkinatorData( &akinatorTree, fileAkinatorName );
    
    TreeDtor( &akinatorTree );
    return 1;
}

    