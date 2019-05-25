//
// Created by horsetif on 19-4-17.
//

#ifndef GRAPH_ALGORITHMS_DIJKSTRAALLPAIRSSP_H
#define GRAPH_ALGORITHMS_DIJKSTRAALLPAIRSSP_H

#include <DijkstraSP.h>

class DijkstraAllPairsSP{
private:
    vector<DijkstraSP*> all;

public:
    DijkstraAllPairsSP(EdgeWeightedDigraph &G){
        for(int i=0;i<G.get_V();i++){
            //cout<<"start find index: "<<i<<endl;
            DijkstraSP *p = new DijkstraSP(G,i); // 这里很重要
            all.push_back(p);
        }
    }

    vector<DirectedEdge> path(int s, int t){
        return all[s]->pathTo(t);
    }

    double dist(int s, int t){
        return all[s]->get_distance(t);
    }

    ~DijkstraAllPairsSP(){
        for(int i= 0; i<all.size(); i++){
            delete all[i];
        }
    }
};

#endif //GRAPH_ALGORITHMS_DIJKSTRAALLPAIRSSP_H
