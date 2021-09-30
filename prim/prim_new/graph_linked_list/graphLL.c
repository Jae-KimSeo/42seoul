#include "graphLL.h"

LinkedGraph* createLinkedGraph(int maxVertexCount){
    LinkedGraph* pReturn = NULL;
    if (maxVertexCount > 0)
    {
        pReturn = (LinkedGraph*)malloc(sizeof(LinkedGraph));
        pReturn->graphType = GRAPH_UNDIRECTED;
        pReturn->maxVertexCount = maxVertexCount;
    }
    else 
    {
        printf("You Must Checking maxVertexCount!\n");
		return (NULL);
    }
    pReturn->currentEdgeCount = 0;
    pReturn->currentVertexCount = 0;
    pReturn->pVertex = (int*)malloc(sizeof(int) * maxVertexCount);
	memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    /*
	pReturn->ppAdjEdge = (ListNode**)malloc(sizeof(ListNode*) * maxVertexCount);
    pReturn->ppAdjEdge[0] = NULL;
    */

    pReturn->ppAdjEdge = (ListNode**)malloc(sizeof(ListNode*) * maxVertexCount);
	
	for (int i = 0; i < maxVertexCount; i++)
		pReturn->ppAdjEdge[i] = NULL;
    
	return (pReturn);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount){
     LinkedGraph* pReturn = NULL;
    createLinkedGraph(maxVertexCount);
    pReturn->graphType = GRAPH_DIRECTED;
   
	return (pReturn);
}

int isEmptyLG(LinkedGraph* pGraph){
    int flag = FALSE;

	if (pGraph != NULL)
	{
		if (pGraph->currentVertexCount == 0)
			flag = TRUE;
	}
	return (flag);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID){
    ListNode *newVertexNode;
    int flag = FAIL;

    if (pGraph == NULL)
        return flag;

    if (checkVertexValid(pGraph, vertexID) == FALSE && pGraph->currentVertexCount < pGraph->maxVertexCount){
        
        int i = 0;
        while (pGraph->ppAdjEdge[i] != NULL){
            i++;
        }
        pGraph->pVertex[vertexID] = USED;
        newVertexNode = node_init(vertexID, '\0');
        pGraph->currentVertexCount++;
        pGraph->ppAdjEdge[i] = newVertexNode;
        flag = SUCCESS;
        
    }
    else{
		printf("This Node is Now Existing or Exceeded the MaxVertexCount!\n");
    }
    return flag;
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
    return addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, 1);
}

int findGraphNodePosition(ListNode* pList, int vertexID){
    
    if (pList == NULL)
        return FAIL;
    if (pList->to_vertex == '\0')
        return FAIL;
    while(pList != NULL){
        if (pList->to_vertex == vertexID)
            return SUCCESS;
        pList->link = pList;
    }
    return FAIL;
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	int flag = FAIL;
    int i = 0;
    ListNode* curr;

    if (pGraph == NULL)
         return flag;   
    if (checkVertexValid(pGraph, fromVertexID) != TRUE || checkVertexValid(pGraph, toVertexID) != TRUE){
        	printf("toVertexID or fromVertexID is Non-Existing!\n");
            return flag;
    }

    while(pGraph->ppAdjEdge[i]){
        curr = pGraph->ppAdjEdge[i];
        if (curr->from_vertex == fromVertexID){
            
            break;
        } 
        i++;
    }
    
    if (findGraphNodePosition(curr, toVertexID) == SUCCESS){
        printf("edge already exist");
        return flag;
    }
  //****************
 /*
        if (curr->to_vertex == '\0'){
            set_to_vertex(curr, toVertexID);
            curr->weight = weight;
            
        }
        else {
            */
            while(curr->link){
                curr = curr->link;
            }
            ListNode *new;
            new = node_init(fromVertexID, toVertexID);
            new->weight = weight;
            curr->link = new;
            
        //*****************
            flag = SUCCESS;
            pGraph->currentEdgeCount++;
        
            if(pGraph->graphType == GRAPH_UNDIRECTED){
                ListNode *to_new;
    
                int j = 0;
                while(pGraph->ppAdjEdge[j]){
                    curr = pGraph->ppAdjEdge[j];
                    if (curr->from_vertex == toVertexID){
                        break;
                    } 
                    j++;
                }
                while(curr->link){
                    curr = curr->link;
                }
                to_new = node_init(toVertexID, fromVertexID);
                to_new->weight = weight;
                curr->link = to_new;

            }
            curr = pGraph->ppAdjEdge[i];
            return (flag);
}


int checkVertexValid(LinkedGraph* pGraph, int vertexID){
    
    if (pGraph->pVertex[vertexID] == USED) 
        return TRUE;
    return FALSE;
    /*
    ListNode **curr;
    ListNode *curr_vertex;

    curr = pGraph->ppAdjEdge;
    while (curr != NULL){
        curr_vertex = *(curr);
        if (curr_vertex->from_vertex == vertexID)
            return TRUE;
        curr++;
    }
    */
}

// Get EdgeCount
int getEdgeCountLG(LinkedGraph* pGraph){
    return pGraph->currentEdgeCount;
}

// Get VertexCount
int getVertexCountLG(LinkedGraph* pGraph){
    return pGraph->currentVertexCount;
}

// Get MaxVertexCount
int getMaxVertexCountLG(LinkedGraph* pGraph){
    return pGraph->maxVertexCount;
}

// Get GraphType
int getGraphTypeLG(LinkedGraph* pGraph){
    return pGraph->graphType;
}

void displayLinkedGraph(LinkedGraph* pGraph){
    ListNode *curr;

    int i = 0;
    if (pGraph == NULL)
        {
            printf("no GRAPH!");
            return ;
        }

    while(pGraph->ppAdjEdge[i]){
        curr = pGraph->ppAdjEdge[i];
        printf("Linked with %d vertex \n", curr->from_vertex);
        while(curr->link != NULL){
            curr = curr->link;
            printf("vertex : %d, weight : %d \n", curr->to_vertex, curr->weight);
        }
        printf("maxVertex : %d, currentVertex : %d, currentEdge : %d ", pGraph->maxVertexCount, pGraph->currentVertexCount, pGraph->currentEdgeCount);
        if (pGraph->graphType == GRAPH_UNDIRECTED)
            printf("this graph is UNDIRECTED");
        else
            printf("this graph is DIRECTED");
        printf("\n");
        i++;
    }
    printf("Vertex_list : ");
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        if (pGraph->pVertex[i] == USED)
            printf("%d ", i);
    }
    printf("\n");
}

void deleteLinkedGraph(LinkedGraph* pGraph){
    if (pGraph != NULL)
	{
		for (int i = 0; i < pGraph->maxVertexCount; i++){
			if (pGraph->ppAdjEdge[i] == NULL)
                break;
            removeVertexLG(pGraph, pGraph->ppAdjEdge[i]->from_vertex);
        }
        free(pGraph->ppAdjEdge[0]); // vertex지우는 방식은 지우고 뒤의 것을 현재 vertex로 붙여주는 형태, 다 지우고나면 마지막 null이 index 0 vertex에 남는다.
        free(pGraph->pVertex);
		free(pGraph->ppAdjEdge);
	    free(pGraph);
	}
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID){
    if (checkVertexValid(pGraph, vertexID) == FALSE)
        return FAIL;
    int i = 0;
    while (pGraph->ppAdjEdge[i]){
        if (pGraph->ppAdjEdge[i]->from_vertex == vertexID){
            break;
        }
        i++;
    }

    ListNode *tmp;
    while (pGraph->ppAdjEdge[i]->link != NULL){
        tmp = pGraph->ppAdjEdge[i];
        removeEdgeLG(pGraph, tmp->link->from_vertex, tmp->link->to_vertex);
        //tmp = pGraph->ppAdjEdge[i];
    }
    tmp = pGraph->ppAdjEdge[i];
    while (pGraph->ppAdjEdge[i]){
        pGraph->ppAdjEdge[i] = pGraph->ppAdjEdge[i + 1];
        i++;
    }
    free(tmp);
    pGraph->pVertex[vertexID] = NOT_USED;
    pGraph->currentVertexCount--;
    return (SUCCESS);
}
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
    ListNode *curr;

    if (checkVertexValid(pGraph, fromVertexID) == FALSE || checkVertexValid(pGraph, toVertexID) == FALSE)
        return (FAIL);
        
    int i = 0;
    while (pGraph->ppAdjEdge[i]){
        if (pGraph->ppAdjEdge[i]->from_vertex == fromVertexID){
            deleteGraphNode(pGraph->ppAdjEdge[i], toVertexID);
            break;
        }
        i++;
    }
    if (pGraph->graphType == GRAPH_UNDIRECTED){
        i = 0;
        while (pGraph->ppAdjEdge[i]){
            if (pGraph->ppAdjEdge[i]->from_vertex == toVertexID){
                deleteGraphNode(pGraph->ppAdjEdge[i], fromVertexID);
                break;
            }
            i++;
        }
    }
    pGraph->currentEdgeCount--;
    return (SUCCESS);
}
void deleteGraphNode(ListNode* pList, int delVertexID){
    ListNode *prev;
    ListNode *tmp;


    if (pList == NULL && pList->link == NULL)
        return ;
 
   // findGraphNodePosition(pList, delVertexID);

    while (pList->link){
        prev = pList;
        pList = pList->link;
    if (pList->to_vertex == delVertexID){
        tmp = pList;
        pList = pList->link; 
        prev->link = pList;
        free(tmp);
        break;
    }   
    }
}


ListNode *getNodeFromVertex(LinkedGraph* pGraph, element vertex){
    int i = 0;
    

    if (!(checkVertexValid(pGraph, vertex)))
        return NULL;
    while(pGraph->ppAdjEdge[i]){
        if (pGraph->ppAdjEdge[i]->from_vertex == vertex)
            return pGraph->ppAdjEdge[i];
        i++;
    }

    return NULL;
}