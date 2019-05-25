//
// Created by horsetif on 19-4-23.
//

#ifndef SEARCH_ALGORITHMS_LINEARPROBINGHASHST_H
#define SEARCH_ALGORITHMS_LINEARPROBINGHASHST_H

#include <base_include.h>
template<typename Key,typename Value>
class LinearProbingHashST{
private:
    int N; //符号表的总键值数
    int M; //线性探查表的大小
    vector<Key> keys;
    vector<Value> vals;
public:
    LinearProbingHashST(int _M = 16):M(_M),N(0){
        keys.reserve(_M);
        vals.reserve(_M);
    }
    void put(Key key, Value val){
        if(N>=M/2) resize(2*M);
        int i;
        for(i = hash(key);keys[i]!=nullptr;i=(i+1)%M){
            if(keys[i] == key) {
                vals[i] = val; return;
            }
        }
        keys[i] = key;
        vals[i] = val;
        N++;
    }

private:
    int hash(Key key){
        return key%M;
    }
    void resize(int a);
};
#endif //SEARCH_ALGORITHMS_LINEARPROBINGHASHST_H
