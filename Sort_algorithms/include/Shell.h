//
// Created by horsetif on 19-4-23.
//

#ifndef SORT_ALGORITHMS_SHELL_H
#define SORT_ALGORITHMS_SHELL_H

#include <SortBase.h>
template <typename Comparable>
class Shell : public SortBase<Comparable>{
public:
    void sort(vector<Comparable> &a){
        int N = a.size();
        int h =1 ;
        while(h<N/3) h=3*h+1;
        while(h>=1){
            for(int i=h;i<N;i++){
                for(int j=i; j>=h;j-=h){
                    if(a[j] > a[j-h]) break;
                    this->exchange(a,j,j-h);
                }
            }
            h = h/3;
        }
    }
};
#endif //SORT_ALGORITHMS_SHELL_H
