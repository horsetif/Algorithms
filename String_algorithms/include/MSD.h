//
// Created by horsetif on 19-4-25.
//

#ifndef STRING_ALGORITHMS_MSD_H
#define STRING_ALGORITHMS_MSD_H

#include <base_include.h>
class MSD {
    /*
     * 高位字符串排序法
     * 高位排完就不动了，然后分治排序
     * 如果位数太小改为插入排序
     */
private:
    int R = 256;
    int M = 2;
    vector<string> aux;
    int charAt(string s, int d) {
        if (d < s.size())
            return s[d];
        else
            return -1;
    }
    void sort(vector<string> &a, int lo, int hi, int d) {
        if (hi <= lo + M) {
            //插入排序法
            for(int i =lo; i<=hi; i++){
                for(int j =i; j> lo; j--){
                    if(charAt(a[j],d) <  charAt(a[j-1],d)){
                        std::swap(a[j],a[j-1]);
                    }
                    else break;
                }
            }
            return;
        }
        vector<int> count(R + 2, 0); // 如果这一位没有就是-1.
        for (int i = lo; i <= hi; i++) { //第一步：计算频率
            count[charAt(a[i], d) + 2]++;
        }
        for (int r = 0; r < R + 1; r++) { // 第二步：频率转化为索引
            count[r + 1] += count[r];
        }
        for (int i = lo; i <= hi; i++) { //第三步：索引添加到辅助数组中
            aux[count[charAt(a[i], d) + 1]++] = a[i];
        }
        for (int i = lo; i <= hi; i++) {// 第四步：加回来
            a[i] = aux[i - lo];
        }
        for (int r = 0; r < R; r++) {
            sort(a, lo+count[r], lo + count[r+1] -1 ,d+1);
        }
    }
public:
    void sort(vector<string> &a) {
        int N = a.size();
        aux.clear();
        aux.resize(N);
        sort(a, 0, N - 1, 0);
    }
};
#endif //STRING_ALGORITHMS_MSD_H
