/**
 *      file    :  518_coinChange2.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 14 18:39:30
 *      lastMod :  Thu Jan 14 18:39:30 2021
 **/

class Solution {
public:
    int dp[500][5001];
    int change(int amount, vector<int>& coins) {

      int n = coins.size();
      for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < amount+1; ++j) {
          if (j == 0) {
            dp[i][j] = 1; continue;
          }
          if (i == 0) {
            dp[i][j] = 0; continue;
          }

          if (coins[i-1]<=j)
            dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
          else
            dp[i][j] = dp[i-1][j];
        }
      }

      return dp[n][amount];
    }
};
