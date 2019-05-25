//
// Base class of Graph class.
//
#pragma once
#ifndef GRAPH_ALGORITHMS_GRAPH_H
#define GRAPH_ALGORITHMS_GRAPH_H

#include<vector>
#include<iostream>
#include"Node.h"

using namespace std;

class Graph{
private:
    int V;
    int E;
    vector<Node*> adj;

public:
    Graph(string path_name);
    Graph(int num_V);
    int get_V();
    int get_E();
    void addEdge(int v, int w);
    void init(int num_V);
    Node* get_adj(int index);
    string toString();

};



int degree(Graph &G, int v);

int maxDegree(Graph &G);

double avgDegree(Graph &G);

int numberOfSelfLoops(Graph &G);
#endif //GRAPH_ALGORITHMS_GRAPH_H
