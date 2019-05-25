//
// Created by horsetif on 19-4-14.
//

#ifndef GRAPH_ALGORITHMS_DEPTHFIRSTSEARCH_H
#define GRAPH_ALGORITHMS_DEPTHFIRSTSEARCH_H
#include "Node.h"
#include "Graph.h"
#include "iostream"
class DepthFirstSearch{
public:
    DepthFirstSearch(Graph G, int s); // initialize the s to all graph node.
    bool marked(int v);  // is s connect to s ?
    int get_count();  // the number of node connect to s.
    void dfs(Graph &G, int temp); // the kernel function of dfs.
    ~DepthFirstSearch();
private:
    bool *mark;
    int count;
};

#endif //GRAPH_ALGORITHMS_DEPTHFIRSTSEARCH_H
