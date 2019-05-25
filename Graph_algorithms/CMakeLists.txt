cmake_minimum_required(VERSION 3.10)
project(Graph_algorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories( include )

set(SRC
        ${PROJECT_SOURCE_DIR}/src/Graph.cpp
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        include/DepthFirstSearch.h
        src/DepthFirstSearch.cpp
        include/DepthFirstPaths.h
        src/DepthFirstPaths.cpp
        include/BreadthFirstPaths.h
        src/BreadthFirstPath.cpp
        include/CC.h src/CC.cpp
        include/TwoColor.h
        include/Digraph.h
        src/Digraph.cpp
        include/DirectedDFS.h
        src/DirectedDFS.cpp
        include/DirectedCycle.h
        include/DepthFirstOrder.h
        include/Topological.h
        include/SCC.h
        include/Edge.h
        include/EdgeWeightedGraph.h
        include/LazyPrimMST.h
        include/PrimMST.h
        include/UF.h
        include/KruskalMST.h
        include/DirectedEdge.h
        include/EdgeWeightedDigraph.h
        include/DijkstraSP.h
        include/DijkstraAllPairsSP.h
        include/AcyclicSP.h
        include/BellmanFordSP.h)

link_directories(${PROJECT_SOURCE_DIR})
add_executable(Graph_algorithms ${SRC})
