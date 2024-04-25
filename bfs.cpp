/*
  In the name of Allah, The Most Gracious and The Most Merciful.

  Glory be to You! We have no knowledge except what You have taught us.
  It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];
int lev[N];         // level of every node from source(s) / shortest path 

void bfs(int s) {
  lev[s] = 0;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v: adj[u]) {
      if (lev[v] == -1) {
        lev[v] = lev[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(0); cin.tie(0);
  
  int nodes, edges;
  cin >> nodes >> edges;

  memset(lev, -1, 4 * N);
  for (int i = 0; i < edges; ++i) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bfs(1);

  return 0;
}