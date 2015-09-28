//
//  longest-tree-path.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1050
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXN 100001

using namespace std;

struct Node {
  vector<Node *> adj;
  Node * parent;
  int depth;
};

Node t[MAXN];

Node * TreeDepth(Node * root)
{
  Node * d = root;
  deque<Node *> s;
  root->depth = 0;
  root->parent = NULL;
  s.push_back(root);
  while (s.empty() == false) {
    Node * p = s.back();
    s.pop_back();
    for (int i = 0; i < p->adj.size(); i++) {
      if (p->adj[i] == p->parent) continue;
      p->adj[i]->parent = p;
      p->adj[i]->depth = p->depth + 1;
      s.push_back(p->adj[i]);
    }
    if (p->depth > d->depth) d = p;
  }
  return d;
}

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/longest-tree-path.in");
  ofstream output("/Users/richard/Programming/codejam/data/longest-tree-path.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    t[a].adj.push_back(t + b);
    t[b].adj.push_back(t + a);
  }
  Node * d = TreeDepth(t + 1);
  d = TreeDepth(d);
  cout << d->depth << endl;
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

