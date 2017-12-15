/* Leilani Horlander-Cruz
   leilanihc112
   CSCE 221-506
   leilanihc112@tamu.edu */

// please implement it
#include "Graph.hpp"
#include <algorithm>
#include <vector>

// assuming graph is not disjoint initially
// assuming vertices are labeled from 0 to (number of vertices)-1 in increasing order
// assuming graph is undirected

Graph::Graph() {}

void Graph::buildGraph(ifstream& in)
{
	int numVertex;
	int numEdge;
	int numInteger = 0;
	string line;
	string integer;
	stringstream ss;
	getline(in,line);          //get line
	ss.str(line);      //add line to string stream
	ss >> integer;
	numVertex = stoi(integer);
	ss >> integer;
	numEdge = stoi(integer);
	
	for (int i = 0; i < numVertex; i++)
	{
		getline(in,line);
		ss.clear();
		ss.str(line);
		ss >> integer;
		int int_integer = stoi(integer);
		Vertex tempVertex = Vertex(i);
		vertices.push_back(tempVertex);
		while (int_integer != -1)
		{
			tempVertex.connectTo(int_integer);
			ss >> integer;
			int_integer = stoi(integer);
		}
		adj_list.push_back(tempVertex.edgeList);
	}	
}

void Graph::displayGraph(ostream& out)
{
	for(int i = 0; i < vertices.size(); i++)
    {
       cout << i << ":" << "\t ";
		for (int j = 0; j < adj_list.size(); j++)
		{
			list<Edge>::iterator itr = adj_list[j].begin();
			while (itr != adj_list[j].end())
			{
				if((*itr).start == i)
				{
					cout << (*itr).end << "\t";
				}
				++itr;
			}
		}
		cout << endl;
    }
}

void Graph::bipartite_f()
{
	//	possibility of two groups true or false
	bipartite = true;
	
	//	temp vector containing vector labels
	vector<int> tempLabels;
	
	for (int i = 0; i < vertices.size(); i++)
	{
		tempLabels.push_back(i);
	}
	
	group_1.push_back(0);
	
	tempLabels.erase(std::remove(tempLabels.begin(), tempLabels.end(), 0), tempLabels.end());
	
	// add any vertices adjacent to 0 to group_2
	for (int i = 0; i < adj_list.size(); i++)
	{
		list<Edge>::iterator itr = adj_list[i].begin();
		while (itr != adj_list[i].end())
		{
			if((*itr).start == 0)
			{
				for(int j = 0; j < vertices.size(); j++)
				{
					if((*itr).end == j)
					{
						group_2.push_back(j);
						tempLabels.erase(std::remove(tempLabels.begin(), tempLabels.end(), j), tempLabels.end());
					}
				}
			}
			++itr;
		}
	}
	
	int old_size = tempLabels.size();
	// keep doing this between two groups until tempLabels is empty (meaning all vertices have been visited)
	while (!tempLabels.empty())
	{
		for(int i = 0; i < group_2.size(); i++)
		{
			for (int j = 0; j < adj_list.size(); j++)
			{
				list<Edge>::iterator itr = adj_list[j].begin();
				while (itr != adj_list[j].end())
				{
					if((*itr).start == group_2[i])
					{
						old_size = tempLabels.size() + 1;
						while (old_size != tempLabels.size())
						{
							old_size = tempLabels.size();
							for (int k = 0; k < tempLabels.size(); k++)
							{
								if((*itr).end == tempLabels[k])
								{
									group_1.push_back(tempLabels[k]);
									tempLabels.erase(tempLabels.begin()+k);
								}
							}
						}
					}
					++itr;
				}
			}
		}
	
		for(int i = 0; i < group_1.size(); i++)
		{
			for (int j = 0; j < adj_list.size(); j++)
			{
				list<Edge>::iterator itr = adj_list[j].begin();
				while (itr != adj_list[j].end())
				{
					if((*itr).start == group_1[i])
					{
						old_size = tempLabels.size() + 1;
						while (old_size != tempLabels.size())
						{
							old_size = tempLabels.size();
							for (int k = 0; k < tempLabels.size(); k++)
							{
								if((*itr).end == tempLabels[k])
								{
									group_2.push_back(tempLabels[k]);
									tempLabels.erase(tempLabels.begin()+k);
								}
							}
						}
					}
					++itr;
				}
			}
		}
	}
	
	//	check if all vertices are in both groups
	if((group_1.size() + group_2.size()) != vertices.size())
		bipartite = false;
	
	//check if vertices in each group are adjacent to each other or not
	for(int i = 0; i < group_1.size(); i++)
	{
		for (int j = 0; j < adj_list.size(); j++)
		{
			list<Edge>::iterator itr = adj_list[j].begin();
			while (itr != adj_list[j].end())
			{
				if((*itr).start == group_1[i])
				{
					for(int k = 0; k < group_1.size(); k++)
					{
						if((*itr).end == group_1[k])
						{
							bipartite = false;
						}
					}
				}
				++itr;
			}
		}
	}
	for(int i = 0; i < group_2.size(); i++)
	{
		for (int j = 0; j < adj_list.size(); j++)
		{
			list<Edge>::iterator itr = adj_list[j].begin();
			while (itr != adj_list[j].end())
			{
				if((*itr).start == group_2[i])
				{
					for(int k = 0; k < group_2.size(); k++)
					{
						if((*itr).end == group_2[k])
						{
							bipartite = false;
						}
					}
				}
				++itr;
			}
		}
	}

	//	display message that grouping not possible if false
	if(bipartite == false)
	{
		cout << "Grouping is not possible for this map" << endl;
	}
	//display two groups of cities if true
	else
	{
		sort(group_1.begin(), group_1.end());
		sort(group_2.begin(), group_2.end());
		cout << "Group 1: ";
		for (int i = 0; i < group_1.size(); i++)
		{
			cout << group_1[i] << " ";
		}
		cout << endl;
		cout << "Group 2: ";
		for (int i = 0; i < group_2.size(); i++)
		{
			cout << group_2[i] << " ";
		}
		cout << endl;
	}
}

void Graph::shortestPath()
{
	// v1 is source city and v2 is destination city
	// check if grouping is possible. if not, display message and do not find shortest path
	if(bipartite == false)
		cout << "Grouping is not possible for this map, so shortest path will not be found between two cities" << endl;
	else
	{
		//accept input of two vertices
		int v1, v2;
		cout << "What is the departure city?: ";
		cin >> v1;
		cout << "What is the destination city?: ";
		cin >> v2;
		
		if ((v1 > vertices.size()-1) || (v2 > vertices.size()-1) || (v1 < 0) || (v2 < 0))
		{
			cout << "One or both of the input cities is/are not in the map" << endl;
		}
		else
		{
		// check if vertices are in the same group. if not, display message and do not find shortest path
			if((binary_search(group_1.begin(), group_1.end(), v1) && binary_search(group_1.begin(), group_1.end(), v2)) || (binary_search(group_2.begin(), group_2.end(), v1) && binary_search(group_2.begin(), group_2.end(), v2)))
			{
				list<int> Queue;
				vector<int> visited;
				int distance = 0;
				vector<int> parent;
				
				// mark all vertices as unvisited
				for (int i = 0; i < vertices.size(); i++)
				{
					visited.push_back(0);
					parent.push_back(vertices.size());
				}
				
				// enqueue source
				Queue.push_front(v1);
				int u;
				// mark source as visited
				visited[v1] = 1;
				// to keep track of source vertex
				parent[v1] = vertices.size()+1;
				
				// save parents of each vertex visited in graph until v2 is visited
				while (Queue.front() != v2)
				{
					// new start vertex for edges in path
					u = Queue.back();
					// dequeue 
					Queue.pop_back();
					for (int j = 0; j < adj_list.size(); j++)
					{
						list<Edge>::iterator itr = adj_list[j].begin();
						while (itr != adj_list[j].end())
						{
							if((*itr).start == u)
							{
								if (visited[(*itr).end] == 0)
								{
									// enqueue all unvisited adjacent vertices to start vertex
									Queue.push_front((*itr).end);
									// mark as visited
									visited[(*itr).end] = 1;
									parent[(*itr).end] = u;
								}
							}
							if (Queue.front() == v2)
								break;
							else
								++itr;
						}
					}
				}
				
				// error checking
				int node = v2;
				// if parent[node] not a vertex in the graph, try again but switch the vertices
				if (parent[node] >= vertices.size())
				{
					int temp_v1 = v1;
					int temp_v2 = v2;
					v2 = temp_v1;
					v1 = temp_v2;
					
					// mark all vertices as unvisited again
					for (int i = 0; i < vertices.size(); i++)
					{
						visited[i] = 0;
						parent[i] = vertices.size();
					}
					
					// enqueue source
					Queue.push_front(v1);
					int u;
					// mark source as visited
					visited[v1] = 1;
					// to keep track of source vertex
					parent[v1] = vertices.size()+1;
					
					// save parents of each vertex visited in graph until v2 is visited
					while (Queue.front() != v2)
					{
						// new start vertex for edges in path
						u = Queue.back();
						// dequeue 
						Queue.pop_back();
						for (int j = 0; j < adj_list.size(); j++)
						{
							list<Edge>::iterator itr = adj_list[j].begin();
							while (itr != adj_list[j].end())
							{
								if((*itr).start == u)
								{
									if (visited[(*itr).end] == 0)
									{
										// enqueue all unvisited adjacent vertices to start vertex
										Queue.push_front((*itr).end);
										// mark as visited
										visited[(*itr).end] = 1;
										parent[(*itr).end] = u;
									}
								}
								if (Queue.front() == v2)
									break;
								else
									++itr;
							}
						}
					}
					
					// error checking again
					int node = v2;
					// if parent[node] not a vertex in the graph, try again but switch the vertices
					if (parent[node] >= vertices.size())
					{
						cout << "Error: something went wrong..." << endl;
						exit(0);
					}
					else
					{
						// will backtrack until reaching v1, incrementing distance every step
						while(node != v1)
						{
							distance++;
							node = parent[node];
						}
					}
					
					// put back
					v1 = temp_v1;
					v2 = temp_v2;
				}
				else
				{	
					// will backtrack until reaching v1, incrementing distance every step
					while(node != v1)
					{
						distance++;
						node = parent[node];
					}
				}
					
				cout << "Shortest distance from city " << v1 << " to city " << v2 << " is " << distance << endl;
			}
			else
				cout << "Cities are not in the same group" << endl;
		}
	}
}