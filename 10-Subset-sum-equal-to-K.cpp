/*
    // using recursion
#include <bits/stdc++.h> 

bool findAns(int n, int k, vector<int>& arr) {
    if(k == 0) return true;
    if(n < 0 || k < 0) return false;

    int take = findAns(n-1, k-arr[n], arr);
    int notTake = findAns(n-1, k, arr);

    return take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // using recursion
    return findAns(n-1, k, arr);
}

// T.C: O(2^N)
// S.c: O(N)
*/


/*
    // using memoization
#include <bits/stdc++.h> 

bool findAns(int n, int k, vector<int>& arr, vector<vector<int>>& dp) {
    if(k == 0) return true;
    if(n < 0) return false;

    if(dp[n][k] != -1) return dp[n][k];
    
    int take = false;
    if(arr[n] <= k) take = findAns(n-1, k-arr[n], arr, dp);
    int notTake = findAns(n-1, k, arr, dp);

    return dp[n][k] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // using memoization
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return findAns(n-1, k, arr, dp);
}

// T.C: O(N*K)      where K is a target.
// S.C: O(N*K) + O(N) {aux array + stack space} where K is a target.
*/


/*
    // using tabulation: will solve later...


*/


/*
    // space optimization


*/