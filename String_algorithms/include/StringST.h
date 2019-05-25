//
// Created by horsetif on 19-4-25.
//

#ifndef STRING_ALGORITHMS_STRINGST_H
#define STRING_ALGORITHMS_STRINGST_H

#include <base_include.h>
template<typename Value>
class StringST{
private:

public:
    StringST();
    void put(string key, Value val);
    const Value* get(string key);
    void del(string key);
    bool contains(string key);
    bool isEmpty();
    string longestPrefixOf(string s);//s 的前缀中最长的键
    vector<string> keysWithPrefix(string s); // 所有以s为前缀的键
    vector<string> keysThatMatch(string s);//所有和s匹配的键
    int size();
    vector<string> keys();
};
#endif //STRING_ALGORITHMS_STRINGST_H
