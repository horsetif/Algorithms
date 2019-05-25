//
// Created by horsetif on 19-4-16.
//
//使用 路径压缩下的加权quick-union方法
#ifndef GRAPH_ALGORITHMS_UF_H
#define GRAPH_ALGORITHMS_UF_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//union-find 方法
class UF{
public:
    UF(int N){
        init(N);
    }
    UF(string path){
        fstream file(path);
        if(!file.is_open()){
            cerr<<"open error!"<<endl;
        }
        file>>total_num;
        init(total_num);
        while(!file.eof()){
            int p,q;
            file>>p>>q;
            if(_union(p,q)) cout<<"union success! in  "<<p<<" and "<<q<<endl;
            else cout<<"union fail! in "<<p<<" and "<<q<<endl;
        }

    }
    bool connected(int p, int q){
        //看下根节点是不是一样的
        if(p >= total_num || q >= total_num) return false;
        int root_p = find(p);
        int root_q = find(q);
        return root_p == root_q;
    }
    int get_count(){
        return count;
    }
    int get_total_num(){
        return total_num;
    };
    void init(int N){
        total_num=N;
        count=N;
        for(int i=0;i<N;i++){
            id.push_back(i);
            weight.push_back(1);
        }
    }
    bool _union(int p, int q)
    {
        //合并函数 查找根节点，把小的树链接在大的树上
        if(p >= total_num || q >= total_num) return false;
        int root_p = find(p);
        int root_q = find(q);
        if(root_p == root_q)
            return;
        count--;
        if(weight[root_p] < weight[root_q]){
            weight[root_q]+=weight[root_p];
            id[root_p]=root_q;
        }
        else{
            weight[root_p]+=weight[root_q];
            id[root_q]=root_p;
        }
        return true;
    }
    int find(int p){
        //向上查找，并且跟新查找路径的所有值，指向根节点
        int root = p;
        //查找部分
        while(id[root]!=root) root=id[root];
        //更新部分（压缩路径）
        while(id[p]!=root){
            int new_p = p;
            p = id[p];
            id[new_p] = root;
        }
        return root;
    }
    ~UF(){}

private:
    int count; // 总体的集合数
    vector<int> id; // 每一个查找点对应的父节点的id号码
    vector<int> weight; // 每一颗树总体的大小
    int total_num; // 总数
};

#endif //GRAPH_ALGORITHMS_UF_H
