//
// Created by horsetif on 19-4-14.
//

#include "../include/CC.h"
#include<cstring>
CC::CC(Graph G) {
    mark = new bool[G.get_V()];
    memset(mark,0,sizeof(bool)*G.get_V());
    id = new int[G.get_V()];
    memset(id,-1, sizeof(int)*G.get_V());
    count = 0;
    int current=0;
    for(int i=0;i<G.get_V();i++){
        if(!mark[i]) {
            dfs(G,i,current);
            current++;
        }

    }

}

int CC::get_count() {
    return count;
}

bool CC::marked(int v) {

    return mark[v];
}

void CC::dfs(Graph &G, int temp, int cur) {
    //if(mark[temp]) return;
    count++;
    mark[temp]=true;
    id[temp] = cur;
    Node* p=G.get_adj(temp)->next;
    while(p!=NULL){
        if(!mark[p->val]) dfs(G,p->val,cur);
        p=p->next;
    }
    //return;
}

CC::~CC() {
    delete[] mark;
    delete[] id;
}

int CC::get_id(int v) {
    return id[v];
}

bool CC::connected(int v, int w) {
    return id[v]==id[w];
}