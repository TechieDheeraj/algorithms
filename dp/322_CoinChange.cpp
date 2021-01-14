/**
 *      file    :  322_CoinChange.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 12 19:03:02
 *      lastMod :  Sat Dec 12 19:03:02 2020
 **/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int dp[13][10001];

      int n = coins.size();

      for (int i =0; i < n+1; ++i) {
        for (int j =0; j < amount+1; ++j) {
          if (i == 0) {
            dp[i][j] = INT_MAX-1;
            continue;
          }
          if (j == 0) {
            dp[i][j] = 0;
            continue;
          }
          if (i == 1) {
            dp[i][j] = j % coins[0] == 0 ? j/coins[0]: INT_MAX-1;
            continue;
          }
          if (coins[i-1]<=j)
            dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
          else
            dp[i][j] = dp[i-1][j];
        }
      }
      return dp[n][amount] < INT_MAX-1 ? dp[n][amount]: -1;
    }
};
/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int>dp(amount+1, amount+1);
      dp[0] = 0;
      // ith location will represent minimum coins needed to make it up to i amount
//      sort(coins.begin(), coins.end());
      for (int i = 1; i<= amount; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
          if (coins[j] <= i)
            dp[i] = min(dp[i], 1+dp[i-coins[j]]);
 //         else
  //          break; // can just break because coins are sorted
        }
      }
      return dp[amount] > amount ? -1: dp[amount];
    }
};
*/
