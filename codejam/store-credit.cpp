//
//  store-credit.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/351101/dashboard#s=p0
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXC 1001

using namespace std;

int N, C, I;
int idx[MAXC];

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/store-credit.in");
  ofstream output("/Users/richard/Programming/codejam/data/store-credit.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> C >> I;
    int r1 = -1, r2 = -1;
    for (int j = 0; j <= C; j++) idx[j] = -1;
    for (int j = 0; j < I; j++) {
      int p;
      cin >> p;
      if (C < p) continue;
      if (idx[C - p] >= 0 && r1 < 0) { r1 = idx[C - p]; r2 = j; }
      if (idx[p] < 0) idx[p] = j;
    }
    cout << "Case #" << (i + 1) << ": " << (r1 + 1) << " " << (r2 + 1) << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

