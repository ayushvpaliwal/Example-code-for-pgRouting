//=======================================================================
// Copyright 1997, 1998, 1999, 2000 University of Notre Dame.
// Authors: Andrew Lumsdaine, Lie-Quan Lee, Jeremy G. Siek
//          Doug Gregor, D. Kevin McGrath
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include <boost/config.hpp>
#include <vector>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/properties.hpp>
#include <boost/graph/betweenness_centrality.hpp>

using namespace boost;
using namespace std;


int main(int, char*[])
{   
    typedef adjacency_list<vecS, vecS,
                            directedS,
                            no_property,
                            property<edge_weight_t, int>
                            > graph;
    
    graph G;

    typedef graph::vertex_descriptor vertex;
    typedef graph::edge_descriptor edge;



    add_edge(1,2, 1,G);
    add_edge(2,5, 1,G);
    add_edge(3,6, 1,G);
    add_edge(4,9, 1,G);
    add_edge(7,8, 1,G);
    add_edge(8,5, 1,G);
    add_edge(5,6, 1,G);
    add_edge(6,9, 1,G);
    add_edge(5,10, 1,G);
    add_edge(6,11, 1,G);
    add_edge(9,12, 1,G);
    add_edge(10,11, 1,G);
    add_edge(11,12, 1,G);
    add_edge(16,17, 1,G);
    add_edge(10,15, 1,G);
    add_edge(14,15, 1,G);
    add_edge(15,13, 1,G);


    std::vector<double> centrality(num_vertices(G), 0.0);

    brandes_betweenness_centrality(
        G, 
        centrality_map(
            make_iterator_property_map(centrality.begin(), get(vertex_index, G),
                                            double()))
        .vertex_index_map(get(vertex_index, G))
        .weight_map(get(edge_weight, G)));

    
    int n=num_vertices(G);
    for(int i=1; i<=n; i++) {
        cout<<"abs BC of vertex "<<i<<":  "<<centrality[i]<<"  rel BC of vertex "<<i<<": "<<(centrality[i]*2)/(n*n-3*n+2)<<'\n';
    }

    return 0;
}
