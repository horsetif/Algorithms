//
// Created by horsetif on 19-4-17.
//
#pragma  once
#ifndef GRAPH_ALGORITHMS_EDGEWEIGHTEDDIGRAPH_H
#define GRAPH_ALGORITHMS_EDGEWEIGHTEDDIGRAPH_H


#include <iostream>
#include <DirectedEdge.h>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

class EdgeWeightedDigraph{
private:
    int V;
    int E;
    vector<vector<DirectedEdge>> adj;

public:

    EdgeWeightedDigraph(string path_name);

    EdgeWeightedDigraph(int num_V);

    int get_V(){
        return V;
    }

    int get_E(){
        return E;
    }

    void addEdge(DirectedEdge e);

    void init(int num_V);

    string toString();

    vector<DirectedEdge> get_adj(int v){
        return adj[v];
    }

    vector<DirectedEdge> edges();

    DirectedEdge get_edge(int v, int w){
        if(v<0 || v>= adj.size() ) cerr<<"get error in Digraph!"<<endl;
        for(auto path : adj[v]){
            if(path.to() == w) return path;
        }
        cerr<<"get error in Digraph!"<<endl;
    }
};

EdgeWeightedDigraph::EdgeWeightedDigraph(int num_V) {
    init(num_V);
}

EdgeWeightedDigraph::EdgeWeightedDigraph(string path_name) {
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
    double weight;
    while(!infile.eof()){
        int v,w;
        infile>>v>>w>>weight;
        DirectedEdge e(v,w,weight);
        addEdge(e);
        E++;
    }
    infile.close();
}

void EdgeWeightedDigraph::init(int num_V){
    V=num_V;
    E=0;
    for(int i=0;i<V;i++){
        vector<DirectedEdge> adj_temp;
        adj.push_back(adj_temp);
    }
}

void EdgeWeightedDigraph::addEdge(DirectedEdge e){
    adj[e.from()].push_back(e);
    E++;
}

string EdgeWeightedDigraph::toString(){
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

vector<DirectedEdge> EdgeWeightedDigraph::edges() {
    vector<DirectedEdge> ans;
    for(int i=0;i<V;i++){
        for(auto a : adj[i]){ ans.push_back(a); }
    }
    return ans;
}



#endif //GRAPH_ALGORITHMS_EDGEWEIGHTEDDIGRAPH_H
