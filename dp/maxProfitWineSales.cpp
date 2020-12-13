/**
 *      file    :  maxProfitWineSales.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 13 19:05:00
 *      lastMod :  Sun Dec 13 19:05:00 2020
 **/

#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

/* 
 *                                      PROBLEM STATEMENT
 *
 *    Imagine you have a collection of N wines placed next to each other on a shelf. For simplicity, let's number the wines from left to right as they are standing on the shelf with integers from 1 to N, respectively. The price of the i-th wine is pi (prices of different wines can be different).

Because the wines get better every year, supposing today is the year 1, on year y the price of the i-th wine will be y*pi, i.e. y-times the value that current year.

You want to sell all the wines you have, but you want to sell exactly one wine per year, starting on this year. One more constraint - on each year you are allowed to sell only either the leftmost or the rightmost wine on the shelf and you are not allowed to reorder the wines on the shelf (i.e. they must stay in the same order as they are in the beginning).

You want to find out, what is the maximum profit you can get, if you sell the wines in optimal order.

So for example, if the prices of the wines are (in the order as they are placed on the shelf, from left to right): p1=1, p2=4, p3=2, p4=3
The optimal solution would be to sell the wines in the order p1, p4, p3, p2 for a total profit 1*1 + 3*2 + 2*3 + 4*4 = 29 

Wrong solution

After playing with the problem for a while, you'll probably get the feeling, that in the optimal solution you want to sell the expensive wines as late as possible. You can probably come up with the following greedy strategy:

Every year, sell the cheaper of the two (leftmost and rightmost) available wines.

Although the strategy doesn't mention what to do when the two wines cost the same, this strategy kinda feels right. But unfortunately, it isn't, as the following example demonstrates. If the prices of the wines are: p1=2, p2=3, p3=5, p4=1, p5=4

The greedy strategy would sell them in the order p1, p2, p5, p4, p3 for a total profit 2*1 + 3*2 + 4*3 + 1*4 + 5*5 = 49

But we can do better if we sell the wines in the order p1, p5, p4, p2, p3 for a total profit 2*1 + 4*2 + 1*3 + 3*4 + 5*5 = 50

This counter-example should convince you, that the problem is not so easy as it can look on a first sight and I will tell you, that it can be solved using DP.

Write a backtrack

When coming up with the memoization solution for a problem, I always start with a backtrack solution that finds the correct answer. Backtrack solution enumerates all the valid answers for the problem and chooses the best one. For most of the problems it is easy to come up with such solution.

Here are some restrictions I put on a backtrack solution:

----> It should be a function, calculating the answer using recursion
----> It should return the answer with return statement, i.e. not store it somewhere
----> All the non-local variables that the function uses should be used as read-only, i.e. the function can modify only local variables and its arguments.

Summary

To sum it up, if you identify that a problem can be solved using DP, try to create a backtrack function that calculates the correct answer. Try to avoid the redundant arguments, minimize the range of possible values of function arguments and also try to optimize the time complexity of one function call (remember, you can treat recursive calls as they would run in O(1) time). Finally cache the values and don't calculate the same things twice.

 */

class Wines {
  public:
    vector<int>win;
    vector<vector<int>>dp;
    int totalWines;

    Wines(int n) {
      win.resize(n);
      totalWines = n;
      dp.resize(n, vector<int>(n, -1));
    }

  int maximumProfit1(int year, int be, int en) {

    if (be > en) return 0;
    return max(maximumProfit1(year+1, be+1, en)+year*win[be], maximumProfit1(year+1, be, en-1)+year*win[en]);
  }

  int maximumProfit2(int be, int en) {

    // en-be+1 is the unsold wines
    if (be > en) return 0;
    int year = totalWines - (en-be+1)+1; 
    return max(maximumProfit2(be+1, en)+year*win[be], maximumProfit2(be, en-1)+year*win[en]);
  }

  int maximumProfit3(int be, int en) {

    // en-be+1 is the unsold wines
    if (be > en) return 0;
    if (dp[be][en] != -1) return dp[be][en];
    int year = totalWines - (en-be+1)+1; 
    dp[be][en] = max(maximumProfit3(be+1, en)+year*win[be], maximumProfit3(be, en-1)+year*win[en]);
    return dp[be][en];
  }
};

int main() {
  int n = 0;
  cout << "Enter Total wines " << endl;
  cin >> n;
  Wines* obj = new Wines(n);

  for (int i = 0; i < n; ++i) {
    cin >> obj->win[i]; 
  } 

//  time_t start, end;
 // time(&start);
  auto start = high_resolution_clock::now();
  cout << obj->maximumProfit1(1, 0, n-1)<< endl;
  auto stop = high_resolution_clock::now();
  //time(&end);
  //cout << "Time taken by maximumProfit1 is " << double(end-start) << setprecision(5) << endl; 
  cout << "Time taken by maximumProfit1 is " << duration_cast<microseconds>(stop-start).count() << " Microseconds" << endl; 

  start = high_resolution_clock::now();
  cout << obj->maximumProfit2(0, n-1)<< endl;
  stop = high_resolution_clock::now();
  cout << "Time taken by maximumProfit2 is " << duration_cast<microseconds>(stop-start).count() << " Microseconds "<< endl; 

  start = high_resolution_clock::now();
  cout << obj->maximumProfit3(0, n-1)<< endl;
  stop = high_resolution_clock::now();
  cout << "Time taken by maximumProfit3 is " << duration_cast<microseconds>(stop-start).count() << " Microseconds" << endl; 

  return 0;
}
