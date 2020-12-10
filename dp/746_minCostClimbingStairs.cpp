/**
 *      file    :  746_minCostClimbingStairs.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 11 02:57:12
 *      lastMod :  Fri Dec 11 02:57:12 2020
 **/

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    vector<int>dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i =2; i<=n; ++i) {
      dp[i] = min(dp[i-1], dp[i-2]) + (i == n ? 0: cost[i]);
    }

    return dp[n];
  }
};
