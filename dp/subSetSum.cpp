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
      this->dp.resize(n+1, vector<bool>(w+1, false));
    }

    bool subsetSum(vector<int>&weights, int ts) {
      if ( ts

    }

    bool subsetSum(vector<int>&weights, int& items) {
      sumSetSum1(weights, items, this->sum);
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

  cout << "Subset with sum exists: " << boolalpha << ks->subsetSum(weights, items) << endl;

  return 0;
}    

