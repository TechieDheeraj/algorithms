/**
 *      file    :  494_targetSum.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 11 00:40:38
 *      lastMod :  Mon Jan 11 00:40:38 2021
 **/

class Solution {
public:
    //vector<vector<int>>dp;
    int dp[21][1001];
    int countSubsets(vector<int>&arr, int n, int sum) {
      /*
      if (sum == 0 && n == 0)
        return 1;
      if (n == 0)
        return 0;
      
      if (dp[n][sum] != -1) return dp[n][sum];
      
      if (arr[n-1]<= sum)
        return dp[n][sum] = countSubsets(arr, n-1, sum-arr[n-1]) + countSubsets(arr, n-1, sum);
      else
        return dp[n][sum] = countSubsets(arr, n-1, sum);
      */  
      
      for (int i=0; i < n+1; ++i) {
        for (int j=0; j < sum+1; ++j) {
          if (j == 0 && i == 0) {
            dp[i][j] = 1;
            continue;
          }
          if (i == 0) {
            dp[i][j] = 0;
            continue;
          }
          
          if (arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
          else
            dp[i][j] = dp[i-1][j];
        }
      }
      return dp[n][sum];  
/*      */
    }
  
    int findTargetSumWays(vector<int>& nums, int& S) {
      // This Problem is same as the count the subsets with difference to given S
      
      int sum = 0;
      int n = nums.size();
      
      sum = accumulate(nums.begin(), nums.end(), 0);
     // dp.resize(n+1, vector<int>(sum+1));
 //     dp.resize(n+1, vector<int>(sum+1, -1));
      
      if (sum < S || ((sum+S) % 2 != 0)) return 0;
      
      return countSubsets(nums, n, (sum+S)/2);
    }
};
