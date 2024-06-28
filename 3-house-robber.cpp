/*

//  ================ using recursion ================

int findAnsRE(int ind, vector<int> &nums) {
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;
    int rob = nums[ind] + findAnsRE(ind-2, nums);
    int NotRob = 0 + findAnsRE(ind-1, nums);

    return max(rob, NotRob);
}
int rob(vector<int>& nums) {
    // using recursion
    return findAnsRE(nums.size()-1, nums);

}


// T.C: O(2^N)
// S.C: O(N) {aux stack space}

*/

/*

//  ================= using memoization =================

int findAnsRE(int ind, vector<int> &nums, vector<int> &dp) {
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int rob = nums[ind] + findAnsRE(ind-2, nums, dp);
    int NotRob = 0 + findAnsRE(ind-1, nums, dp);

    return dp[ind] = max(rob, NotRob); 
}
int rob(vector<int>& nums) {
    // using memoization
    vector<int> dp(nums.size(), -1);
    return findAnsRE(nums.size()-1, nums, dp);

}

// T.C: O(N)
// S.C: O(N) + O(N) {aux stack space + aux array space}

*/

/*

//  ================= using tabulation =================

#include <bits/stdc++.h>

    int rob(vector<int>& nums) {
        // using tabulation
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int rob = nums[i];
            if(i > 1) rob += dp[i-2];
            int notRob = 0 + dp[i-1];

            dp[i] = max(rob, notRob);
        }

        return dp[nums.size()-1];

    }


// T.C: O(N)
// S.C: O(N) {aux array space}

*/

/*

//  ================= using space optimization =================

int rob(vector<int>& nums) {
    // using space optimization
    
    int prev1 = nums[0], prev2 = 0;
    for(int i = 1; i < nums.size(); i++) {
        int rob = nums[i];
        if(i > 1) rob += prev2;
        int notRob = 0 + prev1;
        prev2 = prev1;
        prev1 = max(rob, notRob);
    }
    return prev1;
}

// T.C: O(N)
// S.C: O(1)

*/