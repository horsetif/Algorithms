//
// Created by horsetif on 19-4-17.
//

#ifndef GRAPH_ALGORITHMS_DIJKSTRASP_H
#define GRAPH_ALGORITHMS_DIJKSTRASP_H

#include <EdgeWeightedDigraph.h>
#include <algorithm>
#include <vector>

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



class DijkstraSP{
private:
    bool * marked;
    vector<double> distTo;
    DirectedEdge* edgeTo; // the edge which shortest to the mst tree.
    vector<NodeToTree> max_heap; // priority queue of NodeToTree.
    vector<DirectedEdge> SP; // shortest path for i to other path.
    int find_point;
public:

    DijkstraSP(EdgeWeightedDigraph G ,int index);
    vector<DirectedEdge> edge(){ return SP;}
    double get_distance(int v){
        return distTo[v];
    }
    bool hasPathTo(int v){
        return marked[v];
    }
    vector<DirectedEdge> pathTo(int v){
        vector<DirectedEdge> ans;
        if(!marked[v]) return ans;
        do{
            ans.push_back(edgeTo[v]);
            v = edgeTo[v].from();
        }while(v!=find_point);
        return ans;
    }

    ~DijkstraSP(){
        //cout<<"end find point = "<<find_point<<endl;
        delete[] marked;
        delete[] edgeTo;
    }
private:
    void relax(EdgeWeightedDigraph &G, int v);
};
DijkstraSP::DijkstraSP(EdgeWeightedDigraph G ,int begin_point) {
    find_point = begin_point;
    marked = new bool[G.get_V()];
    memset(marked,0,sizeof(bool)*G.get_V());

    for(int i=0;i<G.get_V();i++){
        distTo.push_back(INTMAX_MAX);
    }

    edgeTo = new DirectedEdge[G.get_V()];

    distTo[begin_point]=0.0;

    relax(G,begin_point);

    while(max_heap.size()!=0) {
        make_heap(max_heap.begin(),max_heap.end(),greater<NodeToTree>());
        int index = max_heap[0].index;
        pop_heap(max_heap.begin(),max_heap.end(),greater<NodeToTree>());
        max_heap.pop_back();
        relax(G, index);
    }
    for(int i=0;i<G.get_V();i++){
        if( i == begin_point ) continue;
        SP.push_back(edgeTo[i]);
    }

}
void DijkstraSP::relax(EdgeWeightedDigraph &G, int index){
    marked[index]=true;
    for(DirectedEdge e : G.get_adj(index)){
        int w = e.to();
        if(distTo[w] > distTo[index] + e.weight){
            distTo[w] = distTo[index] + e.weight;
            edgeTo[w] = e;
            bool find=false;
            for(auto t : max_heap)
                if(t.index ==  w) {
                    t.distance=distTo[w];
                    find=true;
                    break;
                }
            if(!find){
                NodeToTree temp(w,distTo[w]);
                max_heap.push_back(temp);
            }
        }
    }

}
#endif //GRAPH_ALGORITHMS_DIJKSTRASP_H
