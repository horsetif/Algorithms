#include <base_include.h>
#include <Selection.h>
#include <Insertion.h>
#include <Shell.h>
#include <Merge.h>
#include <Quick.h>
#include <MaxPQ.h>
#include <PQsort.h>
#include <array>
int main() {
    vector<int> a;
    for (int i = 0; i < 50; i++) {
        a.push_back(rand() % 50);
    }
    PQsort<int> s;
    s.sort(a);
    s.show(a);
    cout << s.isSorted(a);
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        cp++;
    }
    array<int,10> a1 = {0,1};
    a1 = {2,2};
    for(auto m : a1){cout<<m<<endl;}
    vector<int> test={1,2,3,4,5,6,7,8,9,10};
    auto it = test.begin();
    it = test.erase(test.end(),test.end());
    for(auto k : test) cout<<k<<" ";
}