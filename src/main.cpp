
#include "config.h"

#include <stdio.h>
    
#include "tree.h"
#include "akinator.h"

int main()
{
    const char* fileAkinatorName =  "akinator_data.txt"; 
    
    Tree akinatorTree = { 0 };
    TreeCtor( &akinatorTree );

    LoadAkinatorData( &akinatorTree, fileAkinatorName );

    TreeGraphDump( &akinatorTree );

    SaveAkinatorData( &akinatorTree, fileAkinatorName );

    TreeDtor( &akinatorTree );
    return 1;
}

    