//
//  ggames.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/4284487/dashboard#s=p2
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXELF 1024

using namespace std;

bool meet(int i, int j, int k) {
  int s = 1;
  for (int p = 0; p < k; p++) s *= 2;
  return (i/s) == (j/s);
}

struct Case {
  bool frd[MAXELF][MAXELF];
  int ki[MAXELF];
  int order[MAXELF];
  int n, n2;
  void init(int _n) {
    n = _n;
    n2 = 1;
    for (int i = 0; i < n; i++) n2 *= 2;
    for (int i = 0; i < n2; i++) {
      for (int j = 0; j < n2; j++) frd[i][j] = false;
      ki[i] = -1;
      order[i] = -1;
    }
  }
  bool find(int p) {
    if (p >= n2) return true;
    if (p < 0) return false;
    while (order[p] + 1 < n2) {
      order[p]++;
      bool isOk = true;
      for (int i = 0; i < p; i++) {
        if (order[i] == order[p]) { isOk = false; break; }
        int i1 = order[i];
        int i2 = order[p];
        if (frd[i1][i2] && meet(i, p, ki[i1])) { isOk = false; break; }
        if (frd[i2][i1] && meet(i, p, ki[i2])) { isOk = false; break; }
      }
      if (!isOk) continue;
      bool found = find(p + 1);
      if (found) return true;
    };
    order[p] = -1;
    return find(p - 1);
  }
} g;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/ggames.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/ggames.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int T, N, M, ei, ki, bi, fi;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N >> M;
    g.init(N);
    for (int j = 0; j < M; j++) {
      cin >> ei >> ki >> bi;
      ei -= 1;
      g.ki[ei] = ki;
      for (int k = 0; k < bi; k++) {
        cin >> fi;
        g.frd[ei][fi - 1] = true;
      }
    }
    bool ok = g.find(0);
    cout << "Case #" << (i + 1) << ": " << (ok ? "YES" : "NO") << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

