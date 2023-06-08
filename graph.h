#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
//add appropriate system specific path for queue.h
#define SIZE 100

/*
DG-->Direct Graph
UG-->Undirected Graph

To use the functions, create structure objects
[struct Graph* for Directed Graph]
[struct undirGraph* for Undirected Graph

*/

//directed graph using adjacency list
struct Edge {
    int dest;
    struct Edge* next;
};

struct Graph {
    int numV;
    struct Edge* edges[SIZE];
    bool visited[SIZE];
};

struct Graph* create_graph_DG(int numV) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numV = numV;
    for (int i = 0; i < numV; i++) {
        graph->edges[i] = NULL;
        
        
        graph->visited[i] = false;
    }
    return graph;
}

void add_edge_DG(struct Graph* graph, int src, int dest) {
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->dest = dest;
    edge->next = graph->edges[src];
    graph->edges[src] = edge;
}

void remove_edge_DG(struct Graph* graph, int src, int dest) {
    struct Edge* current = graph->edges[src];
    struct Edge* previous = NULL;
    if(current=NULL)
        return;
    while (current != NULL) {
        if (current->dest == dest) {
            if (previous == NULL) {
                graph->edges[src] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int has_edge_DG(struct Graph* graph, int src, int dest) {
    struct Edge* current = graph->edges[src];
    while (current != NULL) {
        if (current->dest == dest) {
            printf("Edge exists from %d to %d",src,dest);
            return 1;
        }
        current = current->next;
    }
    printf("\nEdge Doesn't Exists");
    return 0;
}

void print_graph_DG(struct Graph* graph) {
    for (int i = 0; i < graph->numV; i++) {
        printf("Adjacency List of Vertex %d", i);
        struct Edge* current = graph->edges[i];
        while (current != NULL) {
            printf(" ->%d", current->dest);
            current = current->next;
        }
        printf("\n");
    }
}

void DFS_DG(struct Graph* graph, int v) {
    for(int i=0;i<graph->numV;i++)
         graph->visited[i] = false;
    graph->visited[v] = true;
    printf("%d ", v);
    struct Edge* adj = graph->edges[v];
    while (adj != NULL) {
        int adj_v = adj->dest;
        if (!graph->visited[adj_v]) {
            DFS_DG(graph, adj_v);
        }
        adj = adj->next;
    }

}

void BFS_DG(struct Graph* graph, int v) {
    for(int i=0;i<graph->numV;i++)
         graph->visited[i] = false;
    int head,tail;
    int q[SIZE];
    create_SEQ(&head,&tail);
    graph->visited[v] = true;
    insert_SEQ(q,&tail,v);
    while (!isEmpty_SEQ(head,tail)) {
        int v = delete_SEQ(q,&head);
        printf("\nVisited vertex %d ", v);
        struct Edge* adj = graph->edges[v];
        while (adj != NULL) {
            int adj_v = adj->dest;
            if (!graph->visited[adj_v]) {
                graph->visited[adj_v] = true;
                insert_SEQ(q,&tail,adj_v);
            }
            adj = adj->next;
        }
    }
}

//undirected Graph using adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct undirGraph {
    int num_vertices;
    struct AdjList* arr;
    struct Node* edges[SIZE];
    bool visited[SIZE];
};

struct undirGraph* create_graph_UG(int num_vertices) {
    struct undirGraph* undirGraph = (struct undirGraph*)malloc(sizeof(struct undirGraph));
    undirGraph->num_vertices = num_vertices;
    undirGraph->arr = (struct AdjList*)malloc(num_vertices * sizeof(struct AdjList));
    for (int i = 0; i < num_vertices; i++) {
        undirGraph->arr[i].head = NULL;
        undirGraph->visited[i] = false;
    }
    return undirGraph;
}

struct Node* create_node_UG(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void add_edge_UG(struct undirGraph* undirGraph, int src, int dest) {
    struct Node* newNode = create_node_UG(dest);
    newNode->next = undirGraph->arr[src].head;
    undirGraph->arr[src].head = newNode;
    newNode = create_node_UG(src);
    newNode->next = undirGraph->arr[dest].head;
    undirGraph->arr[dest].head = newNode;
}
void remove_edge_UG(struct undirGraph* graph, int src, int dest) {
    struct Node* curr = graph->arr[src].head;
    struct Node* prev = NULL;
    while (curr != NULL && curr->data != dest) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("\nInvalid vertex");
        return;
    }
    if (prev == NULL) {
        graph->arr[src].head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    curr = graph->arr[dest].head;
    prev = NULL;
    while (curr != NULL && curr->data != src) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        return;
    }
    if (prev == NULL) {
        graph->arr[dest].head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}


void print_graph_UG(struct undirGraph* undirGraph) {
    for (int i = 0; i < undirGraph->num_vertices; i++) {
        struct Node* ptr = undirGraph->arr[i].head;
        printf("Adjacency list of vertex %d", i);
        while (ptr) {
            printf("->%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void BFS_UG(struct undirGraph* undirGraph, int startVertex)
{
    for(int i=0;i<undirGraph->num_vertices;i++)
         undirGraph->visited[i] = false;
    int head,tail;
    int q[SIZE];
    create_SEQ(&head,&tail);
    undirGraph->visited[startVertex] = true;
    insert_SEQ(q,&tail,startVertex);
    while (!isEmpty_SEQ(head,tail)) 
    {
         int currentVertex = delete_SEQ(q,&head);
        printf("Visited vertex %d\n", currentVertex);
        struct Node* temp = undirGraph->arr[currentVertex].head;
        while (temp!=NULL)
        {
            int adjacentVertex = temp->data;
            if (!undirGraph->visited[adjacentVertex])
            {
                undirGraph->visited[adjacentVertex] = true;
                insert_SEQ(q,&tail,adjacentVertex);
            }
            temp = temp->next;
        }
    }
}

void DFS_UG(struct undirGraph* undirGraph, int vertex) {
    printf("Visited %d\n", vertex);
    undirGraph->visited[vertex] = true;
     struct Node* temp = undirGraph->arr[vertex].head;
    while (temp) {
        int connectedVertex = temp->data;
        if (!undirGraph->visited[connectedVertex]) {
            DFS_UG(undirGraph, connectedVertex);
        }
        temp = temp->next;
    }
}

//undirected graph representation using adjecency matrix
int undir[SIZE][SIZE];
int undir_matrix(int n)
{
  int max_edges=n*(n-1)/2;
  int origin,destin,i,j;
  for(i=1; i<=max_edges; i++)
        {
                printf("\nEnter edge [ %d ] ( -1 -1 to quit ) : ",i);
                scanf("%d %d",&origin,&destin);
                if( (origin == -1) && (destin == -1) )
                        break;
                if( origin>=n || destin>=n || origin<0 || destin<0 )
                {
                        printf("\nInvalid vertex!\n");
                        i--;
                }
                else
                {
                        undir[origin][destin] = 1;            
                        undir[destin][origin] = 1;
                }
        }
        printf("\nThe adjacency matrix is :: \n");
        for(i=0; i<=n-1; i++)
        {
                for(j=0; j<=n-1; j++)
                        printf("  %d",undir[i][j]);
                printf("\n");
        }
}

//directed graph representation using adjecency matrix
int dir[SIZE][SIZE];
int dir_matrix(int n)
{
  int max_edges=n*(n-1);
  int origin,destin,i,j;
  for(i=1; i<=max_edges; i++)
        {
                printf("\nEnter edge [ %d ] ( -1 -1 to quit ) : ",i);
                scanf("%d %d",&origin,&destin);
                if( (origin == -1) && (destin == -1) )
                        break;
                if( origin>=n || destin>=n || origin<0 || destin<0 )
                {
                        printf("\nInvalid vertex!\n");
                        i--;
                }
                else
                {
                        dir[origin][destin] = 1;            
                }
        }
        printf("\nThe adjacency matrix is :: \n");
        for(i=0; i<=n-1; i++)
        {
                for(j=0; j<=n-1; j++)
                        printf("  %d",dir[i][j]);
                printf("\n");
        }
}