//
//  trie-graph.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1036
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>

#define NOT_USE_STDIO
#define NCHAR 26

using namespace std;

string s;

struct TrieNode {
  int accept, link;
  TrieNode * suffix;
  TrieNode * parent;
  TrieNode * next[NCHAR];
  TrieNode(int _a, int _k, TrieNode * _p):accept(_a),link(_k),parent(_p) {
    suffix = NULL;
    for (int i = 0; i < NCHAR; i++) next[i] = NULL;
  }
};

struct TrieGraph {
  TrieNode * root;
  TrieGraph() {
    root = new TrieNode(0, 0, NULL);
  }
  void AddWord(const string &w) {
    TrieNode * p = root;
    for (int i = 0; i < w.length(); i++) {
      int c = w[i] - 'a';
      if (p->next[c] == NULL) {
        p->next[c] = new TrieNode(0, c, p);
      }
      p = p->next[c];
    }
    p->accept = 1;
  }
  void BuildGraph() {
    deque<TrieNode *> q;
    q.push_back(root);
    while (q.empty() == false) {
      TrieNode * p = q.front();
      q.pop_front();
      if (p->parent == NULL || p->parent == root) {
        p->suffix = root;
      } else {
        p->suffix = p->parent->suffix->next[p->link];
      }
      if (p->suffix->accept) p->accept = 1;
      for (int i = 0; i < NCHAR; i++) {
        if (p->next[i] == NULL) {
          if (p == root) p->next[i] = root;
          else p->next[i] = p->suffix->next[i];
        } else {
          q.push_back(p->next[i]);
        }
      }
    }
  }
  bool Test(const string &s) {
    TrieNode * p = root;
    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'a';
      if (p->next[c] == NULL) return false;
      p = p->next[c];
      if (p->accept) return true;
    }
    return false;
  }
};

TrieGraph g;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/trie-graph.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/trie-graph.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;
    g.AddWord(word);
  }
  g.BuildGraph();
  cin >> s;
  cout << (g.Test(s) ? "YES" : "NO") << endl;
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

