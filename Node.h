#ifndef NODE_H
#define NODE_H

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
        int distance;
        int evaluated;
        Node* next;
        Edge* edges; // Estrutura 2

        Node(int id, int arrival, int departure, int distance = INT_MAX, int evaluated = 0);
        virtual ~Node();
        void AddEdge(int destination, int distance);
        void SetNext(Node* next);
        Node* GetNode(int id);
        void AddNode(Node* node);
        void print();

    protected:

    private:
};

#endif // NODE_H
