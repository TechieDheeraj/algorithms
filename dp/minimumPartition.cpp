/**
 *      file    :  minimumPartition.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 28 00:00:40
 *      lastMod :  Mon Dec 28 00:00:40 2020
 **/

class Solution {
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums
     */
    vector<vector<bool>>dp;
    vector<int>sums;
    int count = 1;

    void subsetSum(vector<int>& arr, int n , int ts) {

      for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < ts+1; ++j) {
          if ( j == 0) {
            dp[i][j] = true;
            continue;
          }
          if ( i == 0) {
            dp[i][j] = false;
            continue;
          }
          if (arr[i-1]<= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
          else
            dp[i][j] = dp[i-1][j];

          if(i == n) {
            if(dp[i][j] && count <= ts/2)
              sums.push_back(j);
            count++;
          }
        }
      }
    }

    int findMin(vector<int> &nums) {
      int sum = 0;
      int size = nums.size();
      //vector<int>sums;

      for (auto &i : nums)
        sum+=i;

      dp.resize(size+1, vector<bool>(sum+1));

      sums.push_back(0);
      subsetSum(nums, size, sum);

      /*
      for (int i = 0; i <= sum/2; ++i) {
        if (dp[size][i])
          sums.push_back(i);
      }
      */

      int result = INT_MAX;
      //for (int i = 0; i < sums.size(); ++i)
      for (int i = 0; i < sums.size(); ++i)
        result = min(result, sum-(2*sums[i]));
        // 0, 1, 2, 3, -, -, -, 7, 8, 9, 10  [1, 2, 7] == s2-s1 = min((sum-s1)-s1)

      return result;
      }

        // write your code here
};
