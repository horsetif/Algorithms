//
// Created by horsetif on 19-4-14.
//
#include "../include/BreadthFirstPaths.h"
#include<cstring>
#include<queue>
BreadthFirstPaths::BreadthFirstPaths(Graph G, int s) {
    mark = new bool[G.get_V()];
    memset(mark,0,sizeof(bool)*G.get_V());
    edgeTo = new int[G.get_V()];
    memset(edgeTo,-1,sizeof(int)*G.get_V());
    mark[s]=true;
    count = 0;
    start_point=s;
    bfs(G,s);

}

int BreadthFirstPaths::get_count() {
    return count;
}

bool BreadthFirstPaths::marked(int v) {

    return mark[v];
}

void BreadthFirstPaths::bfs(Graph &G, int temp) {
    queue<int> que;
    que.push(temp);
    while(!que.empty()){
        Node* q = G.get_adj(que.front());
        que.pop();
        Node* pre=q;
        q=q->next;
        while(q){
            if(!mark[q->val]) {
                que.push(q->val);
                mark[q->val]=true;
                edgeTo[q->val]=pre->val;
                count++;
            }
            q=q->next;
        }
    }
}

BreadthFirstPaths::~BreadthFirstPaths() {
    delete[] mark;
    delete[] edgeTo;
}

bool BreadthFirstPaths::hasPathTo(int v) {
    return marked(v);
}

vector<int> BreadthFirstPaths::pathTo(int v) {
    vector<int> ans;
    if(!hasPathTo(v)) return ans;
    while(v!=start_point){
        ans.push_back(v);
        v=edgeTo[v];
    }
    ans.push_back(start_point);
    return ans;
}
