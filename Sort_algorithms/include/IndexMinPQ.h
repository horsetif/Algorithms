//
// Created by horsetif on 19-4-23.
//

#ifndef SORT_ALGORITHMS_INDEXMINPQ_H
#define SORT_ALGORITHMS_INDEXMINPQ_H

#include <base_include.h>
template <typename Key>
class IndexMinPQ{
public:
    IndexMinPQ(int maxN){
        keys.reserve(maxN+1);
        pq.reserve(maxN+1);
        qp.reserve(maxN+1);
        for(int i = 0; i<=maxN; i++) qp[i] = -1;
    }
    void insert(int k, Key key){
        N++;
        qp[k] = N;
        pq[N] = k;
        keys[k] = key;
        swim(N);
    }
    void change(int k, Key key){
        keys[k] = key;
        swim(qp[k]);
        sink(qp[k]);
    }
    bool contains(int k){
        return qp[k] != -1;
    }
    void del(int k){
        exchange(k,N--);
        swim(qp[k]);
        sink(qp[k]);
        keys.pop_back();
        qp[pq[N+1]] = -1;
    }
    Key min(){
        return keys[pq[1]];
    }
    int minIndex(){
        return pq[1];
    }
    int delMin(){
        int indexofMin = pq[1];
        exchange(1,N--);
        sink(1);
        keys.pop_back();
        qp[pq[N+1]] = -1;
        return indexofMin;
    }
    bool isEmpty(){
        return N == 0;
    }
    int size(){
        return N;
    }

private:
    int N; // PQ中元素的数量
    vector<int> pq; //索引二叉堆，从1开始的 , pq 里的值就是说第几个的意思
    vector<int> qp; //逆序， qp[pq[i]] = pq[qp[i]] = i,i在pq的位置为qp[i]
    vector<Key> keys; // 键值元素

    bool less(int i,int j){
        return keys[pq[i]] < keys[pq[j]];
    }
    void exchange(int i, int j){
        Key tmp = keys[pq[i]];
        keys[pq[i]] = keys[pq[j]];
        keys[pq[j]] = tmp;
    }
    void swim(int k){
        while( k> 1 && less(k/2,k)){
            exchange(k/2,k);
            k = k/2;
        }
    }
    void sink(int k){
        while(2*k <= N){
            int j = 2*k;
            if(j<N && less(j,j+1)) j++;
            if(!less(k,j)) break;
            exchange(k,j);
            k = j;
        }
    }
};
#endif //SORT_ALGORITHMS_INDEXMINPQ_H
