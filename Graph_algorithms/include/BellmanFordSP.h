//
// Created by horsetif on 19-4-17.
//

#ifndef GRAPH_ALGORITHMS_BELLMANFORDSP_H
#define GRAPH_ALGORITHMS_BELLMANFORDSP_H

#include <EdgeWeightedDigraph.h>
#include <algorithm>
#include <queue>
#include <DirectedCycle.h>
class BellmanFordSP{
private:
    vector<double> distTo;
    vector<DirectedEdge*> edgeTo;
    bool* onQ;
    queue<int> que;
    int cost; // relax　的调用次数
    vector<DirectedEdge> cycle;
    int start_point;

public:
    BellmanFordSP(EdgeWeightedDigraph G, int s){
        start_point = s;
        cost = 0;
        //edgeTo = new DirectedEdge[G.get_V()];
        onQ = new bool[G.get_V()];
        for(int i=0; i<G.get_V(); i++){
            distTo.push_back(INTMAX_MAX);
            onQ[i] = false;
            edgeTo.push_back(NULL);
        }
        onQ[s] = true;
        distTo[s] = 0.0;
        que.push(s);
        while(!que.empty() && ! this->hasNegativeCycle()){
            int v = que.front();
            cout<<"v = "<<v<<endl;
            que.pop();
            onQ[v] = false;
            relax(G, v);
        }
    }

    void relax(EdgeWeightedDigraph &G, int v){
        for( auto e : G.get_adj(v)){
            int w = e.to();
            if(distTo[w] > distTo[v] + e.weight){
                distTo[w] = distTo[v] + e.weight;
                edgeTo[w] = &e;
                cout<<e.toString()<<endl;
                //delete[] p;
                if(!onQ[w]){
                    que.push(w);
                    onQ[w] = true;
                }
            }
            if(++cost % G.get_V() == 0) findNegativeCycle();
        }
    }

    bool hasNegativeCycle(){
        return cycle.size() != 0 ;
    }
    vector<DirectedEdge> negativeCycle(){
        return cycle;
    }
    void findNegativeCycle(){
        cout<<"find cycle!"<<endl;
        int V = distTo.size();
        EdgeWeightedDigraph spt(V);
        for(int v=0; v<V; v++){
            if(edgeTo[v]!=NULL){
                spt.addEdge(*edgeTo[v]);
            }
        }
        DirectedCycle cyc(spt); // here all node become 5-1.
        vector<int> cycle_node = cyc.get_cycle();
        if( cycle_node.size() != 0 ){
            cycle = cyc.get_cycle_path();
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
            ans.push_back(*edgeTo[v]);
            v = edgeTo[v]->from();
        }while(v!=start_point);
        return ans;
    }
};

#endif //GRAPH_ALGORITHMS_BELLMANFORDSP_H
