/**
 *      file    :  416_partitionEqualSum.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 27 18:19:39
 *      lastMod :  Sun Dec 27 18:19:39 2020
 **/

class Solution {
public:
//    vector<vector<bool>>dp;
    int dp[201][20001];
    bool subsetExists(vector<int>&arr, int n, int ts) {
      for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < ts+1; ++j) {
          if (j == 0) {
            dp[i][j] = true;
            continue;
          }
          if (i == 0) {
            dp[i][j] = false;
            continue;
          }
          
          if (arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
          else
            dp[i][j] = dp[i-1][j];
        }
      }
      return dp[n][ts];
    }
  /*
    bool subsetExists(vector<int>&arr, int n, int ts) {
      if (ts == 0) return true;
      if (n == 0) return false;
      
      if (dp[n][ts]) return dp[n][ts];
      
      if (arr[n-1] <= ts)
        return dp[n][ts] = subsetExists(arr, n-1, ts-arr[n-1]) || subsetExists(arr, n-1, ts);
      else
        return dp[n][ts] = subsetExists(arr, n-1, ts);
    }
    */
  
    bool canPartition(vector<int>& nums) {
      int sum = 0;
      for (auto &i: nums)
        sum+=i;
      if (sum & 1) return false;
//      memset(dp, false, sizeof(dp));
 //     dp.resize(nums.size()+1, vector<bool>((sum/2)+1, false));
      return subsetExists(nums, nums.size(), sum/2);
    }
};
