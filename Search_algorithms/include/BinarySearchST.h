//
// Created by horsetif on 19-4-21.
//

#ifndef SEARCH_ALGORITHMS_BINARYSEARCHST_H
#define SEARCH_ALGORITHMS_BINARYSEARCHST_H

#include <base_include.h>
template <typename Key,typename Value>
class BinarySearchST{
private:
    vector<Key> keys;
    vector<Value> values;
    int N;
public:
    BinarySearchST(int capacity):N(0){
        keys.reserve(capacity);
        values.reserve(capacity);
    }
    int size(){
        return N;
    }
    const Value* get(Key key){
        int id = rank(key);
        vector<Value> ans;
        if(keys[id] != key) return nullptr;
        ans.push_back(values[id]);
        return &values[id];
    }
    int rank(Key key){
        int low = 0, high = N-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(keys[mid] < key) low = mid+1;
            else if(keys[mid] > key) high = mid-1;
            else return mid;
        }
        return low;
    }
    void put(Key key, Value value){
        int id = rank(key);
        if(keys[id] == key){
            values[id] = value;
            return;
        }
        else{
            for(int i=N;i>id;i--){
                keys[i+1] = keys[i];
                values[i+1] = values[i];
            }
            keys[id] = key;
            values[id] = value;
            N++;
        }
    }
    void del(Key key){
        int id = rank(key);
        if(keys[id] != key) return;
        else{
            if(id == N) {
                values.pop_back();
                keys.pop_back();
                N--;
                return;
            }
            else{
                for(int i=id;i<N;i++){
                    cout<<keys[i+1];
                    values[i] = values[i+1];
                    keys[i] = keys[i+1];
                    cout<<values[i]<<" "<<keys[i]<<endl;
                }
                values.pop_back();
                keys.pop_back();
                N--;
                return;
            }
        }
    }
    const Key* min(){
        if(N==0) return nullptr;
        return &keys[0];
    }
    const Key* max() {
        if(N == 0) return nullptr;
        return &keys[N];
    }
    const Key* select(int k){
        if(N < k) return nullptr;
        return &keys[k];
    }
    const Key* ceiling(Key key){
        int id = rank(key);
        return &keys[id];
    }
    const Key* floor(Key key){
        int id = rank(key);
        if(id != 0) return &keys[id-1];
        else return &keys[id];
    }
    vector<Key> get_keys(Key lo, Key hi){
        int id_low = rank(lo);
        int id_high = rank(hi);
        vector<Key> ans;
        for(int i= id_low;i<=id_high;i++){
            ans.push_back(keys[i]);
        }
        return ans;
    }
    vector<Key> get_all_keys(){
        vector<Key> ans;
        for(int i=0;i<=N;i++){
            ans.push_back(keys[i]);
        }
        return ans;
    }
};

#endif //SEARCH_ALGORITHMS_BINARYSEARCHST_H
