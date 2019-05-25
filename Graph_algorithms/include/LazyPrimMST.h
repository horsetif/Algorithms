//
// Created by horsetif on 19-4-16.
//

#ifndef GRAPH_ALGORITHMS_LAZYPRIMMST_H
#define GRAPH_ALGORITHMS_LAZYPRIMMST_H

#include <EdgeWeightedGraph.h>
#include <queue>

class LazyPrimMST{
private:
    bool * marked;
    priority_queue<Edge,vector<Edge>,greater<Edge>> que;
    vector<Edge> mst;
public:
    LazyPrimMST(EdgeWeightedGraph G);
    vector<Edge> edge(){ return mst;}
    double weight(){
        double ans;
        for(auto m : mst){
            ans+=m.weight;
        }
        return ans;
    }
    ~LazyPrimMST(){
        delete[] marked;
    }
private:
    void visit(EdgeWeightedGraph &G, int v);
};
LazyPrimMST::LazyPrimMST(EdgeWeightedGraph G) {
    marked = new bool[G.get_V()];
    memset(marked,0,sizeof(bool)*G.get_V());
    // we have to check if the Graph is connected.
    visit(G,0);
    while(!que.empty()){
        Edge temp = que.top();
        int v = temp.either();
        int w = temp.other(v);
        que.pop();
        if(marked[v] && marked[w]) continue;
        mst.push_back(temp);
        if(marked[v]) visit(G,w);
        else visit(G,v);
    }
}
void LazyPrimMST::visit(EdgeWeightedGraph &G, int index) {
    marked[index]=true;
    for(auto a : G.get_adj(index)){
        int v = a.either();
        int w = a.other(v);
        if (index==v && !marked[w]) que.push(a);
        else if(index==w && !marked[v]) que.push(a);
    }
}

#endif //GRAPH_ALGORITHMS_LAZYPRIMMST_H
