#ifndef INSTANCE_H
#define INSTANCE_H

#include <fstream>

#include "Node.h"
#include "Time.h"

class Instance{
    public:
        Node* start;
        Node* destination;
        Node* nodes; // Estrutura 1

        int nNodes;
        int nEdges;
        Time* initTime;
        int nOrigin;
        int nDestination;

        Instance();
        virtual ~Instance();
        void Read();
        void PrintPath(Node* n = nullptr);

    protected:

    private:
};

#endif // INSTANCE_H
