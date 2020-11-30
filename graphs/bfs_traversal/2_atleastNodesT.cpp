/**
 *      file    :  2_atleastNodesT.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Nov 17 23:40:41
 *      lastMod :  Tue Nov 17 23:40:41 2020
**/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

  int n = 9;
  vector<int>visited(n, 0);
  queue<pair<int,int>>q;
  int s = 0, e = 0;
  cin >> s >> e; 

  vector<vector<int> >gh = {{0,1,0,0,0,0,0,0,0},{1,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,1,0},{0,1,1,0,0,0,1,0,0},{0,1,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,1},{0,0,1,0,0,0,0,0,1},{0,0,0,0,0,0,1,1,0}};

  q.push(make_pair(0,s));
  visited[s] = 1;
  while(!q.empty()) {
    auto i = q.front(); q.pop();
    int size = gh[i.second].size();

    if (i.second == e) {
      cout << " Layers passed " << i.first << endl;
      break;
    }
    
    for (int j=0; j< size; ++j) {
      if (gh[i.second][j] == 1 &&  !visited[j]) {
        cout << " Visisted Node: " << j << endl; 
        visited[j]=1;
        q.push(make_pair(i.first+1, j));
      }
    }
  }

  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
