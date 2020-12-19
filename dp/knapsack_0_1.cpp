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
    //vector<int, vector<int>>dp;
    int weight;

    // TC: O(2^n), SC: O(1)
    int maxProfitKs1(vector<int>&values, vector<int>&weights, int n, int w) {
      if (n == 0 || w == 0) return 0;

      if (weights[n-1] <= w) {
        return max(values[n-1] + maxProfitKs1(values, weights, n-1, w-weights[n-1]), maxProfitKs1(values, weights, n-1, w));
      }
      else
       return maxProfitKs1(values, weights, n-1, w);
    }

    int maxProfit(vector<int>&values, vector<int>&weights, int& items) {
      return maxProfitKs1(values, weights, items, this->weight);
    }
};
    


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  Knapsack* ks = new Knapsack();
  int items = 0;

  cout << "Enter the weight of knapsack" << endl;
  cin >> ks->weight;

  cout << "Enter number of items" << endl;
  cin >> items;

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

