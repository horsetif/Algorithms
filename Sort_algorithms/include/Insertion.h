//
// Created by horsetif on 19-4-23.
//

#ifndef SORT_ALGORITHMS_INSERTION_H
#define SORT_ALGORITHMS_INSERTION_H

#include <SortBase.h>
template <typename Comparable>
class Insertion : public SortBase<Comparable>{
public:
    void sort(vector<Comparable> &a){
        int N = a.size();
        for(int i = 1; i<N;i++){
            for(int j=i; j>0; j--){
                if(a[j] > a[j-1] ) break;
                this->exchange(a,j,j-1);
            }
        }
    }
};
#endif //SORT_ALGORITHMS_INSERTION_H
