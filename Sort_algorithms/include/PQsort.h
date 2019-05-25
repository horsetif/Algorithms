//
// Created by horsetif on 19-4-23.
//

#ifndef SORT_ALGORITHMS_PQSORT_H
#define SORT_ALGORITHMS_PQSORT_H
#include <SortBase.h>
template <typename Comparable>
class PQsort : public SortBase<Comparable>{
public:
    void sort(vector<Comparable> &a){
        //堆排序，要把所有索引加1.
        int N = a.size();
        N = N + 1;
        for(int k = N/2; k >= 1; k--){
            sink(a,k-1,N-1);
        }
        while(N>1){
            exchange(a,1-1,N--);
            sink(a,1-1,N-1);
        }
    }
private:
    bool less(vector<Comparable> &a,int i,int j){
        return a[i] < a[j];
    }
    void exchange(vector<Comparable> &a,int i, int j){
        Comparable tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    void swim(vector<Comparable> &a,int k,int N){
        while( k> 1 && less(a,k/2,k)){
            exchange(a,k/2,k);
            k = k/2;
        }
    }
    void sink(vector<Comparable> &a,int k,int N){
        while(2*k <= N){
            int j = 2*k;
            if(j<N && less(a,j,j+1)) j++;
            if(!less(a,k,j)) break;
            exchange(a,k,j);
            k = j;
        }
    }
};
#endif //SORT_ALGORITHMS_PQSORT_H
