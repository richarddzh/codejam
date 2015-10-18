//
//  gfiles.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/4284487/dashboard#s=p1
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//#define NOT_USE_STDIO

using namespace std;

typedef unsigned long long uint64;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/gfiles.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/gfiles.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int T, N;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    uint64 l = 0, r = 0;
    bool bl = false, br = false;
    for (int j = 0; j < N; j++) {
      uint64 p, k;
      cin >> p >> k;
      if (p == 0 || k == 0) continue;
      if (p == 100) { bl = true; br = true; l = k; r = k; }
      if (p > 0) {
        if (br == false || k * 100 / p < r) {
          r = k * 100 / p;
          br = true;
        }
      }
      if (bl == false || k * 100 / (p + 1) + 1 > l) {
        l = k * 100 / (p + 1) + 1;
        bl = true;
      }
    }
    cout << "Case #" << (i + 1) << ": ";
    if (bl && br && l == r) cout << l << endl;
    else cout << "-1" << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

