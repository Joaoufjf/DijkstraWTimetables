#include "Dijkstra.h"

Dijkstra::Dijkstra(){
    instance = new Instance();
    instance->Read();
    Solve();
}

void Dijkstra::Solve(){
    //cout << "Janelas de tempo:" << endl;
    //for(Node* n = instance->nodes; n != nullptr; n = n->next)
    //    cout << n->id << " = " << n->arrival->time << " -> " << n->departure->time << endl;
    //cout << endl;

    //init
    int startTime = instance->initTime->time;

    //caso onde a primeira cidade tem restrição no horário de saída
    startTime += instance->start->Allowed(instance->initTime->time);
    instance->start->distance = startTime;
    //cout << "Hora de saída = " << startTime << " " << startTime / 1440 << ":" << (startTime / 60) %24 << ":" << startTime % 60 << endl;

    //search
    for(Node* n = instance->nodes; n != nullptr; n = n->next){ //para cada nó
        //cout << n->id << endl;
        if(!n->evaluated){ // se ainda não foi avaliado
            n->evaluated = true;
            for(Edge* e = n->edges; e != nullptr; e = e->next){ // para cada uma de suas arestas
                Node* d = instance->nodes->GetNode(e->destination); // pega o vértice destino

                int distance = n->distance + e->weight;
                //cout << " " << e->destination << " " << distance << " " << distance / 1440 << ":" << (distance / 60) %24 << ":" << distance % 60 << endl;
                distance += d->Allowed(distance);
                // > funciona, mas >= permite ver todas as possibilidades que tem mesmo custo
                if(d->distance >= distance){ // caso a distância (s, n) + (n, d) < (s, d)
                    d->distance =  distance; //distância até n + distância até d + restrição de tempo de d
                    d->pred = n->id;
                    //cout << "  Distancia de " << e->destination << " atualizada " << d->distance << endl;
                }
            }
        }
    }

    //end
    instance->PrintPath();
    int elapsed = (instance->destination->distance - instance->initTime->time);
    cout << "Tempo total = " << elapsed / 60 << ":" << elapsed % 60 << endl;
}

Dijkstra::~Dijkstra(){
    //dtor
    delete instance;
}
