//krushkal's algorithm

#include<bits/stdc++.h>
using namespace std;

class DSU
{
  int *parent;
  int *rank;
public:
    DSU (int n)
  {
    parent = new int[n];
      rank = new int[n];

    for (int i = 0; i < n; i++)
      {
	parent[i] = -1;
	rank[i] = 1;
      }
  }

  int _find (int x)
  {
    if (parent[x] == -1)
      {
	return x;
      }
    return parent[x] = _find (parent[x]);
  }

  void _union (int x, int y)
  {
    int s1 = _find (x);
    int s2 = _find (y);
    if (s1 != s2)
      {
	if (rank[s1] > rank[s2])
	  {
	    parent[s2] = s1;
	    rank[s2] += rank[s1];
	  }
	else
	  {
	    parent[s1] = s2;
	    rank[s1] += rank[s2];
	  }
      }
  }
};


class Graph
{
  vector <vector<int> >edgelist;
  int V;
public:
    Graph (int V)
  {
    this->V = V;
  }

  void addEdge (int x, int y, int w)
  {
    edgelist.push_back ({w, x, y});
  }

  void kruskalmst ()
  {
    sort (edgelist.begin (), edgelist.end ());
    DSU s (V);
    int ans = 0;

  for (auto edge:edgelist)
      {
	int w = edge[0];
	int x = edge[1];
	int y = edge[2];

	if (s._find (x) != s._find (y))
	  {
	    s._union (x, y);
	    ans += w;
	  }
      }
    cout << ans;
  }
};

int main ()
{
  Graph g (4);
  g.addEdge (0, 1, 10);
  g.addEdge (1, 3, 15);
  g.addEdge (2, 3, 4);
  g.addEdge (2, 0, 6);
  g.addEdge (0, 3, 5);
  
  g.kruskalmst ();

  return 0;
}
