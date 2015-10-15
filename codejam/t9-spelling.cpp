//
//  t9-spelling.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/351101/dashboard#s=p2
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXL 1001

using namespace std;
char str[MAXL];
const char * code[] = {
  "2","22","222","3","33","333","4","44","444","5","55","555","6","66","666",
  "7","77","777","7777","8","88","888","9","99","999","9999","0"
};

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/t9-spelling.in");
  ofstream output("/Users/richard/Programming/codejam/data/t9-spelling.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N;
  cin >> N;
  cin.getline(str, MAXL);
  for (int i = 0; i < N; i++) {
    cin.getline(str, MAXL);
    cout << "Case #" << (i + 1) << ": ";
    char last = 0;
    for (int j = 0; str[j]; j++) {
      int p = str[j] - 'a';
      if (p < 0 || p > 26) p = 26;
      if (code[p][0] == last) cout << " ";
      cout << code[p];
      last = code[p][0];
    }
    cout << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

