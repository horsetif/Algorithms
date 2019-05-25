//
// Created by horsetif on 19-4-23.
//

#ifndef SEARCH_ALGORITHMS_REDBLACKBST_H
#define SEARCH_ALGORITHMS_REDBLACKBST_H

#include <base_include.h>
template <typename Key,typename Value>
class RedBlackBST{
private:
    // 定义BST的叶子节点
    static bool RED = true;
    static bool BLACK = false;
    class Node{
    public:
        Key key;
        Value value;
        int N;
        Node* left;
        Node* right;
        bool color;
        Node(Key _key, Value _value, int _N,bool _color = BLACK):key(_key),value(_value),N(_N),
                                             color(_color),(nullptr),right(nullptr) {}
    };
    Node* root;
public:
    //新建BST方法类
    RedBlackBST():root(nullptr){}
    //递归删除BST方法类
    ~RedBlackBST(){
        del_tree(root);
    }
    int size(){
        //获取整个BST的大小
        return size(root);
    }
    const Node* get(Key key){
        //获取当前变量所对应的值（返回的是所对应的叶子指针。如果没有查到，就返回空指针。
        //不允许修改当前叶子节点所对应的值。
        return get(root, key);
    }
    void put(Key key, Value value){
        //插入key节点，key节点对应的值为value
        root = put(root, key, value);
        root->color = BLACK;
    }
    const Node* floor(Key key){
        //查找小于等于key值的Node
        return floor(root,key);
    }
    const Node* min(){
        //查找当前树的最小值，返回Node节点
        return min(root);
    }
    const Node* max(){
        //查找当前树的最大值，返回node节点
        return max(root);
    }
    const Node* select(int k){
        //查询第k个节点的值，返回node节点
        return select(root,k);
    }
    int rank(Key key){
        //查询key值所对应的排名，按照顺序数第几个。
        return rank(key,root);
    }
    void delmin(){
        //删除最小值
        root = delmin(root);
    }
    void del(Key key){
        //删除对应的key值
        root = del(root, key);
    }
    vector<Key> keys(){
        //返回整个树的所有key值（中序遍历）
        if(root == nullptr) return vector<Key>();
        else
            return keys(min(root)->key,max(root)->key);
    }
    vector<Key> keys(Key lo, Key hi){
        //返回给定范围的所有key值。
        vector<Key> ans;
        keys(root, ans,lo,hi);
        return ans;
    }

private:
    bool isRed(Node* x){
        /*
         * 查看指向当前节点的边是不是红边
         */
        if(x == nullptr) return false;
        else return x->color == RED;
    }

    Node* rotateLeft(Node* root){
        /*左旋红黑树（如果红边在右边）
         * 算法：把根节点的右子树提上来，作为根节点。
         */
        Node* p = root->right;
        if(p == nullptr) return root;//无红边，不旋转
        root->right = p->left;
        p->left = root;
        p->color = root->color;
        root->color = RED;
        p->N = root->N;
        root->N = size(root->left) + size(root->right) + 1;
        return p;
    }

    Node* rotateRight(Node* root){
        /*右旋红黑树（如果红边在左边）
         * 算法：把根节点的左子树提上来，作为根节点。
         */
        Node* p = root->left;
        if(p == nullptr) return root;
        root->left = p->right;
        p->right = root;
        p->color = root->color;
        root->color = RED;
        p->N = root->N;
        root->N = 1 + size(root->left) + size(root->right);
        return p;
    }

    void flipColors(Node* root){
        root->color = RED;
        root->left->color = BLACK;
        root->right->color =  BLACK;
    }

    int size(Node* root){
        //获取当前节点的大小，如果整个节点为空，那么就返回0
        if(root == nullptr) return 0;
        else return root->N;
    }

    Node* get(Node* root, Key key){
        //从root开始查找叶子节点的值
        //算法：递归查找，如果根小于key，就往右找。如果根大于key，就往左找。
        if(root == nullptr) return nullptr;
        if(root->key == key) return root;
        else if(root->key > key) return get(root->left,key);
        else return get(root->right,key);
    }

    Node* put(Node* root, Key key, Value value){
        /*
        从root节点插入key值。
        算法：如果查找原来的树有key值，那么替换就可以。
            如果没有，那么就按照搜索的方法向下查找。
            最后利用回溯的方法更新每个节点的size。
         */
        if(root == nullptr) return new Node(key,value,1,RED);
        if(root->key == key)
            root->value = value;
        else if(root->key > key)
            root->left = put(root->left,key,value);
        else
            root->right = put(root->right,key,value);
        /*旋转规则：
         * 1，如果右边是红，左边是黑，那么左旋
         * 2，如果左边是红，左边的左边也是红，那么右旋
         * 3，如果两个边都是红色，那么颜色变换
         */
        if(isRed(root->right) && !isRed(root->left)) root = rotateLeft(root);
        if(isRed(root->left) && (root->left!=NULL) && isRed(root->left->left))
            root=rotateRight(root);
        if(isRed(root->left) && isRed(root->right)) flipColors(root);

        root->N = size(root->left) + size(root->right) + 1;
        return root;
    }

    Node* floor(Node* root, Key key){
        /*查找小于等于key的最大值。
         * 算法：
         * 如果查到，那么直接返回就行。
         * 如果根节点大于key值，那么要向左查询。
         * 若果根节点小于key值，那么要向右查询。假设向右查不到，那么最大值就是这个根节点。
         *
         */
        if(root == nullptr) return nullptr;
        if(root->key == key) return root;
        else if(root->key > key) return floor(root->left, key);
        else{
            Node* temp = floor(root->right,key);
            if(temp == nullptr) return root;
            else return temp;
        }
    }

    Node* min(Node* root){
        /*
         * 如果左节点有值，就继续向左找。
         */
        if(root == nullptr) return nullptr;
        else if(root->left == nullptr) return root;
        else return min(root->left);
    }

    Node* max(Node* root){
        /*
         *如果右节点有值，就继续往右找。
         */
        if(root == nullptr) return nullptr;
        else if(root->right == nullptr) return root;
        else return max(root->right);
    }
    Node* select(Node* root, int k){
        /*  查找第k个Node
         * 算法：如果根节点左节点的值等于k，那么返回根节点。
         * 如果左节点的N大于k，那么想左查询。
         * 如果左节点的N小于k，那么向右查询，查询第k-t-1个节点，(t为左边节点的总数）
         */
        if(root == nullptr) return nullptr;
        if(root->left == nullptr) return select(root->right,k-1);
        int t = root->left->N;
        if(t > k) return select(root->left,k);
        else if(t < k) return select(root->right,k-t-1);
        else return root;
    }
    int rank(Key key, Node* root){
        /* 查找key值的rank值。
         * 算法：如果根节点大于key值，那么就向左查。
         * 如果根节点小于key值，那么就向右查，再加上左节点的N值再加1.
         * 如果根节点就是key值，那么就返回根的左节点的N值。
         */
        if(root == nullptr) return 0;
        if(root->key > key) return rank(key,root->left);
        else if(root->key < key) return 1+size(root->left)+rank(key,root->right);
        else return size(root->left);
    }
    Node* delmin(Node* root){
        /*删除根节点下的最小值，返回根节点。
         * 算法：不停向左查找，查到树的最小值，然后把最小值的父亲节点的左链接连到父亲节点的右节点上。
         * 然后回溯更新N值。
         */
        if(root == nullptr) return nullptr;
        if(root->left == nullptr) return root->right;
        root->left = delmin(root->left);
        root->N = size(root->left) + size(root->right) + 1;
        return root;
    }
    Node* del(Node* root, Key key){ // 对于红黑树必须要有新的解法。
        /* 从根节点删除对应的key值。 返回根节点
         * 算法：1，按BST查找。
         *      2，找到对应值之后，如果只有一个支，那么就返回存在的支。
         *      3，如果有两个支，那么找到右支的最小值，替换，然后删除root。
         *      4，回溯更新N值。
         */
        if(root == nullptr) return nullptr;
        if(root->key < key) root->left = del(root->left,key);
        if(root->key > key) root->right = del(root->right,key);
        else{
            if(root->right == nullptr) return root->left;
            if(root->left == nullptr) return root->right;
            Node* tmp = root;
            root = min(tmp->right);
            root->right = delmin(tmp->right);
            root->left = tmp->left;
            delete tmp;
        }
        root->N = size(root->left) + size(root->right) + 1;
        return root;
    }

    void keys(Node* root, vector<Key> &que, Key lo, Key hi){
        /*
         * 用中序遍历查找。如果满足条件就加入vector中。
         */
        if(root == nullptr) return ;
        if(lo < root->key) keys(root->left,que,lo,hi);
        if(lo <= root->key && hi >= root->key) que.push_back(root->key);
        if(hi->key > root->key) keys(root->right,que,lo,hi);
    }

    void del_tree(Node* root){
        //递归方法，利用后序遍历，先删除两个叶子节点，最后删除根节点。
        if(root == nullptr) return;
        del_tree(root->left);
        del_tree(root->right);
        delete root;
    }
};
#endif //SEARCH_ALGORITHMS_REDBLACKBST_H
