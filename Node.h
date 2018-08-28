#ifndef NODE_H
#define NODE_H

#define DAY 1440 // dia em minutos
#define INFINITY 1440000 // válido para 1000 dias

#include <iostream>
#include <climits>
#include "Time.h"
#include "Edge.h"

using namespace std;

class Node
{
    public:
        int id;
        Time* arrival;
        Time* departure;
        int pred;
        int distance; // ~digamos~que distância aqui é tempo (4D)
        int evaluated;
        Node* next;
        Edge* edges; // Estrutura 2

        Node(int id, int arrival, int departure, int distance = INFINITY, int evaluated = 0);
        virtual ~Node();
        void AddEdge(int destination, int distance);
        void SetNext(Node* next);
        Node* GetNode(int id);
        void AddNode(Node* node);
        int Allowed(int t);
        void print();

    protected:

    private:
};

#endif // NODE_H
