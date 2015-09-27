//
//  highway.cpp
//  codejam
//  Problem URL: http://hihocoder.com/contest/hiho65/problem/1
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define NOT_USE_STDIO
#define MAXN 1001

using namespace std;

struct Car {
  int x, y, v;
  Car(int _x, int _y, int _v):x(_x),y(_y),v(_v){}
};

vector<Car> cars;
vector<int> cidx, yidx;
double t[MAXN][MAXN];

bool CarOrder(int i, int j)
{
  return cars[i].x > cars[j].x;
}

bool ExitOrder(int i, int j)
{
  return cars[i].y < cars[j].y;
}

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/richard/Programming/codejam/data/highway.in");
  ofstream output("/Users/richard/Programming/codejam/data/highway.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    cars.push_back(Car(x, y, v));
    cidx.push_back(i);
    yidx.push_back(i);
  }
  sort(cidx.begin(), cidx.end(), CarOrder);
  sort(yidx.begin(), yidx.end(), ExitOrder);
  for (int i = 0; i < N; i++) {
    int p = cidx[i];
    for (int j = 0; j < N; j++) {
      int q = yidx[j];
      if (cars[p].x >= cars[q].y || cars[p].y < cars[q].y) {
        t[p][q] = 0;
      } else {
        int x = cars[p].x;
        double t0 = 0;
        if (j > 0 && cars[yidx[j-1]].y > x) {
          x = cars[yidx[j-1]].y;
          t0 = t[p][yidx[j-1]];
        }
        t[p][q] = t0 + double(cars[q].y - x) / cars[p].v;
      }
      if (i > 0) {
        t[p][q] = max(t[p][q], t[cidx[i-1]][q]);
      }
    }
  }
  cout << fixed << setprecision(2);
  for (int i = 0; i < N; i++) {
    cout << t[i][i] << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

