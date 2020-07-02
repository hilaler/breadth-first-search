#include "header_tupro.h"

/*  Name : Hilal Ramadhan Utomo
    SID : 1301194236
    Directed Graph - Breadth First Search
*/

int main(){

    graph G;
    int X;
    char N, B, C;
    createGraph(G);
    cout<< "GRAPH - PROGRAM ASSIGNMENT" << endl;
    cout<< "by Hilal Ramadhan Utomo (1301194236)";
    cout<<endl;
    cout<<"/-----------------------------------/"<<endl;
    cout<<"|        D I R E C T O R Y          |"<<endl;
    cout<<"|-----------------------------------|"<<endl;
    cout<<"|   [1] Add a Node                  |"<<endl;
    cout<<"|   [2] Connect a node              |"<<endl;
    cout<<"|   [3] Print the remaining graph   |"<<endl;
    cout<<"|   [4] Print graph in Breadth      |"<<endl;
    cout<<"|       First Search order          |"<<endl;
    cout<<"|   [0] To end the program          |"<<endl;
    cout<<"/-----------------------------------/"<<endl;
    cout<<endl;
    cout<<" Insert your choice: ";
    cin>>X;
    cout<<endl;

    while (X != 0){
        if (X == 1){

            cout<<"Insert a new Character / Number to become a vertex:"<<endl;
            cin>>N;
            addNewNode(G, N);

        } else if (X == 2){

            cout<<"Here are the remaining graph :"<<endl;
            printGraph(G);
            cout<<"insert a source vertex:"<<endl;
            cin>>N;
            cout<<"insert a vertex to connect with "<< N <<" :"<<endl;
            cin>>C;
            connectNodes(G, N, C);

        } else if (X == 3){

            cout<<"This is the remaining graph :"<<endl;
            printGraph(G);

        } else if (X == 4){

            cout<<"Here are the remaining graph :"<<endl;
            printGraph(G);
            cout<<"insert vertex to start the BFS :"<<endl;
            cin>>B;
            apply_BFS(G, B);

        } else {
            cout<<"Sorry that is not one of the choices"<<endl;
        }

        cout<<endl;
        cout<<"/-----------------------------------/"<<endl;
        cout<<"|        D I R E C T O R Y          |"<<endl;
        cout<<"|-----------------------------------|"<<endl;
        cout<<"|   [1] Add a Node                  |"<<endl;
        cout<<"|   [2] Connect a node              |"<<endl;
        cout<<"|   [3] Print the remaining graph   |"<<endl;
        cout<<"|   [4] Print graph in Breadth      |"<<endl;
        cout<<"|       First Search order          |"<<endl;
        cout<<"|   [0] To end the program          |"<<endl;
        cout<<"/-----------------------------------/"<<endl;
        cout<<endl;
        cout<<"Insert your next choice: ";
        cin>>X;
        cout<<endl;
    }

    cout << "Thank you for your participation  ^^" << endl;
    cout<<endl;
    
    return 0;
}