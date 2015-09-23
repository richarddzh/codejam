//
//  beautiful-string.cpp
//  codejam
//  Problem URL: http://hihocoder.com/contest/mstest2015oct/problem/1
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>

// #define NOT_USE_STDIO

using namespace std;

struct Pattern {
  char c;
  int n;
  Pattern():n(0){}
};

deque<Pattern> P;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/beautiful-string.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/beautiful-string.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N, K;
  char c, isBeautiful;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> K;
    isBeautiful = false;
    P.clear();
    for (int j = 0; j < K; j++){
      cin >> c;
      if (P.size() < 1 || P.back().c != c) {
        Pattern p;
        p.c = c;
        p.n = 1;
        P.push_back(p);
      } else {
        P.back().n++;
      }
      if (P.size() > 3) P.pop_front();
      if (P.size() == 3 && P[0].c + 1 == P[1].c && P[1].c == P[2].c - 1 && P[0].n >= P[1].n && P[2].n >= P[1].n) isBeautiful = true;
    }
    if (isBeautiful) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

