/**
 *      file    :  322_CoinChange.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 12 19:03:02
 *      lastMod :  Sat Dec 12 19:03:02 2020
 **/

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
