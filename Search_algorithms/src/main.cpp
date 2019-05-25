#include <base_include.h>
#include <all_method.h>
int main(){
    BinarySearchST<char,int> bs(10);
    bs.put('k',1);
    bs.put('c',2);
    bs.put('d',3);
    //bs.del('c');
    vector<char> ans = bs.get_all_keys();
    for(auto a : ans) cout<<a<<" ";
    cout<<endl;

}