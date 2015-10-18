//
//  travel.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/10214486/dashboard
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NOT_USE_STDIO
#define MAXN 500
#define MAXS 24

using namespace std;

struct Graph {
  int n;
  int cost[MAXN][MAXN][MAXS];
  void init(int _n) {
    n = _n;
    for (int i = 0; i < MAXS; i++) for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) { cost[j][k][i] = -1; }
      cost[j][j][i] = 0;
    }
  }
  void update(int x, int y, int t, int c) {
    if (cost[x][y][t] < 0 || cost[x][y][t] > c) cost[x][y][t] = c;
  }
  void floydWarshall() {
    for (int i = 0; i < n; i++) {
      for (int t = 0; t < MAXS; t++) for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) {
        if (cost[x][i][t] < 0) continue;
        int t1 = (t + cost[x][i][t]) % MAXS;
        if (cost[i][y][t1] < 0) continue;
        update(x, y, t, cost[x][i][t] + cost[i][y][t1]);
      }
    }
  }
};

Graph g;

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/travel.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/travel.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int T, N, M, K, x, y, c, d, s;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N >> M >> K;
    g.init(N);
    for (int j = 0; j < M; j++) {
      cin >> x >> y;
      for (int t = 0; t < MAXS; t++) {
        cin >> c;
        g.update(x - 1, y - 1, t, c);
        g.update(y - 1, x - 1, t, c);
      }
    }
    g.floydWarshall();
    cout << "Case #" << (i + 1) << ":";
    for (int j = 0; j < K; j++) {
      cin >> d >> s;
      cout << " " << g.cost[0][d - 1][s];
    }
    cout << endl;
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

