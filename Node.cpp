#include "Node.h"

Node::Node(int id, int arrival, int departure, int distance, int evaluated)
{
    this->id = id;
    this->arrival = new Time(arrival);
    this->departure = new Time(departure);
    this->distance = distance;
    this->evaluated = evaluated;

    next = NULL;
    edges = NULL;
}

void Node::AddEdge(int destination, int distance){
    Edge* edge = new Edge(destination, distance);

    if(edges == NULL) // se é a primeira aresta
        edges = edge;
    else{
        Edge* e = edges;

        while(e->next != NULL) // próxima aresta "vaga"
            e = e->next;

        e->next = edge;
    }
}

void Node::SetNext(Node* next){
    this->next = next;
}

Node* Node::GetNode(int id){
    return this->id == id ? this : next->GetNode(id);
}

void Node::AddNode(Node* node){
    if(next == NULL)
        next = node;
    else
        next->AddNode(node);
}

void Node::print(){
    cout << "{" << id << ", "
        << arrival->get() << " -> " << departure->get() << ", "
        << pred << ", "
        << distance << ", "
        << evaluated << ", ";
        if(edges != NULL)
            edges->print();
        cout << "}" << endl;

    if(next != NULL)
        next->print();
}

Node::~Node()
{
    //dtor
}
