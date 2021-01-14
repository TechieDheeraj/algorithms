/**
 *      file    :  700_cuttingARod.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 14 18:05:21
 *      lastMod :  Thu Jan 14 18:05:21 2021
 **/

class Solution {
public:
    /**
     * @param prices: the prices
     * @param n: the length of rod
     * @return: the max value
     */
    vector<vector<int>>dp;
    int cutting(vector<int> &prices, int n) {
      // Write your code here
      vector<int>len;
      for (int i =1; i <= n; ++i) // n is equivalent to max weight in knapsack
        len.push_back(i);
      dp.resize(n+1, vector<int>(n+1));

      for (int i=0; i < prices.size()+1; ++i) { // size of array:weight
        for (int j = 0; j < n+1; ++j) {
          if (j == 0) {
            dp[i][j] = 0; continue;
          }
          if (i == 0) {
            dp[i][j] = 0; continue;
          }
          if (len[i-1] <= j)
            dp[i][j] = max(prices[i-1]+dp[i][j-len[i-1]], dp[i-1][j]);
          else
            dp[i][j] = dp[i-1][j];
        }
      }
      return dp[prices.size()][n];
    }
};
