/**
 *      file    :  graph_al.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Nov 08 23:41:25
 *      lastMod :  Sun Nov  8 23:41:25 2020
 **/

//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

  int n = 7;
  vector<int>visited(n, 0);
  queue<int>q;

  vector<vector<int> >gh = {{0,1,0,0,0,0,0},{1,0,0,1,1,0,0},{0,0,0,1,0,0,0},{0,1,1,0,0,0,1},{0,1,0,0,0,1,0},{0,0,0,0,1,0,0},{0,0,0,1,0,0,0}};

  q.push(0);
  visited[0] = 1;
  cout <<"Visited " << 0 << endl;

  while (!q.empty()) {
    auto v = gh[q.front()];
    q.pop();

    for ( int i = 0; i < v.size(); ++i) {
      if (v[i] == 1 && !visited[i]) {
        cout <<"Visited " << i << endl;
        visited[i] = 1;
        q.push(i);
      }
    }
  }

  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}    

