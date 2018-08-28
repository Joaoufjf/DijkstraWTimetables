#include "Instance.h"

Instance::Instance(){
    //ctor
}

void Instance::Read(){
    start = NULL;
    destination = NULL;

    ifstream arq("in.txt");

    int initTime_;
    arq >> nNodes >> nEdges >> nOrigin >> nDestination >> initTime_;
    initTime = new Time(initTime_);

    int id, arrival, departure;
    for(int n = 0; n < nNodes; n++){
        arq >> id >> arrival >> departure;
        Node* node;
        if(id == nOrigin){
            node = new Node(id, arrival, departure, 0);
            start = node;
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
        arq >> from >> to >> weight;
        Node* node = nodes->GetNode(from);
        node->AddEdge(to, weight);
    }

    //nodes->print();
    arq.close();
}

void Instance::PrintPath(Node* n){
    if(n == nullptr)
        n = destination;

    if(n->pred != -1)
        PrintPath(nodes->GetNode(n->pred));

    cout << "{" << n->id << ", "
        << n->distance << ", "
        << "} ";
}

Instance::~Instance(){
    if(nodes)
        delete nodes;
}
