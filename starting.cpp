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
// In this solution, we are computing the previously computed value again like if we draw the recursion tree for fib(5) then we are repeating the calls. So, if we can somehow store the prev. computed values( called memoization ), we can save time.