/*
#include<iostream>
using namespace std;

int fibNumber(int n)
{
    if(n <= 1) return n;

    return fibNumber(n-1) + fibNumber(n-2);
}
//        0 1 1 2 3 5 8 13 21 ...
// index: 0 1 2 3 4 5 .....
int main(){
    int n; cin >> n;        // give index.

    cout << "fib: "<< fibNumber(n) << endl;

    return 0;
}

// Time Complexity: O(2^N)
// Space Complexity: O(N) => {stack space}


// In this solution, we are computing the previously computed value again like if we draw the recursion tree for fib(5) then we are repeating the calls. So, if we can somehow store the prev. computed values( called memoization ), we can save time.


*/



#include<iostream>
#include<vector>
using namespace std;

int fibNumber(int n, vector<int> &dp) {
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];   // here if n is prev. computed, then return it.

    return dp[n] = fibNumber(n-1, dp) + fibNumber(n-2, dp);         // storing the nth value.
}

int main() {
    int n; cin >> n;        // index.

    vector<int> dp(n+1, -1);

    cout << "fib: "<< fibNumber(n, dp);

    return 0;
}
// Time Complexity: O(N)
// Space Complexity: O(N)+O(N) => {stack space + extra array space.}