/*
    // using recursion
#include <bits/stdc++.h>

int findAns(int n, int d, vector<int>& arr, int s1, int s2) {
    if(n < 0) {
        if(s1 >= s2) return (s1-s2 == d);
        return 0;
    }

    // take it;
    int take = findAns(n-1, d, arr, s1+arr[n], s2);

    // not take it;
    int notTake = findAns(n-1, d, arr, s1, s2+arr[n]);

    return (take+notTake)%1000000007;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // using recursion
    return findAns(n-1, d, arr, 0, 0);
}



*/

/*
    // using memoization
#include <bits/stdc++.h>

int findAns(int n, int d, vector<int>& arr, int s1, int s2, int sum, vector<vector<int>>& dp) {
    if(n < 0) {
        if(s1 >= s2) return (s1-s2 == d);
        return 0;
    }

    int col = (s1-s2 <= 0) ? abs(s1-s2) : sum+(s1-s2);

    if(dp[n][col] != -1) return dp[n][col];

    // take it;
    int take = findAns(n-1, d, arr, s1+arr[n], s2, sum, dp);

    // don't take it;
    int notTake = findAns(n-1, d, arr, s1, s2+arr[n], sum, dp);

    return dp[n][col] = (take+notTake)%1000000007;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    // using memoization
    vector<vector<int>> dp(n, vector<int>((sum+1)*2, -1));
    return findAns(n-1, d, arr, 0, 0, sum, dp);
}


*/

/*



*/

/*



*/