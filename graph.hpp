#pragma ONCE

class basic_graph
{
public:
	basic_graph();

	void add_edge(int, int);

	void rem_edge(int, int);

	template <typename T>
	void forall_neighbours(int, T&&);

	template <typename T>
	void forall_nodes(T&&);
};
