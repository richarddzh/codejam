//
//  circle-point.cpp
//  codejam
//  Problem URL: http://hihocoder.com/contest/mstest2015sept2/problem/1 
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

//#define NOT_USE_STDIO

using namespace std;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/demo.in");
  ofstream output("/Users/richard/Programming/codejam/data/demo.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  double x, y, r, t, m = 0;
  int mx = 0, my = 0, px[4], py[4];
  cin >> x >> y >> r;
  double step = 1/r;
  for (double a = 0; a < M_PI * 2; a += step) {
    double ix = x + r * sin(a);
    double iy = y + r * cos(a);
    px[0] = px[1] = ceil(ix);
    px[2] = px[3] = floor(ix);
    py[0] = py[2] = ceil(iy);
    py[1] = py[3] = floor(iy);
    for (int i = 0; i < 4; i++) {
      t = (px[i]-x)*(px[i]-x) + (py[i]-y)*(py[i]-y);
      if (t <= r*r) {
        if (t > m) {
          m = t; mx = px[i]; my = py[i];
        } else if (t == m) {
          if (px[i] > mx) {
            mx = px[i]; my = py[i];
          } else if (px[i] == mx && py[i] > my) {
            mx = px[i]; my = py[i];
          }
        }
      }
    }
  }
  cout << mx << " " << my << endl;
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

