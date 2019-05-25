//
// Created by horsetif on 19-4-16.
//

#ifndef GRAPH_ALGORITHMS_PRIMMST_H
#define GRAPH_ALGORITHMS_PRIMMST_H

#include <EdgeWeightedGraph.h>
#include <queue>
#include <algorithm>
class NodeToTree{
public:
    int index;
    double distance;
    NodeToTree(int _index, double _dis):index(_index),distance(_dis){}
    friend bool operator < (const NodeToTree&, const NodeToTree&);
    friend bool operator > (const NodeToTree&, const NodeToTree&);
};
bool operator < (const NodeToTree &p1, const NodeToTree &p2){
    return p1.distance < p2.distance;
}
bool operator > (const NodeToTree &p1, const NodeToTree &p2){
    return p1.distance > p2.distance;
}



class PrimMST{
private:
    bool * marked;
    vector<double> distTo;
    Edge* edgeTo; // the edge which shortest to the mst tree.
    vector<NodeToTree> max_heap;
    vector<Edge> mst;
public:
    PrimMST(EdgeWeightedGraph G);
    vector<Edge> edge(){ return mst;}
    double weight(){
        double ans;
        for(auto m : mst){
            ans+=m.weight;
        }
        return ans;
    }
    ~PrimMST(){
        delete[] marked;
        delete[] edgeTo;
    }
private:
    void visit(EdgeWeightedGraph &G, int v);
};
PrimMST::PrimMST(EdgeWeightedGraph G) {
    marked = new bool[G.get_V()];
    memset(marked,0,sizeof(bool)*G.get_V());
    // we have to check if the Graph is connected.
    for(int i=0;i<G.get_V();i++){
        distTo.push_back(INTMAX_MAX);
    }

    edgeTo = new Edge[G.get_V()];

    distTo[0]=0.0;
    visit(G,0);

    while(max_heap.size()!=0) {
        make_heap(max_heap.begin(),max_heap.end(),greater<NodeToTree>());
        int index = max_heap[0].index;
        pop_heap(max_heap.begin(),max_heap.end(),greater<NodeToTree>());
        max_heap.pop_back();
        visit(G, index);
    }
    for(int i=1;i<G.get_V();i++){
        mst.push_back(edgeTo[i]);
    }

}
void PrimMST::visit(EdgeWeightedGraph &G, int index){
    marked[index]=true;
    for(Edge e : G.get_adj(index)){
        int v = e.either();
        int w = e.other(v);
        if(marked[v] && marked[w]) continue;
        w = (w==index) ? v : w;
        if(w==0) continue;
        if(e.weight < distTo[w]){
            distTo[w] = e.weight;
            edgeTo[w] = e;
            bool find=false;
            for(auto t : max_heap)
                if(t.index ==  w) {
                    t.distance=e.weight;
                    find=true;
                    break;
                }
            if(!find){
                NodeToTree temp(w,e.weight);
                max_heap.push_back(temp);
            }
        }
    }

}

#endif //GRAPH_ALGORITHMS_PRIMMST_H
