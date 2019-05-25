//
// Created by horsetif on 19-4-14.
//
#include "../include/Digraph.h"
#include<iostream>
#include<fstream>

int Digraph::get_E() {
    return E;
}

int Digraph::get_V(){
    return V;
}

Digraph::Digraph(int num_V) {
    V=num_V;
    init(num_V);
}

void Digraph::addEdge(int v, int w) {
    if(v<0 || v>=V || w<0 || w>=V) return;
    Node* q=new Node(w);
    q->next=adj[v]->next;
    adj[v]->next=q;
    E++;
}

Digraph::Digraph(string path_name){
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

void Digraph::init(int num_V) {
    for(int i=0;i<num_V;i++){
        adj.push_back(new Node(i));
    }
}

Node* Digraph::get_adj(int index){
    return adj[index];
}

string Digraph::toString() {
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

Digraph Digraph::reverse() {
    Digraph D(V);
    for(int i=0;i<V;i++){
        Node* p=adj[i]->next;
        while(p) {
            D.addEdge(p->val, i);
            p = p->next;
        }
    }
    return D;
}
