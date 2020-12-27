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
		
		int perfectSum(int arr[], int n, int sum)
		{
				
				//int dp[n+1][sum+1];
				dp.resize(n+1, vector<int>(sum+1, -1));
				auto res = subset(arr, n, sum);
				return res % max;
		} 
	/*
		int perfectSum(int arr[], int n, int sum) {

				int dp[n+1][sum+1];
				//dp.resize(n+1, vector<int>(sum+1));
				
				for (int i = 0; i < n+1; ++i) {
						for (int j = 0; j < sum+1; ++j) {
								if (j == 0) {
										dp[i][j] = 1;
										continue;
								}
								if (i == 0) {
										dp[i][j] = 0;
										continue;
								}
								
								if (arr[i-1] <= j)
										dp[i][j] = ((dp[i-1][j-arr[i-1]])%max + (dp[i-1][j])%max)%max;
								else
										dp[i][j] = dp[i-1][j] % max;
						}
				}
				return dp[n][sum]%max;
		}*/	  
};

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
