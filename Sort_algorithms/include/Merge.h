//
// Created by horsetif on 19-4-23.
//

#ifndef SORT_ALGORITHMS_MERGE_H
#define SORT_ALGORITHMS_MERGE_H

#include <SortBase.h>
template <typename Comparable>
class Merge:public SortBase<Comparable>{
private:
    vector<Comparable> aux;
    void sort(vector<Comparable> &a, int lo, int hi){
        if(hi<=lo) return;
        int mid = lo + (hi-lo)/2;
        sort(a,lo,mid);
        sort(a,mid+1,hi);
        merge(a,lo,mid,hi);

    }
    void merge(vector<Comparable> &a, int lo, int mid, int hi){
        int i = lo, j =mid+1;
        for(int k =lo; k<=hi;k++) aux[k] = a[k];
        for(int k = lo; k<=hi; k++){
            if(i>mid) a[k] = aux[j++];
            else if(j > hi) a[k] = aux[i++];
            else if(aux[i]<aux[j]) a[k] = aux[i++];
            else a[k] = aux[j++];
        }
    }
public:
    bool use_BU = false;
    void sort(vector<Comparable> &a){
        aux.clear();
        int N = a.size();
        aux.reserve(N);
        if(!use_BU) {
            sort(a, 0, N - 1);
        }
        else{
            for(int sz = 1; sz < N; sz = sz*2){
                for(int lo = 0; lo < N-sz; lo +=sz*2){
                    merge(a, lo, lo+sz-1, std::min(lo+sz+sz-1,N-1));
                }
            }
        }
    }

};
#endif //SORT_ALGORITHMS_MERGE_H
