// Program to find Dijkstra's shortest path using 
// priority_queue in STL 

#include<iostream>
#include<vector>
#include <algorithm>
#include<set>
#include<list>
using namespace std;
# define INF 0x3f3f3f3f 

// This class represents a directed graph using  
// adjacency list representation 
class Graph
{
	int V;    // No. of vertices 

	// In a weighted graph, we need to store vertex  
	// and weight pair for every edge 
	list< pair<int, int> > *adj;

public:
	Graph(int V);  // Constructor 

	// function to add an edge to graph 
	void addEdge(int u, int v, int w);

	// prints shortest path from s 
	void shortestPath(int s);
};

// Allocates memory for adjacency list 
Graph::Graph(int V)
{
	this->V = V;
	adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}


void Graph::shortestPath(int src)
{
	// Create a set to store vertices that are being 
	// prerocessed 
	

	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 
	vector<int> order;
	vector<int> dummy;
	// Insert source itself in Set and initialize its 
	// distance as 0. 
	dummy.push_back(src);
	//order[src] = 0;

	/* Looping till all shortest distance are finalized
	   then setds will become empty */
	while (!dummy.empty())
	{
		// The first vertex in Set is the minimum distance 
		// vertex, extract it from set. 
		int u = *(dummy.begin());
		dummy.erase(dummy.begin());

		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted distance (distance must be first item 
		// in pair) 
		
		
		order.push_back(u);		// 'i' is used to get all adjacent vertices of a vertex 
		 
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = (*i).first;
			if(order.at(u)==v)
			dummy.push_back(v);
			//int weight = (*i).second;

			//  If there is shorter path to v through u. 
			
		}
	}

}

int main()
{
	// create the graph given in above fugure 
	int V = 4;
	Graph g(V);

	//  making above shown graph 
	/*g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);*/
	g.addEdge(0, 1, 4);
	g.addEdge(0, 2, 8);
	g.addEdge(1, 3, 8);
	g.addEdge(2, 3, 2);
	g.shortestPath(0);

	return 0;
}
