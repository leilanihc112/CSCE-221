/* Leilani Horlander-Cruz
   leilanihc112
   CSCE 221-506
   leilanihc112@tamu.edu */

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Vertex.hpp"

using namespace std;

class Graph {
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<list<Edge>> adj_list; // adjacency list
    vector<Vertex> vertices;  // all vertices
	bool bipartite; // bool for bipartite function
	vector<int> group_1; // labels of vertices in group 1 for bipartite function
	vector<int> group_2; // labels of vertices in group 2 for bipartite function
    Graph(); // default constructor
    Graph(vector<list<Edge>> adjl) : adj_list(adjl) {} // constructor from adjl = adjacency list (optional)
	void buildGraph(ifstream& in);  // build a graph from the adjacency list
    void displayGraph(ostream& out);  // display the graph
	void bipartite_f(); // find possibility of partition of cities into two groups such that there is no edge between two vertices in each group
	void shortestPath(); // find shortest path between two vertices in same group if grouping is possible
};

#endif /* Graph_hpp */
