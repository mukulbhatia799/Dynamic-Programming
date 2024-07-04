/*
    // using recursion
class Solution {
public:
    int findAns(int n, vector<int>& coins, int amount) {
        if(n == 0) {
            if(amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }

        // take;
        int take = INT_MAX;
        if(coins[n] <= amount) take = 1 + findAns(n, coins, amount-coins[n]);
        int notTake = 0 + findAns(n-1, coins, amount);

        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int answer = findAns(n-1, coins, amount);
        return answer == 1e9 ? -1 : answer; 
    }
};


*/

/*
    // using memoization
class Solution {
public:
    int findAns(int n, vector<int>& coins, int amount, vector<vector<int>> &dp) {
        if(n == 0) {
            if(amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }

        if(dp[n][amount] != -1) return dp[n][amount];

        // take;
        int take = INT_MAX;
        if(coins[n] <= amount) take = 1 + findAns(n, coins, amount-coins[n], dp);
        int notTake = 0 + findAns(n-1, coins, amount, dp);

        return dp[n][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int answer = findAns(n-1, coins, amount, dp);
        return answer == 1e9 ? -1 : answer; 
    }
};


*/

/*



*/

/*



*/