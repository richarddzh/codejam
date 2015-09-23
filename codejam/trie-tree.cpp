//
//  trie-tree.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1014
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO

using namespace std;

struct TreeNode {
  vector<TreeNode *> children;
  char c;
  int L;
  TreeNode(char _c):c(_c),L(0){}
};

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/trie-tree.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/trie-tree.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  TreeNode root(0), *p, *next;
  int N;
  string s;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    p = &root;
    for (int j = 0; j < s.length(); j++) {
      next = NULL;
      for (int k = 0; k < p->children.size(); k++) {
        if (p->children[k]->c == s[j]) {
          next = p->children[k];
          break;
        }
      }
      if (next == NULL) {
        next = new TreeNode(s[j]);
        p->children.push_back(next);
      }
      p = next;
      p->L++;
    }
  }
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    p = &root;
    for (int j = 0; j < s.length(); j++) {
      next = NULL;
      for (int k = 0; k < p->children.size(); k++) {
        if (p->children[k]->c == s[j]) {
          next = p->children[k];
          break;
        }
      }
      p = next;
      if (next == NULL) break;
    }
    if (p == NULL) {
      cout << 0 << endl;
    } else {
      cout << p->L << endl;
    }
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

