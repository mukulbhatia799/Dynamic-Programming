/*

//  ================ using recursion ================ 

#include <bits/stdc++.h> 
int findAnsRE(int ind, vector<int> &nums) {
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;

    int pick = nums[ind] + findAnsRE(ind-2, nums);
    int notPick = 0 + findAnsRE(ind-1, nums);

    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    return findAnsRE(nums.size()-1, nums);   // using recursion
}

*/

/*

//  ================= using memoization ================= 

#include <bits/stdc++.h> 
int findAnsRE(int ind, vector<int> &nums, vector<int> &dp) {
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + findAnsRE(ind-2, nums, dp);
    int notPick = 0 + findAnsRE(ind-1, nums, dp);

    return dp[ind] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    return findAnsRE(nums.size()-1, nums, dp);   // using memoization
}

*/

/*

//  ================= using tabulation ================= 

#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // done using tabulation.
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    // using tabulation
    int whenAt0 = nums[0], lessThan0 = 0;
    for(int i = 1; i < nums.size(); i++) {
        int pick = nums[i];
        if(i > 1) pick += dp[i-2];
        int notPick = 0 + dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[nums.size()-1];
}

*/

/*

//  ================= using space optimization ================= 

#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // using space optimization;
    int prev1 = nums[0], prev2 = 0;
    for(int i = 1; i < nums.size(); i++) {
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = 0 + prev1;
        prev2 = prev1;
        prev1 = max(take, notTake);
    }
    return prev1;
}

*/