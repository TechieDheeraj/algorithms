/**
 *      file    :  subSetSum.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 19 23:11:59
 *      lastMod :  Sat Dec 19 23:11:59 2020
 **/

#include <bits/stdc++.h>
using namespace std;

class SubsetSum {
  public:
    vector<vector<bool>>dp;
    int sum;

    SubsetSum(int n, int totals) {
      sum = totals;
      this->dp.resize(n+1, vector<bool>(totals+1, false));
    }

    // recursion
    bool subsetSum1(vector<int>&weights, int n, int ts) {
      if (ts == 0) return true; //first column
      if (n == 0) return false;

      if (weights[n-1] <= ts)
        return subsetSum1(weights, n-1, ts-weights[n-1]) || subsetSum1(weights, n-1, ts);
      else
        return subsetSum1(weights, n-1, ts);
    }

    // recursion + memorization
    bool subsetSum2(vector<int>&weights, int n, int ts) {
      if (ts == 0) return true; // first column
      if (n == 0) return false; // first row except first cell

      if (dp[n][ts]) return dp[n][ts]; 

      if (weights[n-1] <= ts)
        return dp[n][ts] = subsetSum2(weights, n-1, ts-weights[n-1]) || subsetSum2(weights, n-1, ts);
      else
        return dp[n][ts] = subsetSum2(weights, n-1, ts);
    }
    // iterative method
    bool subsetSum3(vector<int>&weights, int n, int ts) {
      for (int i = 0; i < n+1; ++i) { // for size
        for (int j = 0; j < ts+1; ++j) { // for sum
          if (j == 0) {
            dp[i][j] = true;
            continue;
          }
          if (i == 0) {
            dp[i][j] = false;
            continue;
          }
          if (dp[i][j]) return dp[i][j];
          if (weights[i-1] <= j)
            dp[i][j] = dp[i-1][j-weights[i-1]] || dp[i-1][j];
          else
            dp[i][j] = dp[i-1][j];
        }
      }
      printDp(dp, n, ts+1);
      return dp[n][ts];
    }
    bool subsetSum(vector<int>&weights, int& items) {
     // return subsetSum1(weights, items, this->sum);
      //return subsetSum2(weights, items, this->sum);
      return subsetSum3(weights, items, this->sum);
    }

    void printDp(vector<vector<bool>>&d, int r, int size) {
      if (r < 0) return;
      printDp(d, r-1, size);
      cout << "| ";
      for (int i = 0; i < size; ++i)
        cout << (int)d[r][i] << " ";
      cout << "|\n";
    }
};
    
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int items = 0;
  int totalSum = 0;

  cout << "Enter the Total sum" << endl;
  cin >> totalSum;

  cout << "Enter number of values" << endl;
  cin >> items;

  SubsetSum* subs = new SubsetSum(items, totalSum);

  vector<int>weights(items);

  cout << "Enter Weight of Items" << endl;
  for (int i =0; i < items; ++i)
    cin >> weights[i];

  auto res = subs->subsetSum(weights, items); 

  cout << "Subset with sum exists: " << boolalpha << res << endl;

  return 0;
}    

