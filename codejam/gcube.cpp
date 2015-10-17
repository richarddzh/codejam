//
//  gcube.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/4284486/dashboard#s=p1
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define NOT_USE_STDIO
#define MAXN 1001

using namespace std;
double dim[MAXN];

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/gcube.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/gcube.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int T, N, M;
  cin >> T;
  cout << setprecision(7);
  for (int i = 0; i < T; i++) {
    cout << "Case #" << (i + 1) << ":" << endl;
    cin >> N >> M;
    for (int j = 0; j < N; j++) cin >> dim[j];
    for (int j = 0; j < M; j++) {
      int l, r;
      double s = 0;
      cin >> l >> r;
      for (int k = l; k <= r; k++) {
        s += log(dim[k]);
      }
      s /= (r - l + 1);
      cout << exp(s) << endl;
    }
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

