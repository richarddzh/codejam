//
//  gmatrix.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/4284487/dashboard#s=p3
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//#define NOT_USE_STDIO
#define MAXN 3000

using namespace std;

typedef long long int64;

int64 m[MAXN][MAXN], g[MAXN], h[MAXN], p[MAXN][MAXN];
int64 A[MAXN], B[MAXN];
int T, N, K;
int64 C, X;

void DoRow(int s1, int s2)
{
  for (int i = 0; i < s1; i++) {
    for (int j = 0; j < s2; j++) {
      if (j % K == 0) g[j] = m[i][j];
      else g[j] = max(g[j-1], m[i][j]);
      // cerr << g[j] << " ";
    }
    // cerr << endl;
    for (int j = s2 - 1; j >= 0; j--) {
      if (j == s2 - 1 || (j + 1) % K == 0) h[j] = m[i][j];
      else h[j] = max(h[j+1], m[i][j]);
      // cerr << h[j] << " ";
    }
    // cerr << endl;
    for (int j = 0; j + K <= s2; j++) {
      if (j % K == 0) p[i][j] = h[j];
      else p[i][j] = max(h[j], g[j + K - 1]);
      // cerr << p[i][j] << " ";
    }
    // cerr << endl;
  }
}

int64 DoMatrix()
{
  DoRow(N, N);
  int s1 = N, s2 = N - K + 1;
  for (int i = 0; i < s1; i++) for (int j = 0; j < s2; j++) m[j][i] = p[i][j];
  DoRow(s2, s1);
  s1 = N - K + 1;
  s2 = N - K + 1;
  int64 s = 0;
  for (int i = 0; i < s1; i++) for (int j = 0; j < s2; j++) s += p[i][j];
  return s;
}

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/gmatrix.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/gmatrix.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N >> K >> C >> X;
    for (int j = 0; j < N; j++) cin >> A[j];
    for (int j = 0; j < N; j++) cin >> B[j];
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        m[j][k] = (A[j]*(j+1)+B[k]*(k+1)+C)%X;
        // cerr << m[j][k] << " ";
      }
      // cerr << endl;
    }
    int64 s = DoMatrix();
    cout << "Case #" << (i + 1) << ": " << s << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

