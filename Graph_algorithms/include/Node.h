//
// Created by horsetif on 19-4-14.
//

#ifndef GRAPH_ALGORITHMS_NODE_H
#define GRAPH_ALGORITHMS_NODE_H
#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node(int _val){
        val=_val;
        next=NULL;
    }
};
#endif //GRAPH_ALGORITHMS_NODE_H
