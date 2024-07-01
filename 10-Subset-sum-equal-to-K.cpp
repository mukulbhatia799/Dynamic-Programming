// understood the tabulation dp matrix by sumit malik(pepcoding) sir.

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
    // using tabulation
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // using tabulation
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));    // don't need vector of int now, as in memo we have to check if dp[n][target] != -1 means it has changed to T/F or not.
                                                        // But in tabulation, we are filling the dp completely. So, take bool.
    for(int i = 0; i < n; i++) dp[i][0] = true;

    dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            int notTake = dp[i-1][j];
            int take = false;
            if(arr[i] <= j) take = dp[i-1][j-arr[i]];
            dp[i][j] = notTake | take;
        }
    }

    return dp[n-1][k];

 
}


*/


/*
    // space optimization
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // solved using space optimization
    vector<bool> prev(k + 1, false);

    prev[0] = true;

    if (arr[0] <= k) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        vector<bool> curr(k + 1, false);

        curr[0] = true;

        for (int j = 1; j <= k; j++) {
            bool notTake = prev[j];

            bool take = false;
            if (arr[i] <= j) take = prev[j - arr[i]];

            curr[j] = (notTake || take);
        }

        prev = curr;
    }

    return prev[k];
}

*/