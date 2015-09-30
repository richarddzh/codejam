//
//  fibonacci.cpp
//  codejam
//  Problem URL: http://hihocoder.com/contest/mstest2015sept2/problem/3
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXF 27
#define MAXN 1000009

using namespace std;

typedef unsigned long long uint64;

int fibo[MAXF];
uint64 n[MAXF];
const uint64 mod = 1000000007;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/fibonacci.in");
  ofstream output("/Users/richard/Programming/codejam/data/fibonacci.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  fibo[0] = 1;
  fibo[1] = 1;
  for (int i = 2; i < MAXF; i++) fibo[i] = fibo[i-1]+fibo[i-2];
  for (int i = 0; i < MAXF; i++) n[i] = 0;
  int N, a, ai;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    ai = -1;
    for (int j = 0; j < MAXF; j++) if (fibo[j] == a) { ai = j; break; }
    if (ai == -1) continue;
    if (ai >= 2) {
      n[ai] = (n[ai - 1] + n[ai])%mod;
    } else if (ai < 2) {
      n[1] = (n[1] + n[0])%mod;
      n[0] = (n[0] + 1)%mod;
    }
  }
  for (int i = 1; i < MAXF; i++) {
    n[0] = (n[0] + n[i])%mod;
  }
  cout << n[0] << endl;
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

