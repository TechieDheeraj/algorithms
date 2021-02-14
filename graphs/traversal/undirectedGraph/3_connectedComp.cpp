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

int componentNum = 0;

void CCBfs(int n, vector<vector<int>>& gh) {

  vector<int>visited(n, 0);
  queue<int>q;

  for (int k = 0; k < n; ++k) {
    if (visited[k] == 1)
      continue;

    visited[k] = 1;
    cout << " Visited Node: " << k << endl; 
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
}

void CCDfs(vector<vector<int>>&gh, vector<int>& id, int v, vector<int>& visitedDfs) {

  if (!visitedDfs[v]) {
    visitedDfs[v] = 1;
    id[v] = componentNum;

    for (int i = 0; i < gh[v].size(); ++i) {
      if (gh[v][i] && !visitedDfs[i]) {
        CCDfs(gh, id, i, visitedDfs);
      }
    }
  }
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 9;

  vector<vector<int> >gh = {{0,1,0,0,0,0,0,0,0},{1,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,1,0,0,0,1,0,0},{0,1,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0}};

  vector<int>visitedDfs(n);
  vector<int>id(n); // maintain connected component id number for each vertex

  CCBfs(n, gh);
  for (int i =0; i < n; ++i) {
    if (visitedDfs[i]) continue;
    CCDfs(gh, id, i, visitedDfs);
    componentNum++;
  }

  for (int i = 0; i < id.size(); ++i)
    cout << "Connected component for " << i << " is " << id[i] << endl; 

  return 0;
}
