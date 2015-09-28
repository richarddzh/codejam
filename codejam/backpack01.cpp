//
//  backpack01.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1038
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXN 501
#define MAXM 100001

using namespace std;

int need[MAXN], value[MAXN];
int f[MAXM];

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/backpack01.in");
  ofstream output("/Users/richard/Programming/codejam/data/backpack01.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> need[i] >> value[i];
  }
  for (int i = 0; i <= M; i++) {
    f[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = M; j >= need[i]; j--) {
      f[j] = max(f[j], f[j - need[i]] + value[i]);
    }
  }
  cout << f[M] << endl;
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

