
#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <sttring.h>

#include "tree.h"
#include "my_assert.h"
#include "stack"

#define FREE( ptr ) \
    free( ptr );    \
    ptr = NULL;

const char* FileTreeDumpName = "tree_dump.html";
FILE* FileTreeDump = fopen( FileTreeDumpName, "w" );

//  Node functions
//-----------------------------------------------------------------------------

int NodeCtor( Node* node )
{
    ASSERT( node != NULL, 0 );

    node->value = NODE_POISON;
    node->left  = NULL;
    node->right = NULL;

    return 1;
}  

//-----------------------------------------------------------------------------

int NodeDtor( Node* node )
{
    ASSERT( node != NULL, 0 );
    
    node->value = NODE_POISON;
    
    FREE( node->left  );
    FREE( node->right );

    return 1;
}

//-----------------------------------------------------------------------------

FILE* TreeCreateDotDumpFile( Node* node, const char* fileName )
{
    ASSERT( node != NULL, NULL );

    FILE* tempDotFile = fopen( fileName, "w" );

    fprintf( tempDotFile, "digraph ListDump\n" );
    fprintf( tempDotFile, "{\n" );
    {
        int curNodeNum = 1;
        GraphVizNodes( node, tempDotFile, &curNodeNum );
    }
    fprintf( tempDotFile, "}\n" );

    return tempDotFile;
}

//-----------------------------------------------------------------------------

int GraphVizNodes( Node* node, FILE* dotFile, int* nodeNum )
{
    if( node == NULL ) return 0;

    int leftNum  = 0;
    int rightNum = 0;
    
    if/* */( node->left )
    {
        leftNum  = GraphVizNodes( node->left,  dotFile, nodeNum );
    }    
    else if( node->right )
    {
        rightNum = GraphVizNodes( node->right, dotFile, nodeNum );
    }

    fprintf( dotFile, "\tnode%d[ shape = record, style = \"filled\", fillcolor = \"lightgreen\", label = \"%s\" ];\n", 
                       *nodeNum, node->value );

    if( node->left)
    {
        fprintf( dotFile, "\t\"node%d\" -- \"node%d\"\n", *nodeNum, leftNum );
    }
    if( node->right )
    {
        fprintf( dotFile, "\t\"node%d\" -- \"node%d\"\n", *nodeNum, rightNum );
    }

    (*nodeNum)++;
    return (*nodeNum) - 1;
}

//-----------------------------------------------------------------------------


//  Tree functions
//-----------------------------------------------------------------------------

int TreeCtor( Tree* tree )
{
    ASSERT( tree != NULL, 0 );

    tree->isEmpty = true;

    NodeCtor( &tree->headNode );

    return 1;
}

//-----------------------------------------------------------------------------

int TreeDtor( Tree* tree )
{
    ASSERT( tree != NULL, 0 );
    
    // soon

    return 1;
}

//-----------------------------------------------------------------------------

int TreeSaveData( Tree* tree, const char* fileName, const char* fileTypeOpening )
{       
    ASSERT( tree != NULL && fileName != NULL && fileTypeOpening != NULL, 0 );

    if( tree->isEmpty ) return 0;



    return 1;
}

//-----------------------------------------------------------------------------

int TreeLoadData( Tree* tree )
{
    // ASSERT(  );
    
    return 1;
}

//-----------------------------------------------------------------------------

int TreeAddChild( Tree* tree, Node* node, Elem_t val, int side )
{
    ASSERT( tree != NULL && node != NULL, 0 );

    Node* newNode = ( Node* )calloc( 1, sizeof( Node ) );

    newNode->value = val;

    if/* */( side == NodeSides::LEFT_SIDE )
    {
        node->left = newNode;
    }
    else if( side == NodeSides::RIGHT_SIDE )
    {
        node->right = newNode;
    }

    return 1;
}

//-----------------------------------------------------------------------------

int TreeGraphDump( Tree* tree )
{
    ASSERT( tree != NULL, 0 );

    const char* tempDotFileName = "tempGraphVizTree.dot"; 
    FILE*       tempDotFile = TreeCreateDotDumpFile( &tree->headNode, tempDotFileName );
    fclose(     tempDotFile     );

    char graphName[MaxStrLen] = "img/graph.png";

    CreateGraphVizImg( tempDotFileName, graphName, "png" );

    // Delete temp file
    remove( tempDotFileName );

    // Create html file
    fprintf( FileTreeDump, "<pre>" );

    fprintf( FileTreeDump, "<img src = \"%s\", style = \" max-width: 95vw \">", graphName );
    fprintf( FileTreeDump, "<hr>" );

    return 1;
}

//-----------------------------------------------------------------------------

Node* TreeSearch( Node* nodeBegin, Elem_t val )
{
    ASSERT( nodeBegin != NULL, 0 );

    Node* leftNode  = NULL;
    Node* rightNode = NULL;

    if( nodeBegin->left )
    {
        leftNode  = TreeSearch( nodeBegin->left,  val );
    }
    if( nodeBegin->right )
    {
        rightNode = TreeSearch( nodeBegin->right, val );
    }

    if/* */( strcmp( nodeBegin->value, val ) == 0 ) 
    {
        return nodeBegin;
    }
    else if( leftNode  ) return leftNode;
    else if( rightNode ) return rightNode;

    return NULL;
}

//-----------------------------------------------------------------------------


//  Other functions
//-----------------------------------------------------------------------------

int CreateGraphVizImg( const char* dotFileName, const char* fileName, const char* fileType )
{
    if(dotFileName == NULL || fileName == NULL || fileType == NULL) return 0; 

    char cmd[MaxStrLen] = "";

    sprintf( cmd, "dot %s -T %s -o %s", dotFileName, fileType, fileName );
    system(  cmd  );

    return 1;
}

//-----------------------------------------------------------------------------
