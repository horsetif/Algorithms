//
// Created by horsetif on 19-4-17.
//
#pragma once
#ifndef GRAPH_ALGORITHMS_DIRECTEDEDGE_H
#define GRAPH_ALGORITHMS_DIRECTEDEDGE_H
#include <iostream>

using namespace std;
class DirectedEdge{
public:
    DirectedEdge(int _v, int _w, double _weight)
            :v(_v),w(_w),weight(_weight){

    }

    DirectedEdge():DirectedEdge(0,0,0.0) {}

    double get_weight(){
        return weight;
    }

    int from(){ return v; }

    int to() { return w; }

    int compareTo(DirectedEdge &that){
        if(weight > that.get_weight()) return 1;
        else if(weight == that.get_weight()) return 0;
        else return -1;
    }

    string toString(){
        return to_string(v)+"-("+to_string(weight)+")->"+to_string(w);
    }

    ~DirectedEdge(){ }

    friend bool operator>(const DirectedEdge &p1, const DirectedEdge &p2);

    friend bool operator<(const DirectedEdge &p1, const DirectedEdge &p2);

    double weight;
    int v; //start point.
    int w; //end point.
};

bool operator>(const DirectedEdge &p1, const DirectedEdge &p2){
    return p1.weight > p2.weight;
}

bool operator<(const DirectedEdge &p1, const DirectedEdge &p2){
    return p1.weight < p2.weight;
}


#endif //GRAPH_ALGORITHMS_DIRECTEDEDGE_H
