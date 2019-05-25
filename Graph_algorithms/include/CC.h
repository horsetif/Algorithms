//
// Created by horsetif on 19-4-14.
//

#ifndef GRAPH_ALGORITHMS_CC_H
#define GRAPH_ALGORITHMS_CC_H
#include "Node.h"
#include "Graph.h"
#include "iostream"
class CC{
public:
    CC(Graph G); // initialize the s to all graph node.
    bool marked(int v);  // is s connect to s ?
    int get_count();  // the number of node connect to s.
    void dfs(Graph &G, int temp, int cur); // the kernel function of dfs.
    bool connected(int v, int w);  // if the node v and w connected.
    int get_id(int v); // get the id of node v.
    ~CC();
private:
    bool *mark;
    int count;
    int *id;
};
#endif //GRAPH_ALGORITHMS_CC_H
