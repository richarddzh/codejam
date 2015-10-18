//
//  granks.cpp
//  codejam
//  Problem URL: https://code.google.com/codejam/contest/4284487/dashboard#s=p0
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

//#define NOT_USE_STDIO

using namespace std;

typedef long long int64;
struct Player {
  string name;
  int64 score;
  Player(const string & n, int64 s):name(n),score(s){}
};
vector<int> score;
map<string, vector<int64> > players;
vector<Player> rank;

bool RankFunc(const Player & p1, const Player & p2) {
  if (p1.score > p2.score) return true;
  if (p1.score == p2.score && p1.name < p2.name) return true;
  return false;
}

bool SortScore(int64 s1, int64 s2) {
  return s1 > s2;
}

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/granks.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/granks.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int T, P, N, M;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cout << "Case #" << (i + 1) << ":" << endl;
    cin >> P;
    score.clear();
    for (int j = 0; j < P; j++) { int s; cin >> s; score.push_back(s); }
    cin >> N;
    players.clear();
    for (int j = 0; j < N; j++) {
      int64 w;
      cin >> w;
      for (int k = 0; k < P; k++) {
        string name;
        cin >> name;
        players[name].push_back(w * score[k]);
      }
    }
    cin >> M;
    rank.clear();
    for (auto p = players.begin(); p != players.end(); p++) {
      sort(p->second.begin(), p->second.end(), SortScore);
      int64 s = 0;
      for (int j = 0; j < M && j < p->second.size(); j++) {
        s += p->second[j];
      }
      rank.push_back(Player(p->first, s));
    }
    sort(rank.begin(), rank.end(), RankFunc);
    int lastrank = 1;
    for (int j = 0; j < rank.size(); j++) {
      if (j == 0 || rank[j].score != rank[j-1].score) {
        lastrank = j + 1;
      }
      cout << lastrank << ": " << rank[j].name << endl;
    }
  }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

