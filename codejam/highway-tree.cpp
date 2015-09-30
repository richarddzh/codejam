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
#include <algorithm>

#define NOT_USE_STDIO
#define MAXN 100009

using namespace std;

struct Data {
  int repeat;
  int dist;
};

struct Node {
  map<int, Data *> e;
  int idx;
  int parent;
  int nchild;
};

Node * t[MAXN];

void GetChild(Node *r)
{
  int n = 0;
  for (auto i = r->e.begin(); i != r->e.end(); i++) {
    if (i->first == r->parent) continue;
    t[i->first]->parent = r->idx;
    GetChild(t[i->first]);
    n += t[i->first]->nchild + 1;
  }
  r->nchild = n;
  if (r->parent != -1) {
    r->e[r->parent]->repeat = n + 1;
    t[r->parent]->e[r->idx]->repeat = n + 1;
  }
}

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/highway-tree.in");
  ofstream output("/Users/richard/Programming/codejam/data/highway-tree.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N, M, sum = 0;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) t[i] = NULL;
  for (int i = 1; i < N; i++) {
    int u, v, k;
    cin >> u >> v >> k;
    if (u > v) { int h = u; u = v; v = h; }
    if (t[u] == NULL) t[u] = new Node();
    if (t[v] == NULL) t[v] = new Node();
    t[u]->e[v] = new Data();
    t[v]->e[u] = new Data();
    t[u]->idx = u;
    t[v]->idx = v;
    t[u]->e[v]->dist = k;
    t[v]->e[u]->dist = k;
  }
  t[1]->parent = -1;
  GetChild(t[1]);
  for (int i = 1; i <= N; i++) {
    for (auto j = t[i]->e.begin(); j != t[i]->e.end(); j++) {
      if (j->first > i) sum += j->second->repeat * (N - j->second->repeat) * j->second->dist;
    }
  }
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    if (s.compare("QUERY") == 0) {
      cout << sum << endl;
    } else {
      int u, v, k;
      cin >> u >> v >> k;
      int old = t[u]->e[v]->dist;
      t[u]->e[v]->dist = k;
      t[v]->e[u]->dist = k;
      sum += (k - old) * t[u]->e[v]->repeat * (N - t[u]->e[v]->repeat);
    }
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

