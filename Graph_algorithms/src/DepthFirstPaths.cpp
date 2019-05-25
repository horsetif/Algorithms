//
// Created by horsetif on 19-4-14.
//

#include "../include/DepthFirstPaths.h"
#include<cstring>
DepthFirstPaths::DepthFirstPaths(Graph G, int s) {
    mark = new bool[G.get_V()];
    memset(mark,0,sizeof(bool)*G.get_V());
    edgeTo = new int[G.get_V()];
    memset(edgeTo,-1,sizeof(int)*G.get_V());
    mark[s]=true;
    count = 0;
    start_point=s;
    dfs(G,s);

}

int DepthFirstPaths::get_count() {
    return count;
}

bool DepthFirstPaths::marked(int v) {

    return mark[v];
}

void DepthFirstPaths::dfs(Graph &G, int temp) {
    //if(mark[temp]) return;
    count++;
    mark[temp]=true;
    Node* p=G.get_adj(temp)->next;
    while(p!=NULL){
        if(!mark[p->val]) {
            edgeTo[p->val]=temp;
            dfs(G, p->val);
        }

        p=p->next;
    }
    //return;
}

DepthFirstPaths::~DepthFirstPaths() {
    delete[] mark;
    delete[] edgeTo;
}

bool DepthFirstPaths::hasPathTo(int v) {
    return marked(v);
}

vector<int> DepthFirstPaths::pathTo(int v) {
    vector<int> ans;
    if(!hasPathTo(v)) return ans;
    while(v!=start_point){
        ans.push_back(v);
        v=edgeTo[v];
    }
    ans.push_back(start_point);
    return ans;
}