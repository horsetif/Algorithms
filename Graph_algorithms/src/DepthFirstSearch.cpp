//
// Created by horsetif on 19-4-14.
//

#include "../include/DepthFirstSearch.h"
#include<cstring>
DepthFirstSearch::DepthFirstSearch(Graph G, int s) {
    mark = new bool[G.get_V()];
    memset(mark,0,sizeof(bool)*G.get_V());
    mark[s]=true;
    count = 0;
    dfs(G,s);

}

int DepthFirstSearch::get_count() {
    return count;
}

bool DepthFirstSearch::marked(int v) {

    return mark[v];
}

void DepthFirstSearch::dfs(Graph &G, int temp) {
    //if(mark[temp]) return;
    count++;
    mark[temp]=true;
    Node* p=G.get_adj(temp)->next;
    while(p!=NULL){
        if(!mark[p->val]) dfs(G,p->val);
        p=p->next;
    }
    //return;
}

DepthFirstSearch::~DepthFirstSearch() {
    delete[] mark;
}
