/**
 *      file    :  3_connectedComp.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Nov 18 00:34:11
 *      lastMod :  Wed Nov 18 00:34:11 2020
**/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

  int n = 9;
  vector<int>visited(n, 0);
  queue<int>q;

  vector<vector<int> >gh = {{0,1,0,0,0,0,0,0,0},{1,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,1,0,0,0,1,0,0},{0,1,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0}};


  for (int k = 0; k < n; ++k) {
    if (visited[k] == 1)
      continue;

    visited[k] = 1;
    cout << " Visisted Node: " << k << endl; 
    q.push(k);
    while(!q.empty()) {
      auto i = q.front(); q.pop();
      int size = gh[i].size();
      
      for (int j=0; j< size; ++j) {
        if (gh[i][j] == 1 &&  !visited[j]) {
          cout << " Visisted Node: " << j << endl; 
          visited[j]=1;
          q.push(j);
        }
      }
    }
  }

  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
