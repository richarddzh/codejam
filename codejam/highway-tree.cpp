//
//  highway-tree.cpp
//  codejam
//  Problem URL: http://hihocoder.com/contest/mstest2015sept2/problem/2
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXN 100009

using namespace std;

typedef long long int64;

struct Edge {
  int64 repeat;
  int64 dist;
};

map<pair<int, int>, Edge> edges;
set<int>  adj[MAXN];
int64 M, N;

Edge & GetEdge(int u, int v)
{
  if (u > v) { int h = u; u = v; v = h; }
  return edges[pair<int, int>(u, v)];
}

int GetChildNumber(int i, int from)
{
  int sum = 1;
  for (auto p = adj[i].begin(); p != adj[i].end(); p++) {
    if (*p == from) continue;
    int s = GetChildNumber(*p, i);
    GetEdge(i, *p).repeat = (N - s) * s;
    sum += s;
  }
  return sum;
}

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/highway-tree.in");
  ofstream output("/Users/richard/Programming/codejam/data/highway-tree.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int64 sum = 0;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) adj[i].clear();
  for (int i = 1; i < N; i++) {
    int u, v, k;
    cin >> u >> v >> k;
    GetEdge(u, v).dist = k;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  GetChildNumber(1, 0);
  for (auto p = edges.begin(); p != edges.end(); p++) {
    sum += p->second.dist * p->second.repeat;
  }
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    if (s.compare("QUERY") == 0) {
      cout << sum << endl;
    } else {
      int u, v, k;
      cin >> u >> v >> k;
      Edge & e = GetEdge(u, v);
      sum += (k - e.dist) * e.repeat;
      e.dist = k;
    }
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

