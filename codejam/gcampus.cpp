//
//  gcampus.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/4284486/dashboard#s=p2
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXN 100

using namespace std;

typedef long long int64;

int T, N, M;

struct Edge {
  int64 cost;
  int64 dist;
  void init(int64 val) {
    cost = val;
    dist = val;
  }
};

struct Graph {
  Edge e[MAXN][MAXN];
  vector<pair<int, int> > edges;
  int n;
  void init(int _n) {
    n = _n;
    edges.clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) e[i][j].init(-1);
      e[i][i].init(0);
    }
  }
  void addEdge(int u, int v, int c) {
    edges.push_back(make_pair(u, v));
    e[u][v].cost = c;
    updateDist(u, v, c);
  }
  void updateDist(int u, int v, int64 c) {
    if (e[u][v].dist < 0 || e[u][v].dist > c) e[u][v].dist = c;
    if (e[v][u].dist < 0 || e[v][u].dist > c) e[v][u].dist = c;
  }
  void floydWarshall() {
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) {
          int64 eik = e[i][k].dist, ekj = e[k][j].dist;
          if (eik >= 0 && ekj >= 0) updateDist(i, j, eik + ekj);
        }
  }
};

Graph g;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/gcampus.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/gcampus.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  cin >> T;
  for (int i = 0; i < T; i++) {
    cout << "Case #" << (i + 1) << ":" << endl;
    cin >> N >> M;
    g.init(N);
    for (int j = 0; j < M; j++) {
      int u, v, c;
      cin >> u >> v >> c;
      g.addEdge(u, v, c);
    }
    g.floydWarshall();
    for (int j = 0; j < M; j++) {
      auto k = g.edges[j];
      Edge ej = g.e[k.first][k.second];
      if (ej.dist < ej.cost) cout << j << endl;
    }
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

