/**
 *      file    :  knapsack_0_1.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 19 23:11:59
 *      lastMod :  Sat Dec 19 23:11:59 2020
 **/

#include <bits/stdc++.h>
using namespace std;

class Knapsack {
  public:
    vector<vector<int>>dp;
    int weight;

    Knapsack(int n, int w) {
      weight = w;
      this->dp.resize(n+1, vector<int>(w+1, -1));
    }

    // TC: O(2^n), SC: O(1) Recursion
    int maxProfitKs1(vector<int>&values, vector<int>&weights, int n, int w) {
      if (n == 0 || w == 0) return 0;

      if (weights[n-1] <= w) {
        return max(values[n-1] + maxProfitKs1(values, weights, n-1, w-weights[n-1]), maxProfitKs1(values, weights, n-1, w));
      }
      else
       return maxProfitKs1(values, weights, n-1, w);
    }

    // TC: O(n^2), SC: O(nXm) Recursion+Memorize
    int maxProfitKs2(vector<int>&values, vector<int>&weights, int n, int w) {
      if (n == 0 || w == 0) return 0;

      if (dp[n][w] != -1) return dp[n][w];

      if (weights[n-1] <= w) {
        return dp[n][w] = max(values[n-1] + maxProfitKs1(values, weights, n-1, w-weights[n-1]), maxProfitKs1(values, weights, n-1, w));
      }
      else
       return dp[n][w] = maxProfitKs1(values, weights, n-1, w);
    }

    // TC: O(n^2), SC: O(nXm) Iterative
    int maxProfitKs3(vector<int>&values, vector<int>&weights, int n, int w) {

      for(int i = 0; i < n+1; ++i) {
        for(int j = 0; j < w+1; ++j) {
          if (i == 0 || j == 0) {
            dp[i][j] = 0; // Intialize with answer of minimum valid input
            continue;
          }

          if (weights[i-1] <= j)
            dp[i][j] = max(values[i-1]+dp[i-1][j-weights[i-1]], dp[i-1][j]);
          else
            dp[i][j] = dp[i-1][j];
        }
      }
      return dp[n][w];
    }

    int maxProfit(vector<int>&values, vector<int>&weights, int& items) {
      //return maxProfitKs1(values, weights, items, this->weight);
     // return maxProfitKs2(values, weights, items, this->weight);
      return maxProfitKs3(values, weights, items, this->weight);
    }
};
    
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int items = 0;
  int maxW = 0;

  cout << "Enter the weight of knapsack" << endl;
  cin >> maxW;

  cout << "Enter number of items" << endl;
  cin >> items;

  Knapsack* ks = new Knapsack(items, maxW);
  vector<int>values(items);
  vector<int>weights(items);

  cout << "Enter Values of Items" << endl;
  for (int i =0; i < items; ++i)
    cin >> values[i];

  cout << "Enter Weight of Items" << endl;
  for (int i =0; i < items; ++i)
    cin >> weights[i];

  cout << "Max Profit with Knapsack is " << ks->maxProfit(values, weights, items) << endl;

  return 0;
}    

