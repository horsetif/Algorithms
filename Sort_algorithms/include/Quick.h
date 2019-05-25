//
// Created by horsetif on 19-4-23.
//

#ifndef SORT_ALGORITHMS_QUICK_H
#define SORT_ALGORITHMS_QUICK_H
#include <SortBase.h>
#include <random>
template <typename Comparable>
class Quick:public SortBase<Comparable>{
public:
    bool Quick3Way = false;
    void sort(vector<Comparable> &a){
        unsigned int seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
        std::shuffle (a.begin (), a.end (), std::default_random_engine (seed));
        if(!Quick3Way)
            sort(a,0,a.size()-1);
        else
            sort_3way(a,0,a.size()-1);
    }

private:
    void sort(vector<Comparable> &a, int lo, int hi){
        if(hi <= lo) return;
        int j = partition(a,lo,hi);
        sort(a,lo,j-1);
        sort(a,j+1,hi);
    }
    int partition(vector<Comparable> &a, int lo, int hi){
        int i = lo, j = hi+1;
        Comparable v = a[lo];
        while(true){
            while(a[++i]<v) if(i == hi) break;
            while(v<a[--j]) if(j == lo) break;
            if(i>=j) break;
            this->exchange(a,i,j);
        }
        this->exchange(a,lo,j);
        return j;
    }
    void sort_3way(vector<Comparable> &a, int lo, int hi){
        if(hi <= lo ) return;
        int lt = lo, i = lo+1, gt = hi;
        Comparable v = a[lo];
        while(i <= gt){
            if(a[i] < v) this->exchange(a,lt++,i++);
            else if(a[i] > v) this->exchange(a,i,gt--);
            else i++;
        }
        sort(a,lo,lt-1);
        sort(a,gt+1,hi);
    }
};
#endif //SORT_ALGORITHMS_QUICK_H
