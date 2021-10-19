#include "stdio.h"


typedef enum {
    NODE_PIPE 			= (1 << 0),
    NODE_BCKGRND 		= (1 << 1) + 1,
    NODE_SEQ 			= (1 << 2),
    NODE_REDIRECT_IN 	= (1 << 3),
    NODE_REDIRECT_OUT 	= (1 << 4),
    NODE_CMDPATH		= (1 << 5),
    NODE_ARGUMENT		= (1 << 6),
    NODE_DATA 			= (1 << 7),
} NodeType;

int main()
{
	// NODE_PIPE 			= (1 << 0),
    // NODE_BCKGRND 		= (1 << 1),
    // NODE_SEQ 			= (1 << 2),
    // NODE_REDIRECT_IN 	= (1 << 3),
    // NODE_REDIRECT_OUT 	= (1 << 4),
    // NODE_CMDPATH		= (1 << 5),
    // NODE_ARGUMENT		= (1 << 6),

    // NODE_DATA 			= (1 << 7),

	printf(" %d\n %d\n %d\n %d\n %d\n %d\n %d\n",
	NODE_PIPE,
    NODE_BCKGRND,
    NODE_SEQ,
    NODE_REDIRECT_IN,
    NODE_REDIRECT_OUT,
    NODE_CMDPATH,
    NODE_ARGUMENT
	);

    //NODE_DATA 			= (1 << 7), )
}