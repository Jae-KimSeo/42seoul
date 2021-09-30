#include "prim.h"

int main(void){
    LinkedGraph *g;
    
    g = createLinkedGraph(100);

    addVertexLG(g, 0);
    addVertexLG(g, 1);
    addVertexLG(g, 2);
    addVertexLG(g, 3);
    addVertexLG(g, 4);
    addVertexLG(g, 5);
/*
    addEdgewithWeightLG(g, 0, 1, 5);
    addEdgewithWeightLG(g, 0, 2, 3);
    addEdgewithWeightLG(g, 1, 2, 10);
    addEdgewithWeightLG(g, 2, 3, 5);
*/

    addEdgewithWeightLG(g, 0, 1, 4);
    addEdgewithWeightLG(g, 0, 2, 7);
    addEdgewithWeightLG(g, 1, 2, 2);
    addEdgewithWeightLG(g, 2, 3, 1);
    addEdgewithWeightLG(g, 3, 4, 1);
    addEdgewithWeightLG(g, 3, 5, 5);
    addEdgewithWeightLG(g, 4, 5, 6);


    //displayLinkedGraph(g);

    prim(g, 0);

    deleteLinkedGraph(g);
    return (0);
    //system("leaks a.out");
}   