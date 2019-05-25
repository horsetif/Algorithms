//
// Created by horsetif on 19-4-14.
//

#ifndef GRAPH_ALGORITHMS_DIRECTEDDFS_H
#define GRAPH_ALGORITHMS_DIRECTEDDFS_H

#include "Node.h"
#include "Digraph.h"
#include "iostream"
class DirectedDFS{
public:
    DirectedDFS(Digraph G, int s); // initialize the s to all graph node.
    DirectedDFS(Digraph G, vector<int> source);
    bool marked(int v);  // is s connect to s ?
    void dfs(Digraph &G, int temp); // the kernel function of dfs.
    ~DirectedDFS();
private:
    bool *mark;
};

#endif //GRAPH_ALGORITHMS_DIRECTEDDFS_H
