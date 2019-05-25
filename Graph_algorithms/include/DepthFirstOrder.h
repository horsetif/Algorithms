//
// Created by horsetif on 19-4-15.
//
#pragma once
#ifndef GRAPH_ALGORITHMS_DEPTHFIRSTORDER_H
#define GRAPH_ALGORITHMS_DEPTHFIRSTORDER_H


#include "Node.h"
#include "Digraph.h"
#include <cstring>
#include <stack>
#include <EdgeWeightedDigraph.h>
#include "iostream"
class DepthFirstOrder{
public:
    DepthFirstOrder(Digraph G) { // initialize the s to all graph node.
        mark = new bool[G.get_V()];
        memset(mark,0,sizeof(bool)*G.get_V());
        for(int i=0; i<G.get_V(); i++){
            if(!mark[i]) dfs(G,i);
        }
    }

    DepthFirstOrder(EdgeWeightedDigraph G) { // initialize the s to all graph node.
        mark = new bool[G.get_V()];
        memset(mark,0,sizeof(bool)*G.get_V());
        for(int i=0; i<G.get_V(); i++){
            if(!mark[i]) dfs(G,i);
        }
    }
    ~DepthFirstOrder(){
        delete[] mark;
    }

    void dfs(Digraph &G, int index){
        mark[index]=true;
        pre.push_back(index);
        Node* p = G.get_adj(index)->next;
        while(p!=NULL){
            if(!mark[p->val]) dfs(G,p->val);
            p=p->next;
        }
        post.push_back(index);
        reversePost.push(index);
    }

    void dfs(EdgeWeightedDigraph &G, int index){
        mark[index]=true;
        pre.push_back(index);
        for(auto path : G.get_adj(index)){
            if(!mark[path.to()]) dfs(G,path.to());
        }
        post.push_back(index);
        reversePost.push(index);
    }
    vector<int> get_pre(){ return pre; }
    vector<int> get_post(){ return post;}
    stack<int> get_reversePost() { return reversePost; }
private:
    bool *mark;
    vector<int> pre;
    vector<int> post;
    stack<int> reversePost;

};

#endif //GRAPH_ALGORITHMS_DEPTHFIRSTORDER_H
