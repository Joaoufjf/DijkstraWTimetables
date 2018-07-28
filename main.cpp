#include <iostream>

#include "Node.h"

using namespace std;

Node* origin;
Node* destination;
Node* nodes; // Estrutura 1

void Read(){
    origin = NULL;
    destination = NULL;

    int nNodes;
    int nEdges;
    int initTime;
    int nOrigin;
    int nDestination;

    cin >> nNodes >> nEdges >> nOrigin >> nDestination >> initTime;

    int id, arrival, departure;
    for(int n = 0; n < nNodes; n++){
        cin >> id >> arrival >> departure;
        Node* node;
        if(id == nOrigin){
            node = new Node(id, arrival, departure, 0, 1);
            origin = node;
        }
        else{
            node = new Node(id, arrival, departure);
            if(id == nDestination)
                destination = node;
        }

        if(nodes == NULL)
            nodes = node;
        else
            nodes->AddNode(node);
    }

    int from, to, weight;
    for(int e = 0; e < nEdges; e++){
        cin >> from >> to >> weight;
        Node* node = nodes->GetNode(from);
        node->AddEdge(to, weight);
    }

    nodes->print();
}

int main()
{
    Read();
    return 0;
}
