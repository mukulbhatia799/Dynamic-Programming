
/*
// using recursion

#include <bits/stdc++.h> 

int findAns(int n, int m, vector<vector<int>>& matrix) {
    if(n < 0 || m < 0 || m >= matrix[0].size()) return INT_MIN;
    if(n == 0) return matrix[n][m];

    return matrix[n][m] + max(findAns(n-1, m, matrix), max(findAns(n-1, m-1, matrix), findAns(n-1, m+1, matrix)));
}


int getMaxPathSum(vector<vector<int>> &matrix)
{
    // using recursion
    int n = matrix.size(), m = matrix[0].size();

    int maxi = INT_MIN;
    for(int i = 0; i < m; i++) {
        maxi = max(maxi, findAns(n-1, i, matrix));
    }

    return maxi;
}

*/




/*
// using memoization

#include <bits/stdc++.h> 

int findAns(int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if(n < 0 || m < 0 || m >= matrix[0].size()) return INT_MIN;
    if(n == 0) return matrix[n][m];

    if(dp[n][m] != -1) return dp[n][m];

    return dp[n][m] = matrix[n][m] + max(findAns(n-1, m, matrix, dp), max(findAns(n-1, m-1, matrix, dp), findAns(n-1, m+1, matrix, dp)));
}


int getMaxPathSum(vector<vector<int>> &matrix)
{
    // using memoization
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = INT_MIN;
    for(int i = 0; i < m; i++) {
        maxi = max(maxi, findAns(n-1, i, matrix, dp));
    }

    return maxi;
}


*/
