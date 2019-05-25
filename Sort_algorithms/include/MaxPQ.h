//
// Created by horsetif on 19-4-23.
//

#ifndef SORT_ALGORITHMS_MAXPQ_H
#define SORT_ALGORITHMS_MAXPQ_H

#include <base_include.h>
template <typename Key>
class MaxPQ{
private:
    vector<Key> pq;
    int N = 0;
public:
    MaxPQ(int maxN = 100){
        pq.reserve(maxN);
    }

    bool isEmpty(){
        return N == 0;
    }
    int size(){
        return N;
    }
    void insert(Key v){
        pq[++N] = v;
        swim(N);
    }
    Key delMax(){
        Key max = pq[1];
        exchange(1,N--);
        pq.pop_back();
        sink(1);
        return max;
    }

private:
    bool less(int i,int j){
        return pq[i] < pq[j];
    }
    void exchange(int i, int j){
        Key tmp = pq[i];
        pq[i] = pq[j];
        pq[j] = tmp;
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
#endif //SORT_ALGORITHMS_MAXPQ_H
