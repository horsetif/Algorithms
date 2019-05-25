//
// Created by horsetif on 19-4-14.
//

#include "../include/DirectedDFS.h"
#include<cstring>
DirectedDFS::DirectedDFS(Digraph G, int s) {
    mark = new bool[G.get_V()];
    memset(mark,0,sizeof(bool)*G.get_V());
    dfs(G,s);

}

DirectedDFS::DirectedDFS(Digraph G, vector<int> source){
    mark = new bool[G.get_V()];
    memset(mark,0,sizeof(bool)*G.get_V());
    for(auto s : source){
        if(!mark[s]) dfs(G,s);
    }
}

void DirectedDFS::dfs(Digraph &G, int temp) {
    mark[temp]=true;
    Node* p=G.get_adj(temp)->next;
    while(p!=NULL){
        if(!mark[p->val]) dfs(G,p->val);
        p=p->next;
    }
    //return;
}

DirectedDFS::~DirectedDFS() {
    delete[] mark;
}


bool DirectedDFS::marked(int v) {
    return mark[v];
}
