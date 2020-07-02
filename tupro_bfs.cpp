#include "header_tupro.h"

void createGraph(graph &G){

    G = NULL;
}

adr_node createNodeElmt(char X){

    adr_node P = new node;
    info_node(P) = X;
    next_node(P) = NULL;
    first_edge(P) = NULL;
    return P;
}

void insertLast(graph &G, adr_node &P){

    if (G == NULL){
        G = P;
    } else {
        adr_node Prec = G;
        while (next_node(Prec) != NULL){
            Prec = next_node(Prec);
        }
        next_node(Prec) = P;
    }
}

adr_node searchNode(graph G, char findInfo){

    adr_node P = G;
    bool found = false;
    while (P != NULL && !found){
        found = info_node(P) == findInfo;
        if (!found){
            P = next_node(P);
        }
    }
    if (found){
        return P;
    } else {
        return NULL;
    }
}

void addNewNode(graph &G, char X){

    adr_node P = searchNode(G, X);
    if (P == NULL){
        P = createNodeElmt(X);
        insertLast(G, P);
    }
}

adr_edge createEdgeElmt(char X){

    adr_edge P = new edge;
    info_edge(P) = X;
    next_edge(P) = NULL;
    return P;
}

void connectNodes(graph &G, char info1, char info2){

    adr_node P1 = searchNode(G, info1);
    if (P1 != NULL){
        adr_node P2 = searchNode(G, info2);
        if (P2 != NULL){
            adr_edge E = createEdgeElmt(info2);
            next_edge(E) = first_edge(P1);
            first_edge(P1) = E;
        }
    }
}

void printGraph(graph G){

    adr_node P = G;
    while (P != NULL){
        cout<<info_node(P)<<": ";
        adr_edge E = first_edge(P);
        while (E != NULL){
            cout<<info_edge(E)<<", ";
            E = next_edge(E);
        }
        P = next_node(P);
        cout<<endl;
    }
}

void addQueue(Queue &Q, char X){

    Q.info[Q.tail] = X;
    Q.tail++;
}

char deleteQueue(Queue &Q){

    char X = Q.info[0];
    int i = 0;
    int j = 1;
    while (j <= Q.tail){
        Q.info[i] = Q.info[j];
        i++;
        j++;
    }
    Q.tail--;
    return X;
}

void addVisited(Visited &V, char X){

    V.info[V.n] = X;
    V.n++;
}

bool foundInVisited(Visited V, char X){

    bool found = false;
    for (int i=0; i<V.n; i++){
        if (V.info[i] == X){
            found = true;
        }
    }
    return found;
}

void printVisited(Visited V){

    cout<<"Output: ";
    for (int i = 0; i < V.n; i++){
        cout<<V.info[i]<<", ";
    }
    cout<<endl;
}

void apply_BFS(graph G, char startNode){

    if (G != NULL){
        adr_node P = searchNode(G, startNode);
        if (P != NULL){
            Queue Q;
            Q.tail = 0;
            Visited V;
            V.n = 0;
            addQueue(Q, startNode);
            while (Q.tail > 0){
                char X = deleteQueue(Q);
                bool found = foundInVisited(V, X);
                if (!found){
                    addVisited(V, X);
                    P = searchNode(G, X);
                    adr_edge E = first_edge(P);
                    while (E != NULL){
                        addQueue(Q, info_edge(E));
                        E = next_edge(E);
                    }
                }
            }
            printVisited(V);
        }
    }
}
