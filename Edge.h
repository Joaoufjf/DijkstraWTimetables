#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

class Edge
{
    public:
        int destination;
        int weight;
        Edge* next;

        Edge(int destination, int weight);
        virtual ~Edge();
        int GetWeight(int destination);
        void print();

    protected:

    private:
};

#endif // EDGE_H
