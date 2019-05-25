//
// Created by horsetif on 19-4-14.
//
#include "../include/Graph.h"
#include<iostream>
#include<fstream>

int Graph::get_E() {
    return E;
}

int Graph::get_V(){
    return V;
}

Graph::Graph(int num_V) {
    init(num_V);
}

void Graph::addEdge(int v, int w) {
    if(v<0 || v>=V || w<0 || w>=V) return;
    Node* p=new Node(v);
    Node* q=new Node(w);
    p->next=adj[w]->next;
    adj[w]->next=p;
    q->next=adj[v]->next;
    adj[v]->next=q;
    E++;
}

Graph::Graph(string path_name){
    ifstream infile;
    infile.open(path_name);
    if(!infile.is_open()) {
        cerr<<"the path_name is wrong!"<<endl;
        return;
    }
    infile>>V;
    init(V);
    infile>>E;
    E=0;
    while(!infile.eof()){
        int v,w;
        infile>>v>>w;
        addEdge(v,w);
    }
    infile.close();
}

void Graph::init(int num_V) {
    V=num_V;
    for(int i=0;i<num_V;i++){
        adj.push_back(new Node(i));
    }
}

Node* Graph::get_adj(int index){
    return adj[index];
}

string Graph::toString() {
    string s = to_string(V) + " vertices, " + to_string(E) + " edges\n";
    for(int i=0; i<V;i++){
        Node* p = adj[i];
        s += to_string(p->val);
        p=p->next;
        while(p!=NULL){
            s += " -> "+to_string(p->val);
            p=p->next;
        }
        s += "\n";
    }
    return s;

}

int degree(Graph &G, int v){
    // get the degree of G.
    int dg=0;
    if(v<0 || v>=G.get_V()) return dg;
    Node* p = G.get_adj(v);
    while(p->next!=NULL){
        p=p->next;
        dg++;
    }
    return dg;
}

int maxDegree(Graph &G){
    // get the max degree of G.
    int maxD=0;
    for(int i=0;i<G.get_V();i++){
        maxD=max(maxD,degree(G,i));
    }
    return maxD;
}

double avgDegree(Graph &G){
    // get the average degree of G.
    return 2*G.get_E()/G.get_V();
}

int numberOfSelfLoops(Graph &G){
    // get the number of self Loops.
    int cnt=0;
    for(int i=0;i<G.get_V();i++){
        Node* p=G.get_adj(i);
        Node* head=p;
        p=p->next;
        while(p!=NULL){
            if(p==head) {
                cnt++;
            }
            p=p->next;
        }
    }
    return cnt/2;
}