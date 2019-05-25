//
// Created by horsetif on 19-4-14.
//

#ifndef GRAPH_ALGORITHMS_DIGRAPH_H
#define GRAPH_ALGORITHMS_DIGRAPH_H
#include<vector>
#include<iostream>
#include"Node.h"

using namespace std;

class Digraph{
private:
    int V;
    int E;
    vector<Node*> adj;

public:
    Digraph(string path_name);
    Digraph(int num_V);
    int get_V();
    int get_E();
    void addEdge(int v, int w);
    void init(int num_V);
    Node* get_adj(int index);
    string toString();
    Digraph reverse();

};




#endif //GRAPH_ALGORITHMS_DIGRAPH_H
