#include "Node.h"

Node::Node(int id, int arrival, int departure, int distance, int evaluated)
{
    this->id = id;
    this->arrival = new Time(arrival);
    this->departure = new Time(departure);
    this->distance = distance;
    this->evaluated = evaluated;
    this->pred = -1;

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

int Node::Allowed(int t){ // Retorna 0 se não precisa esperar para entrar, ou o tempo a se esperar
//    cout << "Verificando se " << (t % DAY) << " cabe entre " << arrival->time << " e " << departure->time << " = " << ((t % DAY) < arrival->time ? 1 : (t % DAY) > departure->time ? 1 : 0) << endl;
    //int wait = (t % DAY) < arrival->time ? 0 : max(0, departure->time - (t % DAY));
    //if(wait > 0)
        //cout << "!!! Janela de restricao em " << id << " !!!" << endl;
    //return wait;
	
    return (t % DAY) < arrival->time ? 0 : max(0, departure->time - (t % DAY));
}

Node::~Node(){
    if(next)
        delete next;
    if(edges)
        delete edges;
    delete arrival;
    delete departure;
}
