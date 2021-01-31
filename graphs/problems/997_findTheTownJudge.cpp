/**
 *      file    :  997_findTheTownJudge.cpp 
 *      author  :  techiedheeraj
 *      created :  2021 Jan 31 20:17:12 
 *      lastMod :  Sun Jan 31 20:17:12 2021 
 **/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {

      vector<pair<int, int>>nodes(N+1, make_pair(0, 0));

      for (auto &v: trust) {
        nodes[v[0]].second++;
        nodes[v[1]].first++;
      }

      int ret = -1;
      for (int i = 1; i < nodes.size(); ++i) {
        if (nodes[i].first == N-1 && nodes[i].second == 0)
          ret = i;
      }

      return ret;
      /*
      int dp[N+1][N+1];
      memset(dp, 0, sizeof(dp));

      for (auto&v : trust) {
        dp[v[0]][v[1]] = 1;
      }

      vector<pair<int, int>>nodes(N+1, make_pair(0, 0));
      for (int i = 1; i <= N; ++i) {
        for (int j=1; j <= N; ++j) {
          if (dp[i][j])
            nodes[i].second+=1;
          if (dp[j][i])
            nodes[i].first+=1;
        }
      }

      int ret = -1;
      for (int j = 1; j < nodes.size(); ++j) {
        if (nodes[j].second == 0 && nodes[j].first == N-1)
          ret = j;
      }
      return ret;
      */
    }
};
