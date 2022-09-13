/*
Title  : Program to implement Dijkstra’s algorithm to shortest path.
*/

// Program -

#include <iostream>
using namespace std;
int visit[10];
class Graph
{
private:
  int n, l, i, j, cost[10], mat[10][10], dest[10], path[20];
  int edges, min, ncost, x, curdest, s, d, last, k, m;

public:
  Graph()
  {
    edges = 1;
    ncost = 0;
  }
  void DJ(int mat[10][10], int n);
  void display();
  void read();
};

void Graph::read()
{
  cout << "Enter Number Vertices -->>";
  cin >> n;
  cout << "\nEnter The Adjacency Matrix  -->>\n";
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      cin >> mat[i][j];
      if (mat[i][j] == 0)
        mat[i][j] = 9999;
    }
  }
  DJ(mat, n);
}
void Graph ::DJ(int mat[10][10], int n)
{
  cout << "\nEnter The Source Vertex -->> ";
  cin >> s;
  cout << "\nEnter the Destination Vertex -->> ";
  cin >> d;

  for (i = 1; i <= n; i++)
  {
    cost[i] = 9999;
  }
  cost[s] = 0;
  x = s;
  visit[x] = 1;
  while (x != d)
  {
    curdest = cost[x];
    min = 9999;
    for (i = 1; i <= n; i++)
    {
      if (visit[i] == 0)
      {
        ncost = curdest + mat[x][i];
        if (ncost < cost[i])
        {
          cost[i] = ncost;
          dest[i] = x;
        }
        if (cost[i] < min)
        {
          min = cost[i];
          k = i;
        }
      }
    }
    x = k;
    visit[x] = 1;
  }
  display();
}

void Graph ::display()
{
  l = d;
  path[last] = d;
  last++;

  while (dest[l] != s)
  {
    m = dest[l];
    l = m;
    path[last] = l;
    last++;
  }

  path[last] = s;
  cout << "Shortest path is -->>";
  for (l = last; l >= 1; l--)
  {
    cout << "\n"
         << path[l] << "->" << path[l - 1] << ": " << mat[path[l]][path[l - 1]];
  }

  cout << "\n Total Cost: " << cost[d];
}

int main()
{
  Graph G;
  G.read();
}

/* OUTPUT -

Enter Number Vertices -->>8

Enter The Adjacency Matrix  -->>
0 1 1 1 1 0 0 0
1 0 0 0 0 1 0 0
1 0 0 0 0 1 0 0
1 0 0 0 0 0 1 0
1 0 0 0 0 0 1 0
0 1 1 0 0 0 0 1
0 0 0 1 1 0 0 1
0 0 0 0 0 1 1 0

Enter The Source Vertex -->> 1

Enter the Destination Vertex -->> 8
shortest path is
1->2: 1
2->6: 1
6->8: 1

Total Cost: 3

*/
