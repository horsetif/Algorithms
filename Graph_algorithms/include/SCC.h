//
// Created by horsetif on 19-4-15.
//

#ifndef GRAPH_ALGORITHMS_SCC_H
#define GRAPH_ALGORITHMS_SCC_H

#include "Node.h"
#include "Digraph.h"
#include "iostream"
#include "DepthFirstOrder.h"
#include <cstring>
#include <stack>
class SCC{
public:
    SCC(Digraph G){
        id = new int[G.get_V()];
        memset(id,-1,sizeof(int)*G.get_V());
        mark = new bool[G.get_V()];
        memset(mark,0,sizeof(bool)*G.get_V());
        int count=0;
        DepthFirstOrder order_class(G.reverse());
        stack<int> ans = order_class.get_reversePost();
        while(!ans.empty()){
            int index=ans.top();
            if(!mark[index]) {
                dfs(G,index,count);
                count++;
            }
            ans.pop();
        }
    }
    void dfs(Digraph &G, int index, int cur){
        mark[index]=true;
        id[index]=cur;
        Node* p = G.get_adj(index)->next;
        while(p!=NULL){
            if(!mark[p->val]) dfs(G,p->val,cur);
            p=p->next;
        }
    }

    int get_id(int num){
        return id[num];
    }

    ~SCC(){
        delete[] id;
        delete[] mark;
    }
private:
    int* id;
    bool* mark;
};

#endif //GRAPH_ALGORITHMS_SCC_H
