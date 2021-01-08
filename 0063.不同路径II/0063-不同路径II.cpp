class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> path(n);

        path[0] = (obstacleGrid[0][0] == 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    path[j] = 0;
                    continue;
                }

                if (j-1 >= 0 && obstacleGrid[i][j-1] == 0) {
                    path[j] += path[j-1];
                }
            }
        }

        return path.back();
    }
};