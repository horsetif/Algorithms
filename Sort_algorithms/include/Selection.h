//
// Created by horsetif on 19-4-23.
//

#ifndef SORT_ALGORITHMS_SELECTION_H
#define SORT_ALGORITHMS_SELECTION_H

#include <SortBase.h>
template <typename Comparable>
class Selection:public SortBase<Comparable>{
public:
    //void exchange(vector<Comparable> &a, int index, int i);
    void sort(vector<Comparable> &a){
        /*选择排序
         * 从左向右，按照顺序查找最小值，然后插在最前面。
         */
        int N = a.size();
        for(int i = 0; i<N;i++){
            int min_index = i;
            for(int j = i+1;j<N; j++){
                if(a[min_index] > a[j]) min_index =j;
            }
            //this->exchange(a,min_index,i); // why ??
            SortBase<Comparable>::exchange(a,min_index,i);

        }
    }
};
#endif //SORT_ALGORITHMS_SELECTION_H
