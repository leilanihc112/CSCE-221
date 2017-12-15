/* Leilani Horlander-Cruz
   leilanihc112
   CSCE 221-506
   leilanihc112@tamu.edu */

// please implement it

#include "Vertex.hpp"
    
// connect this vertex to a specific vertex (adding edge)
void Vertex::connectTo(int end)
{
	Edge tempEdge = Edge(label,end,1);
	edgeList.push_back(tempEdge);
}