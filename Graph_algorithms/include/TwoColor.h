//
// Created by horsetif on 19-4-14.
//

#ifndef GRAPH_ALGORITHMS_TWOCOLOR_H
#define GRAPH_ALGORITHMS_TWOCOLOR_H

#include "Node.h"
#include "Graph.h"
#include "iostream"
#include <cstring>
class TwoColor{
public:
    TwoColor(Graph G){
        // initialize the s to all graph node.
        isTwoColorable=true;
        mark = new bool[G.get_V()];
        memset(mark,0,sizeof(bool)*G .get_V());
        color = new bool[G.get_V()];
        memset(color,0,sizeof(bool)*G.get_V());
        for(int i=0; i<G.get_V();i++){
            if(!mark[i]){
                dfs(G,i);
            }
        }


    }
    void dfs(Graph &G, int temp) { // the kernel function of dfs.
        mark[temp]=true;
        Node* pre=G.get_adj(temp);
        Node* p=pre->next;
        while(p){
            if(!mark[p->val]){
                color[p->val]=~color[pre->val];
                mark[p->val]=true;
                dfs(G,p->val);
            }
            else if(color[p->val]==color[pre->val]) isTwoColorable=false;
            p=p->next;
        }
    }
    ~TwoColor(){
        delete[] mark;
        delete[] color;
    }
    bool is_two_color(){
        return isTwoColorable;
    }
private:
    bool *mark;
    bool *color;
    bool isTwoColorable;
};

#endif //GRAPH_ALGORITHMS_TWOCOLOR_H
