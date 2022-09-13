/*
Title  : Program to implement Kruskal’s algorithm to find Minimum Cost Spanning Tree.
*/

#include <iostream>
using namespace std;
int visited[10];

class Kruskal
{
public:
  int edge, mincost, n, i, j, cost[10][10], min, u, v, a, b;
  Kruskal()
  {
    edge = 1;
    mincost = 0;
  }
  void read();
  void Kus(int cost[10][10], int n);
};

void Kruskal::read()
{
  cout << "Enter Number Vertices -->>";
  cin >> n;

  cout << "Enter The Adjacency Matrix  -->>\n";

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      cin >> cost[i][j];
      if (cost[i][j] == 0)
      {
        cost[i][j] = 9999;
      }
    }
  }

  Kus(cost, n);
}

void Kruskal::Kus(int cost[10][10], int n)
{
  while (edge < n)
  {
    min = 9999;

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (cost[i][j] < min)
        {
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }
    while (visited[u])
      u = visited[u];
    while (visited[v])
      v = visited[v];
    cout << endl;
    if (u != v)
    {
      edge++;
      cout << "Edge   " << a << "  -->>  " << b << "     Weight   " << min << endl;
      mincost = mincost + min;
      visited[v] = u;
    }
    cost[a][b] = cost[b][a] = 9999;
  }
  cout << "Min Cost   -->> " << mincost;
}

int main()
{
  Kruskal G;
  G.read();
}

/* OutPut -

Enter Number Vertices -->>6
Enter The Adjacency Matrix  -->>
0 2 3 0 0 0
2 0 5 3 4 0
3 5 0 0 4 0
0 3 0 0 2 3
0 4 4 2 0 5
0 0 3 0 0 0

Edge   0  -->>  1     Weight   2

Edge   3  -->>  4     Weight   2

Edge   0  -->>  2     Weight   3

Edge   1  -->>  3     Weight   3

Edge   3  -->>  5     Weight   3
Min Cost   -->> 13

*/