#include "graph.hpp"

class basic_graph
{
private:
	map<int, set<int>> neighbours;
	map<int, int> in_out_deg;
};

basic_graph::basic_graph(){}

void basic_graph::add_edge(int x, int y)
{
	++in_out_deg[x];
	++in_out_deg[y];
	neighbours[x].push_back(y);
}

void basic_graph::rem_edge(int x, int y)
{
	--in_out_deg[x];
	--in_out_deg[y];
	neighbours[x].erase(y);

	if(in_out_deg[x] == 0)
	{
		neighbours.erase(x);
		in_out_deg.erase(x);
	}
}

template <typename T>
void basic_graph::forall_neighbours(int x, T&& t)
{
	for(auto y : neighbours[x])
		t(y);
}

template <typename T>
void basic_graph::forall_nodes(T&& t)
{
	for(auto x : in_out_deg)
		t(x.first);
}
