/*
  In the name of Allah, The Most Gracious and The Most Merciful.

  Glory be to You! We have no knowledge except what You have taught us.
  It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];     // adjacency matrix
bool vis[N];          // visited flag array

void dfs(int u) {
  vis[u] = 1;

  for (auto v: adj[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(0); cin.tie(0);
  
  int nodes, edges;
  cin >> nodes >> edges;

  for (int i = 0; i < edges; ++i) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  return 0;
}