//
// Created by horsetif on 19-4-23.
//

#ifndef SEARCH_ALGORITHMS_SEPARATECHAININGHASHST_H
#define SEARCH_ALGORITHMS_SEPARATECHAININGHASHST_H

#include <base_include.h>
#include <SequentialSearchST.h>
template<typename Key,typename Value>
class SeparateChainingHashST{
private:
    int N; // 键值对总数
    int M; //散列表大小
    vector<SequentialSearchST<Key,Value>> st;
public:
    SeparateChainingHashST(int _M):M(_M),N(0){
        st.reserve(_M);
    }
    SeparateChainingHashST():SeparateChainingHashST(997){}
    const SequentialSearchST::Node* get(Key key){
        return st[hash(key)].get(key);
    }
    void put(Key key, Value val){
        st[hash(key)].put(key,val);
    }
private:
    int hash(Key key){
        /*返回key值对应的hash值。
         * 需要重写这里。
         */
        return key%M;
    }
};
#endif //SEARCH_ALGORITHMS_SEPARATECHAININGHASHST_H
