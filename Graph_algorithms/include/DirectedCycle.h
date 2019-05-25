//
// Created by horsetif on 19-4-14.
//
#pragma once
#ifndef GRAPH_ALGORITHMS_DIRECTEDCYCLE_H
#define GRAPH_ALGORITHMS_DIRECTEDCYCLE_H

#include "Node.h"
#include "Digraph.h"
#include "iostream"
#include <cstring>
#include <EdgeWeightedDigraph.h>
class DirectedCycle{
public:
    DirectedCycle(Digraph G); // initialize the s to all graph node.
    DirectedCycle(EdgeWeightedDigraph &G);
    vector<int> get_cycle(); //if there exits a cycle, we have to return one.
    void dfs(Digraph &G, int temp); // the kernel function of dfs.
    void dfs(EdgeWeightedDigraph &G, int temp);
    bool hasCycle();  // if there exits a cycle, return true.
    vector<DirectedEdge> get_cycle_path(){
        return cycle_path;
    }
    ~DirectedCycle();
private:
    bool *mark;
    int *edgeTo;
    bool *stack;
    vector<int> cycle;
    vector<DirectedEdge> cycle_path;
    bool is_cycle;
};

DirectedCycle::DirectedCycle(Digraph G) {
    mark = new bool[G.get_V()];
    memset(mark,0,sizeof(bool)*G.get_V());
    edgeTo = new int[G.get_V()];
    memset(edgeTo,-1,sizeof(int)*G.get_V());
    stack = new bool[G.get_V()];
    memset(stack,0,sizeof(bool)*G.get_V());
    is_cycle=false;
    for(int i=0;i<G.get_V();i++){
        if(!mark[i]) dfs(G,i);
    }
}

void DirectedCycle::dfs(Digraph &G, int temp) {
    mark[temp]=true;
    stack[temp]=true;
    Node* p=G.get_adj(temp)->next;
    while(p!=NULL){
        if(this->hasCycle()) return;
        if(!mark[p->val]) {
            edgeTo[p->val]=temp;
            dfs(G, p->val);
        }
        else if(stack[p->val]){
            is_cycle=true;
            cycle.push_back(p->val);
            int k=temp;
            while(k!=p->val){
                cycle.push_back(k);
                k=edgeTo[k];

            }
            cycle.push_back(p->val);
        }
        p=p->next;
    }
    stack[temp]=false;
}

DirectedCycle::~DirectedCycle() {
    delete[] mark;
    delete[] edgeTo;
    delete[] stack;
}

vector<int> DirectedCycle::get_cycle() {
    return cycle;
}
bool DirectedCycle::hasCycle() {
    return is_cycle;
}

DirectedCycle::DirectedCycle(EdgeWeightedDigraph &G) {
    mark = new bool[G.get_V()];
    memset(mark,0,sizeof(bool)*G.get_V());
    edgeTo = new int[G.get_V()];
    memset(edgeTo,-1,sizeof(int)*G.get_V());
    stack = new bool[G.get_V()];
    memset(stack,0,sizeof(bool)*G.get_V());
    is_cycle=false;
    for(int i=0;i<G.get_V();i++){
        if(!mark[i]) dfs(G,i);
    }
}

void DirectedCycle::dfs(EdgeWeightedDigraph &G, int temp) {
    mark[temp]=true;
    stack[temp]=true;

    for(auto path : G.get_adj(temp)){
        if(this->hasCycle()) return;
        int w = path.to();
        if(!mark[w]){
            edgeTo[w]=temp;
            dfs(G,w);
        }
        else if(stack[w]){
            is_cycle = true;
            cycle.push_back(w);
            int k = temp;
            while( k != w ){
                cycle.push_back(k);
                cycle_path.push_back(G.get_edge(edgeTo[k],k));
                k = edgeTo[k];
            }
        }
    }
    stack[temp] = false;
}



#endif //GRAPH_ALGORITHMS_DIRECTEDCYCLE_H
