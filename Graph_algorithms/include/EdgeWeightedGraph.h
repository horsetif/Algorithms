//
// Created by horsetif on 19-4-16.
//

#ifndef GRAPH_ALGORITHMS_EDGEWEIGHTEDGRAPH_H
#define GRAPH_ALGORITHMS_EDGEWEIGHTEDGRAPH_H

#include <iostream>
#include <Edge.h>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

class EdgeWeightedGraph{
private:
    int V;
    int E;
    vector<vector<Edge>> adj;

public:
    EdgeWeightedGraph(string path_name);
    EdgeWeightedGraph(int num_V);
    int get_V(){
        return V;
    }
    int get_E(){
        return E;
    }
    void addEdge(Edge e);
    void init(int num_V);
    string toString();
    vector<Edge> get_adj(int v){
        return adj[v];
    }
    vector<Edge> edges();

};

EdgeWeightedGraph::EdgeWeightedGraph(int num_V) {
    init(num_V);
}
void EdgeWeightedGraph::init(int num_V){
    V=num_V;
    E=0;
    for(int i=0;i<V;i++){
        vector<Edge> adj_temp;
        adj.push_back(adj_temp);
    }
}
EdgeWeightedGraph::EdgeWeightedGraph(string path_name) {
    ifstream infile;
    infile.open(path_name);
    if(!infile.is_open()) {
        cerr<<"the path_name is wrong!"<<endl;
        return;
    }
    infile>>V;
    init(V);
    infile>>E;
    E=0;
    init(V);
    double weight;
    while(!infile.eof()){
        int v,w;
        infile>>v>>w>>weight;
        Edge e(v,w,weight);
        addEdge(e);
        E++;
    }
    infile.close();
}

void EdgeWeightedGraph::addEdge(Edge e){
    int v = e.either();
    int w = e.other(v);
    adj[v].push_back(e);
    adj[w].push_back(e);
    E++;
}

string EdgeWeightedGraph::toString(){
    string ans;
    for(auto a : adj){
        if(!a.empty()){
            for(auto t : a){
                ans+=t.toString();
                ans+=" ";
            }
            ans+="\n";
        }
    }
    return ans;
}

vector<Edge> EdgeWeightedGraph::edges() {
    vector<Edge> ans;
    for(int i=0;i<V;i++){
        for(auto a : adj[i]){
            if(a.either() == i) ans.push_back(a);
        }
    }
    return ans;
}

#endif //GRAPH_ALGORITHMS_EDGEWEIGHTEDGRAPH_H
