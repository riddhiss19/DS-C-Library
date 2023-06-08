Topic : Graph

Description :
	Graphs in data structures are non-linear data structures made up of a finite number of nodes or vertices and the edges that connect them. Graphs in data structures are used to address real-world problems in which it represents the problem area as a network like telephone networks, circuit networks, and social networks.

1.create graph in directed graph :
   struct Graph* create_graph_DG(int numV)
   it take one argument :
   1.number to be inserted 
  
2.Add edge in directed graph:
void add_edge_DG(struct Graph* graph, int src, int dest)
it take three argument :
1.graph  of struct type
2.source type  integer 
3.destination type integer

3.print/display directed graph:
void print_graph_DG(struct Graph* graph)
it take one argument :
1.graph  of struct type

4.depth first search in directed graph :
void DFS_DG(struct Graph* graph, int v)
it take two argument :
1.graph  of struct type
2.vertex type integer 

5.breadth  first search in directed graph :
void BFS_DG(struct Graph* graph, int v)
it take two argument :
1.graph  of struct type
2.vertex type integer 

6.create undirected Graph using adjacency list:
struct undirGraph* create_graph_UG(int num_vertices)
it take one argument:
num_vertices type interger.

7.create node in undirected Graph using adjacency list:
struct Node* create_node_UG(int data)
it take one argument:
1.data/value type integer 

8. Add edge in undirected Graph using adjacency list:
void add_edge_UG(struct undirGraph* undirGraph, int src, int dest)
it take three argument :
1.undirGraph of struct type.
2.source type  integer 
3.destination type integer

9.display element  in undirected Graph using adjacency list:
void print_graph_UG(struct undirGraph* undirGraph)
1.undirGraph of struct type.

10.breadth  first search  in undirected Graph using adjacency list:
void BFS_UG(struct undirGraph* graph, int startVertex)
it take two argument :
1.undirGraph  of struct type
2.startVertex type integer .

11.depth first search in undirected Graph using adjacency list:
void DFS_DG(struct undirGraph* graph, int vertex)
it take two argumnets:
1.undirGraph  of struct type
2.vertex type integer 







 