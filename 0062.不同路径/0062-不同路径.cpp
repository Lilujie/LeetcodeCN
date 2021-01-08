class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0) return 0;
        if (m == 1 || n == 1) return 1;

        int path[101][101]={0};
        //return uniquePaths(m-1,n) + uniquePaths(m, n-1); //超时
        for (int i = 1; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                path[1][j] = 1;
                path[i][1] = 1;
            }
        }
        
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m][n];

        // vector<int> dp(n, 0);
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         dp[j] = (i > 0 && j >0 ) ? dp[j] = dp[j-1] + dp[j] : 1;
        //     }
        // }
        // return dp[n-1];
    }
};