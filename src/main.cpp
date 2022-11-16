
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
    
    LoadAkinatorData( &akinatorTree.headNode, file );

    fclose( file );

    TreeGraphDump( &akinatorTree );

    SaveAkinatorData( &akinatorTree.headNode, fileAkinatorName );
    
    TreeDtor( &akinatorTree );
    return 1;
}

    