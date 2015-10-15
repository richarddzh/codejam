//
//  reverse-words.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/351101/dashboard#s=p1
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXL 1002

using namespace std;

char str[MAXL];
deque<string> q;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/reverse-words.in");
  ofstream output("/Users/richard/Programming/codejam/data/reverse-words.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N;
  cin >> N;
  cin.getline(str, MAXL);
  for (int i = 0; i < N; i++) {
    q.clear();
    cin.getline(str, MAXL);
    istringstream ss(str);
    string s;
    while (ss >> s) q.push_back(s);
    cout << "Case #" << (i + 1) << ":";
    while (!q.empty()) {
      cout << " " << q.back();
      q.pop_back();
    }
    cout << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

