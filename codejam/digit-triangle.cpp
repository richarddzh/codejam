//
//  digit-triangle.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1037
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXN 101

using namespace std;

int t[MAXN][MAXN];

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/digit-triangle.in");
  ofstream output("/Users/richard/Programming/codejam/data/digit-triangle.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> t[i][j];
    }
  }
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      t[i][j] += max(t[i+1][j], t[i+1][j+1]);
    }
  }
  cout << t[0][0] << endl;
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

