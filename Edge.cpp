#include "Edge.h"

Edge::Edge(int destination, int weight)
{
    this->destination = destination;
    this->weight = weight;
    this->next = NULL;
}

int Edge::GetWeight(int destination){
    return this->destination == destination ? weight : next->GetWeight(destination);
}

void Edge::print(){
    cout << "(" << destination << ", " << weight << ") ";
    if(next != NULL)
        next->print();
}

Edge::~Edge()
{
    //dtor
}
