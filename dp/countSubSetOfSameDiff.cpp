/**
 *      file    :  perfectSumProblem.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 27 21:46:00
 *      lastMod :  Sun Dec 27 21:46:00 2020
 **/
   
#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
		long long max = 1e9+7;
		
		vector<vector<int>>dp;
		
		int subset(int arr[], int n, int sum) {
				if ( sum == 0) return 1;
				if (n == 0) return 0;
				if (dp[n][sum] != -1) return dp[n][sum];
				if (arr[n-1] <= sum) 
						return dp[n][sum] = ((subset(arr, n-1, sum-arr[n-1]))%max + (subset(arr, n-1, sum)%max))%max;
				else
						return dp[n][sum] = subset(arr, n-1, sum) % max;
		}
		
		int countSubsets(int arr[], int n, int diff)
		{
				
        int totalSum = 0;
        for (int i = 0; i < n; ++i)
          totalSum+=arr[i];
				dp.resize(n+1, vector<int>(totalSum+1, -1));

        int sum = (totalSum+diff)/2; 

				auto res = subset(arr, n, sum);
				return res % max;
		} 
};

int main() 
{
   	int t;
    cout << "Enter No. of Test Cases " << endl;
    cin >> t;
    while (t--)
    {
        int n, diff;

        cout << "Enter sizeof Arr/difference " << endl;
        cin >> n >> diff;

        int a[n];
        cout << "Enter Array elements " << endl;
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	    Solution ob;
	    cout << "result is " << ob.countSubsets(a, n, diff) << "\n";
	     
    }
    return 0;
}
