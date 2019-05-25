//
// Created by horsetif on 19-4-17.
//

#ifndef GRAPH_ALGORITHMS_ACYCLICSP_H
#define GRAPH_ALGORITHMS_ACYCLICSP_H

#include <EdgeWeightedDigraph.h>
#include <Topological.h>
#include <algorithm>
class AcyclicSP{
private:
    vector<double> distTo;
    DirectedEdge* edgeTo;
    int start_point;
public:
    AcyclicSP(EdgeWeightedDigraph G, int s){
        start_point = s;
        for(int i = 0; i<G.get_V();i++){
            distTo.push_back(INTMAX_MAX);
        }
        edgeTo = new DirectedEdge[G.get_V()];
        distTo[s] = 0.0;
        Topological top(G);
        vector<int> t_order = top.get_order();
        for(int i = top.get_order().size()-1 ; i>=0 ; i--){
            relax(G,t_order[i]);
        }
    }

    void relax(EdgeWeightedDigraph &G, int v){
        for(auto path : G.get_adj(v)){
            int w = path.to();
            if(distTo[w] > distTo[v] + path.weight){
                distTo[w] = distTo[v] + path.weight;
                edgeTo[w] = path;
            }
        }
    }

    double get_distance(int v) { return distTo[v]; }

    bool hasPathTo(int v){
        return abs(distTo[v]-INTMAX_MAX)>1e-5 ;
    }

    vector<DirectedEdge> pathTo(int v){
        vector<DirectedEdge> ans;
        if(!hasPathTo(v)) return ans;
        do{
            ans.push_back(edgeTo[v]);
            v = edgeTo[v].from();
        }while(v!=start_point);
        return ans;
    }

    ~AcyclicSP(){
        delete[] edgeTo;
    }
};

#endif //GRAPH_ALGORITHMS_ACYCLICSP_H
