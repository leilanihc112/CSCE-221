/* Leilani Horlander-Cruz
   leilanihc112
   CSCE 221-506
   leilanihc112@tamu.edu */

#include <iostream>
#include <string>

#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    try{
        if (argc != 2) throw invalid_argument("Usage: ./main <file name>");
        ifstream in(argv[1]);
        if (!in) throw invalid_argument("Invalid file name or unable to open file.");
        Graph g;
        g.buildGraph(in);
        g.displayGraph(cout);
		g.bipartite_f();
		g.shortestPath();
        return 0;
    }
    catch (exception& error){
        cerr << "Error: " << error.what() << endl;
    }
}