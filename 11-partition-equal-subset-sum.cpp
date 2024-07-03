/*
    // using recursion
class Solution {
public:
    bool findAns(int n, int target, vector<int>& nums) {
        if(n == 0) return (target == nums[0]);

        bool take = false;
        if(nums[n] <= target) take = findAns(n-1, target-nums[n], nums);

        bool notTake = findAns(n-1, target, nums);

        return take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        // using recursion
        int n = nums.size();
        int target = 0;
        for(int i = 0; i < nums.size();i++) {
            target += nums[i];
        }
        if(target & 1) return false;        // if sum is odd then we can't divide it in two subsets.

        return findAns(n-1, target/2, nums);
    }
};


*/

/*
    // using memoization
class Solution {
public:
    bool findAns(int n, int target, vector<int>& nums, vector<vector<int>> &dp) {
        if(n == 0) return (target == nums[0]);

        if(dp[n][target] != -1) return dp[n][target];

        bool take = false;
        if(nums[n] <= target) take = findAns(n-1, target-nums[n], nums, dp);

        bool notTake = findAns(n-1, target, nums, dp);

        return dp[n][target] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        // using memoization
        int n = nums.size();
        int target = 0;
        for(int i = 0; i < nums.size();i++) {
            target += nums[i];
        }
        if(target & 1) return false;        // if sum is odd then we can't divide it in two subsets.
        target /= 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return findAns(n-1, target, nums, dp);
    }
};


*/

/*
    // using tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // using tabulation
        int n = nums.size();
        int sum = 0;
        for(auto ele: nums) sum += ele;
        if(sum & 1) return false;
        sum /= 2;
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));

        for(int i = 0; i < n; i++) dp[i][0] = true;

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {
                int notTake = dp[i-1][j];
                int take = false;
                if(nums[i] <= j) take = dp[i-1][j-nums[i]];
                dp[i][j] = (take || notTake);
            }
        }

        return dp[n-1][sum];

    }
};


*/

/*
    // using space optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // using spacae optimization
        int n = nums.size();
        int sum = 0;
        for(auto ele: nums) sum += ele;
        if(sum & 1) return false;
        sum /= 2;

        vector<bool> prev(sum+1, 0);
        prev[0] = true;
        if(nums[0] <= sum) prev[nums[0]] = true;

        for(int i = 1; i < n; i++) {
            vector<bool> curr(sum+1, 0);
            curr[0] = true;
            for(int j = 1; j <= sum; j++) {
                int notTake = prev[j];
                int take = false;
                if(nums[i] <= j) take = prev[j-nums[i]];
                curr[j] = (take || notTake);
            }
            prev = curr;
        }

        return prev[sum];

    }
};


*/

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    if (n <= 2)
        return n;
    // using tabulation
    vector<int> dp(n + 1, -1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

void findAns(int n, int num, int sum, int count, int &answer) {
    if(n <= 0) return ;
    if(sum == num) {
        cout << "sum: " << sum << endl;
        answer = min(answer, count);
        return ;
    }

    // take it
    if(n*n <= num) findAns(n, num, sum+(n*n), count+1, answer);

    // not take it;
    findAns(n-1, num, sum, count, answer);
}

int main()
{
    int answer = INT_MAX;
    int n;
    findAns(n, n, 0, 0, answer);

    cout << "answer: " << answer << endl;

    return 0;
}