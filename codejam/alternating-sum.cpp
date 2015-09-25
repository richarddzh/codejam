//
//  alternating-sum.cpp
//  codejam
//  Problem URL: http://hihocoder.com/problemset/problem/1033
//
//  Created by ZhengDong on 15/9/24.
//  Copyright (c) 2015Äê ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

//#define NOT_USE_STDIO
#define NBIT 32
#define NSUM 400

using namespace std;

typedef unsigned long long uint64;

struct Item {
  uint64 n, s;
  bool ok;
  Item():ok(false),n(0),s(0){}
};
Item dp[NBIT][NSUM];
Item dp2[NBIT][NSUM];

int bit[NBIT];
int asum[NBIT];
uint64 pre[NBIT];
uint64 ten[NBIT];
const uint64 mod = 1000000007;

void SetInteger(uint64 x, int ksum)
{
  int i;
  for (i = 0; ; i++) {
    bit[i] = x % 10;
    pre[i] = (x - bit[i]) * ten[i];
    x /= 10;
    if (x == 0) {
      bit[i+1] = -1;
      break;
    }
  }
  int sign = 1;
  int csum = 0;
  while (i >= 0) {
    asum[i] = sign * (ksum - csum);
    csum += sign * bit[i];
    sign = (sign > 0) ? (-1) : (1);
    i--;
  }
}

Item ComputeItem(int nbit, int ksum) 
{
  if (ksum+100 < 0 || ksum+100 >= NSUM || nbit < 0 || nbit >= NBIT) return Item();
  Item &item = dp[nbit][ksum+100];
  if (item.ok) return item;
  if (nbit == 0) {
    if (ksum == 0) {item.n = 1; item.s = 0;}
    item.ok = true;
    return item;
  }
  if (nbit == 1) {
    if (ksum < 0 || ksum > 9) {
      item.ok = true;
      return item;
    }
    item.n = 1;
    item.s = ksum;
    item.ok = true;
    return item;
  }
  for (int i = 0; i < 10; i++) {
    Item i2 = ComputeItem(nbit - 1, i - ksum);
    item.n += i2.n;
    item.s = (((((ten[nbit-1] * i)%mod) * (i2.n%mod))%mod + i2.s)%mod + item.s)%mod;
  }
  item.ok = true;
  return item;
}

Item ComputeItem2(int nbit, int ksum)
{
  if (ksum+100 < 0 || ksum+100 >= NSUM || nbit < 0 || nbit >= NBIT) return Item();
  Item &item = dp2[nbit][ksum+100];
  if (item.ok) return item;
  if (nbit == 1) return ComputeItem(1, ksum);
  item = ComputeItem2(nbit - 1, ksum);
  for (int i = 1; i < 10; i++) {
    Item i2 = ComputeItem(nbit - 1, i - ksum);
    item.n += i2.n;
    item.s = (((((ten[nbit-1] * i)%mod) * (i2.n%mod))%mod + i2.s)%mod + item.s)%mod;
  }
  item.ok = true;
  return item;
}

uint64 SumLessThan(uint64 x, int ksum)
{
  SetInteger(x, ksum);
  uint64 sum = 0;
  for (int i = 0; bit[i] >= 0; i++) {
    for (int j = 0; j < bit[i]; j++) {
      if (bit[i+1] < 0 && j == 0) {
        // highest digit set to zero.
        Item i2 = ComputeItem2(i, ksum);
        sum = (sum + i2.s)%mod;
      } else {
        Item i2 = ComputeItem(i, j - asum[i]);
        sum = ((((pre[i] + j*ten[i])%mod * (i2.n%mod))%mod + i2.s)%mod + sum)%mod;
      }
    }
  }
  return sum;
}

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("alternating-sum.in");
  ofstream output("alternating-sum.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  ten[0] = 1;
  for (int i = 1; i < NBIT; i++) ten[i] = ten[i-1] * 10;
  uint64 a, b;
  int k;
  // for (;;) {
  cin >> a >> b >> k;
  a = SumLessThan(a, k);
  b = SumLessThan(b+1, k);
  cout << ((b + mod - a)%mod) << endl;
  // }
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

