//
// Created by horsetif on 19-4-16.
//

#ifndef GRAPH_ALGORITHMS_EDGE_H
#define GRAPH_ALGORITHMS_EDGE_H
#include <iostream>
using namespace std;
class Edge{
public:
    Edge(int _v, int _w, double _weight)
            :v(_v),w(_w),weight(_weight){

    }
    Edge(){
        w=0;
        v=0;
        weight=0.0;
    }
    double get_weight(){
        return weight;
    }
    int either(){
        return v;
    }
    int other(int _v){
        if(v==_v) return w;
        else return v;
    }
    int compareTo(Edge &that){
        if(weight > that.get_weight()) return 1;
        else if(weight == that.get_weight()) return 0;
        else return -1;
    }
    string toString(){
        return to_string(v)+"-("+to_string(weight)+")->"+to_string(w);
    }
    bool operator < (const Edge &that){
        return weight < that.weight;
    }
    bool operator > (const Edge &that){
        return weight > that.weight;
    }
    ~Edge(){ }
    friend bool operator>(const Edge &p1, const Edge &p2);
    double weight;
    int v;
    int w;
};

bool operator>(const Edge &p1, const Edge &p2){
    return p1.weight > p2.weight;
}
#endif //GRAPH_ALGORITHMS_EDGE_H
