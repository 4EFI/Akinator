
#include "config.h"

#include <stdio.h>
    
#include "tree.h"
#include "akinator.h"

int main()
{
    Tree       akinatorTree = { 0 };
    TreeCtor( &akinatorTree );

    akinatorTree.headNode.value = "Unknown who";

    TreeGraphDump( &akinatorTree );

    

    TreeDtor( &akinatorTree );
}

    