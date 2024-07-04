// gfg**********

/*
    // using recursion
    
int findAns(int n, int W, int wt[], int val[]) {
    if(n < 0 || W == 0) return 0;
    
    // pick
    int pick = 0;
    if(wt[n] <= W) pick = val[n] + findAns(n-1, W-wt[n], wt, val);
    
    // not pick
    int notPick = 0 + findAns(n-1, W, wt, val);
    
    return max(pick, notPick);
}

int knapSack(int W, int wt[], int val[], int n) 
{
    // using recursion
    return findAns(n-1, W, wt, val);
    
}


*/

/*
    // using memoization

int findAns(int n, int W, int wt[], int val[], vector<vector<int>> &dp) {
    if(n < 0 || W == 0) return 0;

    if(dp[n][W] != -1) return dp[n][W];

    // pick
    int pick = 0;
    if(wt[n] <= W) pick = val[n] + findAns(n-1, W-wt[n], wt, val, dp);

    // not pick
    int notPick = 0 + findAns(n-1, W, wt, val, dp);

    return dp[n][W] = max(pick, notPick);
}

int knapSack(int W, int wt[], int val[], int n)
{
    // using memoization
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    return findAns(n-1, W, wt, val, dp);

}

*/

/*



*/

/*



*/