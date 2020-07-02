#ifndef HEADER_TUPRO_H_INCLUDED
#define HEADER_TUPRO_H_INCLUDED
#include <iostream>
#define info_node(P) P->info_node
#define next_node(P) P->next_node
#define first_edge(P) P->first_edge
#define info_edge(P) P->info_edge
#define next_edge(P) P->next_edge
using namespace std;
typedef struct node *adr_node;
typedef struct edge *adr_edge;
typedef adr_node graph;

struct node{
    char info_node;
    adr_node next_node;
    adr_edge first_edge;
};
struct edge{
    char info_edge;
    adr_edge next_edge;
};
struct Queue{
    char info[100];
    int tail;
};
struct Visited{
    char info[100];
    int n;
};

void createGraph(graph &G);
adr_node createNodeElmt(char X);
void insertLast(graph &G, adr_node &P);
adr_node searchNode(graph G, char findInfo);
void addNewNode(graph &G, char X);
adr_edge createEdgeElmt(char X);
void connectNodes(graph &G, char info1, char info2);
void printGraph(graph G);
void addQueue(Queue &Q, char X);
char deleteQueue(Queue &Q);
void addVisited(Visited &V, char X);
bool foundInVisited(Visited V, char X);
void printVisited(Visited V);
void apply_BFS(graph G, char startNode);

#endif