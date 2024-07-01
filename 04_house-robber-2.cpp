/*

int findAns(vector<int> &nums)
{
    int prev1 = nums[0], prev2 = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int rob = nums[i];
        if (i > 1)
            rob += prev2;
        int notRob = 0 + prev1;
        prev2 = prev1;
        prev1 = max(rob, notRob);
    }
    return prev1;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    // just remove the front house in first call and last house in second call as they are linked circular so we can take max of both.
    vector<int> removeFirst;
    vector<int> removeLast;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            removeFirst.push_back(nums[i]);
        if (i != n - 1)
            removeLast.push_back(nums[i]);
    }

    int answer = max(findAns(removeFirst), findAns(removeLast));
    return answer;
}

*/