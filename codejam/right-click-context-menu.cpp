//
//  right-click-context-menu.cpp
//  codejam
//
//  Created by ZhengDong on 15/9/23.
//  Copyright (c) 2015年 ZhengDong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// #define NOT_USE_STDIO

using namespace std;

struct Section;

struct MenuItem {
  int length;
  vector<Section> sections;
  MenuItem():length(0){}
  int getLength();
};

vector<MenuItem> Items;

bool MenuItemOrder(int i, int j)
{
  return Items[i].getLength() >= Items[j].getLength();
}

struct Section {
  int length;
  vector<int> subItems;
  Section():length(0){}
  int getLength() {
    if (subItems.size() < 1) return 0;
    if (length > 0) return length;
    sort(subItems.begin(), subItems.end(), MenuItemOrder);
    for (int i = 0; i < subItems.size(); i++) {
      if (i + Items[subItems[i]].getLength() > length) length = i + Items[subItems[i]].getLength();
    }
    return length;
  }
};

bool SectionOrder(const Section &i, const Section &j)
{
  return i.length - i.subItems.size() >= j.length - j.subItems.size();
}

int MenuItem::getLength()
{
  if (sections.size() < 1) return 1;
  if (length > 0) return length;
  for (int i = 0; i < sections.size(); i++) sections[i].getLength();
  sort(sections.begin(), sections.end(), SectionOrder);
  int preLength = 0;
  for (int i = 0; i < sections.size(); i++) {
    if (preLength + sections[i].getLength() > length) length = preLength + sections[i].getLength();
    preLength += sections[i].subItems.size();
  }
  return length;
}

int main(int argc, const char * argv[]) {
#ifdef NOT_USE_STDIO
  ifstream input("/Users/zhengdong/Programming/codejam/data/right-click-context-menu.in");
  ofstream output("/Users/zhengdong/Programming/codejam/data/right-click-context-menu.out");
  streambuf *in = cin.rdbuf(input.rdbuf());
  streambuf *out = cout.rdbuf(output.rdbuf());
#endif
  int N, K, idx;
  cin >> N;
  for (int i = 0; i < N + 1; i++) {
    cin >> K;
    MenuItem item;
    Section section;
    for (int j = 0; j < K; ) {
      cin >> idx;
      if (idx > 0) {
        section.subItems.push_back(idx);
        j++;
      }
      if (idx == 0 || j == K) {
        item.sections.push_back(section);
        section = Section();
      }
    }
    Items.push_back(item);
  }
  cout << Items[0].getLength() << endl;
#ifdef NOT_USE_STDIO
  cin.rdbuf(in);
  cout.rdbuf(out);
#endif
  return 0;
}

