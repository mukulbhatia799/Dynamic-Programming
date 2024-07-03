/*
    // using recursion

void findAns(vector<int>& arr, int ind, int take, int notTake, int &answer) {
	if(ind < 0) {
		answer = min(answer, abs(take-notTake));
		return ;
	}

	// take it
	findAns(arr, ind-1, take+arr[ind], notTake, answer);
	// don't take it
	findAns(arr, ind-1, take, notTake+arr[ind], answer);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// using recursion
	int answer = INT_MAX;
	findAns(arr, arr.size()-1, 0, 0, answer);

	return answer;
}

*/

/*


	// using memoization

int findAns(int n, int take, int notTake, vector<int>& arr, vector<vector<int>> &dp) {
	if(n < 0) {
		// cout << take << ", " << notTake << endl;
		return abs(take - notTake);
	}

	if(dp[n][abs(take-notTake)] != -1) return dp[n][abs(take-notTake)];

	// take it
	int diff1 = findAns(n-1, take+arr[n], notTake, arr, dp);

	// don't take it
	int diff2 = findAns(n-1, take, notTake+arr[n], arr, dp);

	// cout << "diff1: " << diff1 << " diff2: " << diff2 << endl;
	return dp[n][abs(take-notTake)] = min(diff1, diff2);

}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	vector<vector<int>> dp(n, vector<int>(sum+1, -1));
	
	return findAns(n-1, 0, 0, arr, dp);
}


*/

/*
	// using tabulation

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
	
	for(int i = 0; i < n; i++) {
		dp[i][0] = true;
	}

	if(arr[0] <= sum) dp[0][arr[0]] = true;

	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= sum; j++) {
			int notTake = dp[i-1][j];
			int take = false;
			if(arr[i] <= j) take = dp[i-1][j-arr[i]];
			dp[i][j] = notTake | take;
		}
	}

	int mini = INT_MAX;
	for(int i = 0; i <= sum; i++) {
		if(dp[n-1][i] == true) {
			int firstSubSum = i;
			int secSubSum = sum-i;
			mini = min(mini, abs(firstSubSum-secSubSum));
		}
	}

	return mini;
	
}


*/

/*
	// using space optimization
    
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	vector<bool> prev(sum+1, 0), curr(sum+1, 0);
	
		prev[0] = true;
		curr[0] = true;


	if(arr[0] <= sum) curr[arr[0]] = true;

	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= sum; j++) {
			int notTake = prev[j];
			int take = false;
			if(arr[i] <= j) take = prev[j-arr[i]];
			curr[j] = notTake | take;
		}
		prev = curr;
	}

	int mini = INT_MAX;
	for(int i = 0; i <= sum; i++) {
		if(prev[i] == true) {
			int firstSubSum = i;
			int secSubSum = sum-i;
			mini = min(mini, abs(firstSubSum-secSubSum));
		}
	}

	return mini;
	
}


*/