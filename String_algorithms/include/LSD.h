//
// Created by horsetif on 19-4-25.
//

#ifndef STRING_ALGORITHMS_LSD_H
#define STRING_ALGORITHMS_LSD_H

#include <base_include.h>
class LSD {
    /*
     * 低位优先排序法，从低到高排序
     * 主要针对的是长度相同的字符串进行排序
     */
public:
    void sort(vector<string> &a, int W) {
        int N = a.size();
        int R = 256;
        vector<string> aux(N,"");
        for (int d = W - 1; d >= 0; d--) {
            aux.clear();
            vector<int> count(R + 1, 0);
            for (int i = 0; i < N; i++) {//第一步：计算出频率
                count[a[i][d] + 1]++;
            }
            for (int r = 0; r < R; r++) {//第二步：将频率转化为索引
                count[r + 1] += count[r];
            }
            for (int i = 0; i < N; i++) {//第三步：将元素分类
                aux[count[a[i][d]]++] = a[i];
            }
            for (int i = 0; i < N; i++) {//第四步：回写
                a[i] = aux[i];
            }
        }
    }
};
#endif //STRING_ALGORITHMS_LSD_H
