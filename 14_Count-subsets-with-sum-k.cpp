

/*
// using recursion


int findAns(int ind, vector<int>& arr, int k, int sum) {
	if(ind < 0) {
		if(sum == k) return 1;
		return 0;
	}

	// takei it;
	int take = 0;
	if(sum+arr[ind] <= k) take = findAns(ind-1, arr, k, sum+arr[ind]);
	int notTake = findAns(ind-1, arr, k, sum);
	return take+notTake;
}


int findWays(vector<int>& arr, int k)
{
	// using recursion
	int n = arr.size();
	return findAns(n-1, arr, k, 0);
}


*/


/*
    // using memoization


int findAns(int ind, vector<int>& arr, int k, long long int sum, vector<vector<long long int>> &dp) {
	if(ind < 0) {
		if(sum == k) return 1;
		return 0;
	}

	if(dp[ind][sum] != -1) return dp[ind][sum];

	// takei it;
	int take = 0;
	if(sum+arr[ind] <= k) take = findAns(ind-1, arr, k, sum+arr[ind], dp);
	int notTake = findAns(ind-1, arr, k, sum, dp);
	return dp[ind][sum] = (take+notTake) % 1000000007;
}


int findWays(vector<int>& arr, int k)
{
	// using memoization
	long long int sum = 0;
	int n = arr.size();
	for(int i = 0; i < n; i++) sum += arr[i];
	vector<vector<long long int>> dp(n, vector<long long int>(sum+1, -1));
	return findAns(n-1, arr, k, 0, dp);
}



*/


/*
    // using tabulation
#define mod 1000000007

int findWays(vector<int>& arr, int k)
{
	// using tabulation
	long long int sum = 0;
	int n = arr.size();
	vector<vector<long long int>> dp(n, vector<long long int>(k+1, 0));
	
	for(int i = 0; i < n; i++) dp[i][0] = 1;
	if(arr[0] <= k) dp[0][arr[0]] += 1;

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= k; j++) {
			int notTake = dp[i-1][j];
			int take = 0;
			if(arr[i] <= j) take = dp[i-1][j-arr[i]];
			dp[i][j] = (notTake + take)%1000000007;
		}
	}

	return dp[n-1][k];
}


*/


/*
    // using space optimization

#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int>& num, int k) {
	// using space optimization
    int n = num.size();
    vector<int> prev(k+1, 0);
    prev[0] = 1;

    if (num[0] <= k) prev[num[0]] += 1;

    for (int ind = 1; ind < n; ind++) {
        vector<int> curr(k+1, 0);
        curr[0] = 1;

        for (int j = 0; j <= k; j++) {	// as we are couting number the subseq sum equal to k. so, we have to start from 0th index to k.
            int notTake = prev[j];

            int take = 0;
            if (num[ind] <= j) take = prev[j-num[ind]];

            curr[j] = (notTake+take) % 1000000007;
        }

        prev = curr;
    }

    return prev[k];
}



*/