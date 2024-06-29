/*
    // using recursion

    void findAns(int m, int n, int i, int j, int &count) {
        if(i == m && j == n) {
            count++;
            return ;
        }
        if(i+1 <= m) findAns(m, n, i+1, j, count);
        if(j+1 <= n) findAns(m, n, i, j+1, count);
    }
    int uniquePaths(int m, int n) {
        int i = 0, j = 0, count = 0;
        findAns(m-1, n-1, i, j, count);
        return count;
    }

    // T.C: O(2^m*n)
    // S.C: O(path length) =. O(m+n);

*/