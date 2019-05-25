//
// Created by horsetif on 19-4-20.
//

#ifndef SEARCH_ALGORITHMS_SEQUENTIALSEARCHST_H
#define SEARCH_ALGORITHMS_SEQUENTIALSEARCHST_H

#include <base_include.h>

template <typename Key,typename Value>
class SequentialSearchST{
public:
    struct Node {
        Key key;
        Value value;
        Node *next;

        Node(Key _key, Value _value) : key(_key), value(_value), next(nullptr) {}
    };

private:
    Node* head;
public:
    SequentialSearchST() : head(nullptr){}
    ~SequentialSearchST(){
        while(head!=nullptr){
            Node * p = head;
            head = head->next;
            delete p;
        }
    }
    const Node* get(Key &&key) const { // check the move semantics
        Node* f = head;
        while(f!=nullptr){
            if(f->key == key) return f;
            f = f->next;
        }
        return nullptr;
    }

    const Node* get(Key &key) const { // check the const function
        Node* f = head;
        while(f!=nullptr){
            if(f->key == key) return f;
            f = f->next;
        }
        return nullptr;
    }

    void put(Key key, Value value){
        Node * p = get_(key);
        if(p != nullptr){
            p->value = value;
            return;
        }
        p = new Node(key,value);
        p->next= head;
        head = p;
    }
    int size(){
        Node* f = head;
        int cnt = 0;
        while(f!=nullptr){
            f = f->next;
            cnt++;
        }
        return cnt;
    }
    void del(Key key){
        if(head == nullptr) return;
        Node *p = head;
        Node *pre = nullptr;
        while(p!=nullptr && p->key!=key){
            pre = p;
            p = p->next;
        }
        if(p!=nullptr && pre!=nullptr){
            pre->next = p->next;
        }
        return;
    }
    vector<Key> keys(){
        Node* f = head;
        vector<Key> ans;
        while(f!=nullptr){
            ans.push_back(f->key);
            f = f->next;
        }
        return ans;
    }

private:
    Node* get_(Key key){
        Node* f = head;
        while(f!=nullptr){
            if(f->key == key) return f;
            f = f->next;
        }
        return nullptr;
    }
};

#endif //SEARCH_ALGORITHMS_SEQUENTIALSEARCHST_H
