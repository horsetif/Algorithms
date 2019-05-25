//
// Created by horsetif on 19-4-25.
//

#ifndef STRING_ALGORITHMS_QUICK3STRING_H
#define STRING_ALGORITHMS_QUICK3STRING_H

#include <base_include.h>
class Quick3string{
private:
    int charAt(string s, int d) {
        if (d < s.size())
            return s[d];
        else
            return -1;
    }
    void sort(vector<string>& a,int lo, int hi, int d){
        if(hi <= lo) return;
        int lt = lo, gt = hi;
        int v = charAt(a[lo],d);
        int i = lo + 1;
        while(i <= gt){
            int t = charAt(a[i],d);
            if(t < v) swap(a[lt++],a[i++]);
            else if(t > v) swap(a[i],a[gt--]);
            else i++;
        }
        sort(a, lo, lt-1, d);
        if(v >= 0 ) sort(a,lt, gt, d+1);
        sort(a, gt+1, hi, d);
    }
public:
    void sort(vector<string>& a){
        sort(a,0,a.size()-1,0);
    }
};
#endif //STRING_ALGORITHMS_QUICK3STRING_H
