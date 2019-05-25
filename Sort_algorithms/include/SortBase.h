//
// Created by horsetif on 19-4-23.
//

#ifndef SORT_ALGORITHMS_SORTBASE_H
#define SORT_ALGORITHMS_SORTBASE_H

#include <base_include.h>
template <typename Comparable>
class SortBase{
public:
    virtual void sort(vector<Comparable> &a) = 0;
    //虚函数，可以排序数组的实际函数

    virtual bool isSorted(vector<Comparable> &a){
        //检测是否排序成功
        if(a.size()<=1) return true;
        for(int i=1;i<a.size();i++){
            if(a[i]<a[i-1]) return false;
        }
        return true;
    }
    virtual void exchange(vector<Comparable> &a, int i, int j){
        //交换数组两个元素
        Comparable tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    virtual void show(vector<Comparable> &a){
        //显示数组
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};
#endif //SORT_ALGORITHMS_SORTBASE_H
