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
#include <boost/graph/bandwidth.hpp>


using namespace boost;
using namespace std;


int main(int, char*[])
{
    //using namespace boost;
    //using namespace std;
    typedef adjacency_list< vecS, vecS, undirectedS,
        property< vertex_color_t, default_color_type,
            property< vertex_degree_t, int > > >
        Graph;
    typedef graph_traits< Graph >::vertex_descriptor Vertex;
    typedef graph_traits< Graph >::edge_descriptor Edge;
    typedef graph_traits< Graph >::vertices_size_type size_type;
    


    typedef std::pair< std::size_t, std::size_t > Pair;
    Pair edges[17] = {  
        Pair(1, 2), 
        Pair(2, 5), 
        Pair(3, 6), 
        Pair(4, 9), 
        Pair(7, 8), 
        Pair(8, 5), 
        Pair(5, 6), 
        Pair(6, 9), 
        Pair(5, 10), 
        Pair(6, 11), 
        Pair(9, 12), 
        Pair(10, 11), 
        Pair(11, 12), 
        Pair(16, 17),
        Pair(10, 15),
        Pair(14, 15),
        Pair(15, 13)   
        }; 

    Graph G(17);


    for (int i = 0; i < 17; ++i)
        add_edge(edges[i].first, edges[i].second, G);
     


     std::cout << "bandwidth of Given Graph :" << bandwidth(G) << std::endl;
    for(int i=1; i<=17; i++) {
        std::cout << "bandwidth of "<<i<<"th vertex :"<< ith_bandwidth(i,G) << std::endl;
    }


    return 0;
}
