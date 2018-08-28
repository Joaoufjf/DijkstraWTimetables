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

    //caso onde a primeira cidade tem restri��o no hor�rio de sa�da
    startTime += instance->start->Allowed(instance->initTime->time);
    instance->start->distance = startTime;
    //cout << "Hora de sa�da = " << startTime << " " << startTime / 1440 << ":" << (startTime / 60) %24 << ":" << startTime % 60 << endl;

    //search
    for(Node* n = instance->nodes; n != nullptr; n = n->next){ //para cada n�
        //cout << n->id << endl;
        if(!n->evaluated){ // se ainda n�o foi avaliado
            n->evaluated = true;
            for(Edge* e = n->edges; e != nullptr; e = e->next){ // para cada uma de suas arestas
                Node* d = instance->nodes->GetNode(e->destination); // pega o v�rtice destino

                int distance = n->distance + e->weight;
                //cout << " " << e->destination << " " << distance << " " << distance / 1440 << ":" << (distance / 60) %24 << ":" << distance % 60 << endl;
                distance += d->Allowed(distance);
                // > funciona, mas >= permite ver todas as possibilidades que tem mesmo custo
                if(d->distance >= distance){ // caso a dist�ncia (s, n) + (n, d) < (s, d)
                    d->distance =  distance; //dist�ncia at� n + dist�ncia at� d + restri��o de tempo de d
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
