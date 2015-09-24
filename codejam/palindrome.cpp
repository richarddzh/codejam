//
//  panlindrome.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1032
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
#define STRLEN 1000001
#define MAXLEN 2000009

using namespace std;

char s[MAXLEN], str[STRLEN];
int f[MAXLEN];

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("palindrome.in");
  ofstream output("palindrome.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N, i, j, m, n, len, id, mx, maxp;
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> str;
    for (j = 0; str[j]; j++) {
      s[j*2] = 0;
      s[j*2+1] = str[j];
    }
    s[j*2] = 0;
    len = j * 2 + 1;
    id = 0;
    mx = 0;
    maxp = 1;
    for (j = 0; j < len; j++) {
      if (j > mx) {
        f[j] = 0; m = j-1; n = j+1;
      } else {
        int f2 = f[id*2-j];
        if (f2 < mx-j) {
          f[j] = f2; m = -1;
        } else {
          f[j] = mx-j; n = mx+1; m = 2*j-n;
        }
      }
      while (m >= 0 && n < len && s[m] == s[n]) {
        m--; n++; f[j]++;
      }
      if (f[j]+j > mx) {
        mx = f[j]+j; id = j;
      }
      if (f[j] > maxp) {
        maxp = f[j];
      }
    }
    cout << maxp << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

