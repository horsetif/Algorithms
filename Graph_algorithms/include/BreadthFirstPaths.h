//
// Created by horsetif on 19-4-14.
//

#ifndef GRAPH_ALGORITHMS_BREADTHFIRSTPATHS_H
#define GRAPH_ALGORITHMS_BREADTHFIRSTPATHS_H
#include "Node.h"
#include "Graph.h"
#include "iostream"
class BreadthFirstPaths{
public:
    BreadthFirstPaths(Graph G, int s); // initialize the s to all graph node.
    bool marked(int v);  // is s connect to s ?
    int get_count();  // the number of node connect to s.
    bool hasPathTo(int v); // if there is a path from s to v.
    vector<int> pathTo(int v); // if there exits a path from s to v.return the path.
    void bfs(Graph &G, int temp); // the kernel function of dfs.
    ~BreadthFirstPaths();
private:
    bool *mark;
    int count;
    int *edgeTo;
    int start_point;
};

#endif //GRAPH_ALGORITHMS_BREADTHFIRSTPATHS_H
