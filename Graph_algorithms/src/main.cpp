/*
#include <iostream>
#include <fstream>
#include "../include/Graph.h"
#include "../include/DepthFirstSearch.h"
#include "../include/DepthFirstPaths.h"
#include "../include/BreadthFirstPaths.h"
#include "../include/CC.h"
#include "../include/TwoColor.h"
using namespace std;
int main() {
    string path_name="../data/tinyG.txt";
    Graph G(path_name);
    cout<<G.toString()<<endl;
    cout<<"G's max Degree is : "<<maxDegree(G)<<endl;
    cout<<"G's index 4 's degree is : "<<degree(G,4)<<endl;
    cout<<"G's self loop is : "<<numberOfSelfLoops(G)<<endl;
    cout<<"G's average degree is: "<<avgDegree(G)<<endl;

    DepthFirstSearch search(G,0);
    cout<<"the node which connected to node 0 are: "<<endl;
    for(int i=0;i<G.get_V();i++){
        if(search.marked(i)) cout<<i<<" ";
    }
    cout<<endl;
    cout<<"the total num is : "<<search.get_count()<<endl;

    DepthFirstPaths path(G,0);
    cout<<"the path from 0 to 3 is : "<<endl;
    vector<int> ans=path.pathTo(3);
    for(auto a : ans) cout<<a<<" ";
    cout<<endl;

    BreadthFirstPaths Bpath(G,0);
    cout<<"the Bpath from 0 to 3 is : "<<endl;
    vector<int> ans_b=Bpath.pathTo(3);
    for(auto a : ans_b) cout<<a<<" ";
    cout<<endl;

    CC cc(G);
    cout<<" the id of 1,8, 11 are : "<<endl;
    cout<<cc.get_id(1)<<" "<<cc.get_id(8)<<" "<<cc.get_id(11)<<endl;

    TwoColor color(G);
    cout<<"the graph is a two color graph ? "<<endl;
    cout<<color.is_two_color()<<endl;

    return 0;
}
 */
 /*
#include <iostream>
#include <stack>
#include "Digraph.h"
#include "DirectedDFS.h"
#include "DirectedCycle.h"
#include "DepthFirstOrder.h"
#include "Topological.h"
#include "SCC.h"
using namespace std;
int main(){
    string path_name="../data/tinyDG.txt";
    Digraph D(path_name);
    cout<<D.toString()<<endl;
    //Digraph R=D.reverse();
    //cout<<endl<<endl<<"the reverse Digraph is :"<<endl;
    //cout<<R.toString()<<endl;

    DirectedDFS DFS(D,0);
    cout<<"4 is the path of 0 ? "<<DFS.marked(4)<<endl;
    cout<<"9 is the path of 0 ? "<<DFS.marked(9)<<endl;

    DirectedCycle cycle(D);
    vector<int> ans=cycle.get_cycle();
    cout<<"this cycle is :"<<endl;
    for(auto a : ans){
        cout<<a<<" ";
    }
    cout<<endl;

    string DAG_path="../data/DAG.txt";
    Digraph DAG(DAG_path);
    cout<<D.toString()<<endl;
    Topological Top(DAG);
    vector<int> dag_path=Top.get_order();
    cout<<"the top order is :"<<endl;
    for(auto a : dag_path){
        cout<<a<<" ";
    }
    cout<<endl;

    cout<<"get the Strong connected id "<<endl;
    SCC scc(D);
    for(int i=0;i<D.get_V();i++){
        cout<<scc.get_id(i)<<" ";
    }
    cout<<endl;

    return 0;
}
*/
 /*
 #include<iostream>
#include <Edge.h>

#include <algorithm>

#include <EdgeWeightedGraph.h>

#include <LazyPrimMST.h>

#include <PrimMST.h>

#include <KruskalMST.h>
 using namespace std;
 int main(){
     string MST_path = "../data/tinyEWG.txt";
     EdgeWeightedGraph G(MST_path);
     cout<<G.toString()<<endl;
     vector<Edge> ans = G.get_adj(0);
     for(auto d : ans) cout<<d.toString()<<endl;
     cout<<endl<<endl;
     LazyPrimMST prim(G);
     cout<<"the LazyMST is : "<<endl;
     for(auto d : prim.edge()) cout<<d.toString()<<endl;
     cout<<endl<<endl;
     cout<<"the MST is : "<<endl;
     PrimMST primm(G);
     for(auto d : primm.edge()) cout<<d.toString()<<endl;
     cout<<endl<<endl<<"the KruskalMST is : "<<endl;
     KruskalMST krus(G);
     for(auto d : krus.edge()) cout<<d.toString()<<endl;


     return 0;
 }
  */
 /*
#include <iostream>

#include<EdgeWeightedDigraph.h>

#include <DijkstraSP.h>

#include <DijkstraAllPairsSP.h>

#include <AcyclicSP.h>

#include <BellmanFordSP.h>
 using namespace std;

 int main(){
     string SP_path = "../data/tinyEWD.txt";
     EdgeWeightedDigraph EG(SP_path);
     cout<<EG.toString()<<endl<<endl<<endl;
     DijkstraSP DJ(EG,0);
     for(auto a : DJ.edge()) cout<<a.toString()<<endl;
     cout<<endl<<endl<<endl;
     DijkstraAllPairsSP D(EG);
     for(auto a : D.path(0,5)) cout<<a.toString()<<endl<<endl<<endl;

     string A_SP_path = "../data/tinyEWDAG.txt";
     AcyclicSP ac(A_SP_path,5);
     for(auto a : ac.pathTo(6)) cout<<a.toString()<<endl;

     string SP_path_n = "../data/tinyEWDn.txt";
     cout<<"nagetive search: "<<endl;
     EdgeWeightedDigraph Na(SP_path_n);
     BellmanFordSP BF(Na,0);
     for(auto p : BF.negativeCycle()) cout<<p.toString()<<" "<<endl;
     //for(auto p : BF.pathTo(6)) cout<<p.toString()<<endl;
     return 0;
 }
  */

#include <iostream>
 struct A{};
 struct B{};
  typedef A C;
 typedef int Money;
 class account{
     typedef B C;
 public:
     C get(){ return B{};}
     typedef  double Money;
     Money a=10.0;
 private:

     C aaa = B{};

 };
 C bb = A{};
 int main(){

 }