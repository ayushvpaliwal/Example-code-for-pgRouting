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
    
    typedef adjacency_list< vecS, vecS, undirectedS,
        property< vertex_color_t, default_color_type,
            property< vertex_degree_t, int > > >
        Graph;
    typedef graph_traits< Graph >::vertex_descriptor Vertex;
    typedef graph_traits< Graph >::edge_descriptor Edge;
    typedef graph_traits< Graph >::vertices_size_type size_type;
    


    typedef std::pair< std::size_t, std::size_t > Pair;
    Pair edges[14] = { 
        Pair(0, 3), // a-d
        Pair(0, 5), // a-f
        Pair(1, 2), // b-c
        Pair(1, 4), // b-e
        Pair(1, 6), // b-g
        Pair(1, 9), // b-j
        Pair(2, 3), // c-d
        Pair(2, 4), // c-e
        Pair(3, 5), // d-f
        Pair(3, 8), // d-i
        Pair(4, 6), // e-g
        Pair(5, 6), // f-g
        Pair(5, 7), // f-h
        Pair(6, 7)  // g-h
          }; 

    Graph G(10);


    for (int i = 0; i < 14; ++i)
        add_edge(edges[i].first, edges[i].second, G);

    

    std::vector<double> centrality(num_vertices(G), 0.0);


    typedef property_map<Graph, vertex_index_t>::type vertexIndexMap;

    vertexIndexMap vertex_map = get(vertex_index, G);

    
    iterator_property_map<std::vector<double>::iterator,
                            vertexIndexMap
                            > vertex_itr_map(centrality.begin(), vertex_map);
    

    brandes_betweenness_centrality(G, vertex_itr_map);

    
    int n=num_vertices(G);
    for(int i=0; i<n; i++) {
        cout<<"abs BC of vertex "<<i<<":  "<<centrality[i]<<"  rel BC of vertex "<<i<<": "<<(centrality[i]*2)/(n*n-3*n+2)<<'\n';
    }
    

    return 0;
}
