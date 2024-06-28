/*

//  ------------------- using recursion ------------------- 

#include <bits/stdc++.h> 

int findAns(int n, vector<int> &heights, vector<int> &dp) {
    if(n == 0) return 0;

    int left = findAns(n-1, heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right = findAns(n-2, heights) + abs(heights[n] - heights[n-2]);

    return min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    // using recursion
    return findAns(n-1, heights);
}

*/


/*

//  ---------------- using memoization ---------------- 

#include <bits/stdc++.h> 

int findAns(int n, vector<int> &heights, vector<int> &dp) {
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    int left = findAns(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right = findAns(n-2, heights, dp) + abs(heights[n] - heights[n-2]);

    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1); // using memoization
    dp[0] = 0;
    return findAns(n-1, heights, dp);
}

 */


/*

//  ------------- using tabulation ------------- 

#include <bits/stdc++.h> 

int findAns(int n, vector<int> &heights, vector<int> &dp) {
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    int left = findAns(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right = findAns(n-2, heights, dp) + abs(heights[n] - heights[n-2]);

    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0); // using tabulation
    for(int i = 1; i < n; i++) {
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1) right = dp[i-2] + abs(heights[i] - heights[i-2]);

        dp[i] = min(left, right);
    }
    return dp[n-1];
}

*/


/*

// ------------- using space optimization ------------- 

#include <bits/stdc++.h> 

int findAns(int n, vector<int> &heights, vector<int> &dp) {
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    int left = findAns(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right = findAns(n-2, heights, dp) + abs(heights[n] - heights[n-2]);

    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    // using space optimization(S.C => O(1))
    int prev1 = 0, prev2 = 0;
    for(int i = 1; i < n; i++) {
        int left = prev1 + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i > 1) right = prev2 + abs(heights[i]-heights[i-2]);
        prev2 = prev1;
        prev1 = min(left, right);
    }

    return prev1;
    
}

*/