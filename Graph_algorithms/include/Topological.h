//
// Created by horsetif on 19-4-15.
//

#ifndef GRAPH_ALGORITHMS_TOPOLOGICAL_H
#define GRAPH_ALGORITHMS_TOPOLOGICAL_H

#include "Node.h"
#include "Digraph.h"
#include "iostream"
#include "DepthFirstOrder.h"
#include "DirectedCycle.h"
#include <EdgeWeightedDigraph.h>
class Topological{
public:
    Topological(Digraph G){
        DirectedCycle cycle(G);
        if(!cycle.hasCycle()){
            DepthFirstOrder DFS(G);
            order = DFS.get_post();
        }
    }

    Topological(EdgeWeightedDigraph G){
        DirectedCycle cycle(G);
        if(!cycle.hasCycle()){
            DepthFirstOrder DFS(G);
            order = DFS.get_post();
        }
    }
    bool isDAG(){
        return order.size()!=0 ;
    }
    vector<int> get_order(){
        return order;
    }
    ~Topological(){
    }
private:
    vector<int> order;
};

#endif //GRAPH_ALGORITHMS_TOPOLOGICAL_H
