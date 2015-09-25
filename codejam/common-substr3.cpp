//
//  common-substr3.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1059
//
//  Created by ZhengDong on 15/9/24.
//  Copyright (c) 2015Äê ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

#define NOT_USE_STDIO
#define MAX_LEN 2500

using namespace std;

char s1[MAX_LEN], s2[MAX_LEN]; // two string
int dp[MAX_LEN][MAX_LEN]; // length of max common substr of s1[0..i],s2[0..j]
int m[MAX_LEN][MAX_LEN]; // max{dp[i-k][j-k]+k, for k=3..f[i,j]}
int f[MAX_LEN][MAX_LEN]; // length of max common suffix of s1[0..i],s2[0..j]

int SolveProblem()
{
  int i, j, l1, l2;
  for (i = 0; s1[i]; i++) for (j = 0; s2[j]; j++) {
    if (s1[i] != s2[j]) {
      f[i][j] = 0;
    } else {
      if (i < 1 || j < 1) f[i][j] = 1; else f[i][j] = f[i-1][j-1]+1;
    }
    if (f[i][j] >= 3) {
      m[i][j] = max(m[i-1][j-1]+1, ((i>=3&&j>=3)?(dp[i-3][j-3]+3):(3)));
    } else {
      m[i][j] = 0;
    }
    if (i < 1 || j < 1) {
      dp[i][j] = 0;
    } else {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if (f[i][j] >= 3) dp[i][j] = max(dp[i][j], m[i][j]);
    }
  }
  return dp[i-1][j-1];
}

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("common-substr3.in");
  ofstream output("common-substr3.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  cin >> s1;
  cin >> s2;
  cout << SolveProblem() << endl;
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

