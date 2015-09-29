//
//  char-remove.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1039
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

#define NOT_USE_STDIO

using namespace std;

struct Node {
  char c;
  int n;
  Node(char _c, int _n):c(_c),n(_n){}
};

unsigned long FinalLength(list<Node> &l)
{
  unsigned long len = l.size();
  for (;;) {
    for (auto i = l.begin(); i != l.end(); ) {
      auto i1 = i;
      i1++;
      while (i1 != l.end() && i1->c == i->c) {
        i->n += i1->n;
        i1 = l.erase(i1);
      }
      i = i1;
    }
    for (auto i = l.begin(); i != l.end(); ) {
      if (i->n > 1) i = l.erase(i);
      else i++;
    }
    if (l.size() >= len) break;
    len = l.size();
  }
  return len;
}

unsigned long StringRemoval(const string &s)
{
  unsigned long m = 0;
  for (int p = 0; p <= s.length(); p++) for (char c = 'A'; c <= 'C'; c++) {
    list<Node> l;
    for (int i = 0; i < s.length(); i++) {
      if (i == p) l.push_back(Node(c, 1));
      l.push_back(Node(s[i], 1));
    }
    if (p == s.length()) l.push_back(Node(c, 1));
    unsigned long fl = FinalLength(l);
    if (fl < s.size() + 1 && s.size() + 1 - fl > m) m = s.size() + 1 - fl;
  }
  return m;
}


int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/char-remove.in");
  ofstream output("/Users/richard/Programming/codejam/data/char-remove.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    cout << StringRemoval(s) << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

