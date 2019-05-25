//
// Created by horsetif on 19-4-16.
//

#ifndef GRAPH_ALGORITHMS_KRUSKALMST_H
#define GRAPH_ALGORITHMS_KRUSKALMST_H

#include <EdgeWeightedGraph.h>
#include <queue>
#include <UF.h>

class KruskalMST{
public:
    KruskalMST(EdgeWeightedGraph &G){
        priority_queue<Edge,vector<Edge>,greater<Edge>> que;
        for(auto t : G.edges()) que.push(t);
        UF uf(G.get_V());
        while(!que.empty() && mst.size()<G.get_V()){
            Edge temp = que.top();
            que.pop();
            int v = temp.either(), w = temp.other(v);
            if(uf.connected(v,w)) continue;
            uf._union(v,w);
            mst.push_back(temp);
        }
    }
    vector<Edge> edge(){ return mst; }
    double weight(){
        double ans = 0;
        for(auto t : mst){
            ans += t.weight;
        }
        return ans;
    }

private:
    vector<Edge> mst;
};

#endif //GRAPH_ALGORITHMS_KRUSKALMST_H
