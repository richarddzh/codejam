//
//  kmp.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1015
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO

using namespace std;

struct PatternChar {
  int next;
  char c;
  PatternChar(char _c, int n):c(_c),next(n){}
};

vector<PatternChar> Pattern;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/kmp.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/kmp.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N;
  string s;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    Pattern.clear();
    for (int j = 0; j < s.length(); j++) {
      int p = j;
      while (p > 0) {
        p = Pattern[p - 1].next;
        if (s[p] == s[j]) break;
      }
      if (s[p] == s[j] && j > 0) {
        Pattern.push_back(PatternChar(s[j], p + 1));
      } else {
        Pattern.push_back(PatternChar(s[j], 0));
      }
      cerr << Pattern.back().next << endl;
    }
    cin >> s;
    int p = 0, k = 0;
    for (int j = 0; j < s.length(); ) {
      if (Pattern[p].c != s[j] || p >= Pattern.size()) {
        if (p > 0) {
          p = Pattern[p - 1].next;
        } else {
          p = 0;
          j++;
        }
      } else {
        p++;
        j++;
        if (p >= Pattern.size()) k++;
      }
    }
    cout << k << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

