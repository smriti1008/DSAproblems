class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxVal = 0;

        for (auto& row : grid) {
            for (int x : row) {
                maxVal = max(maxVal, x);
            }
        }

        int bits = 0;
        while ((1LL << bits) <= maxVal) {
            bits++;
        }

        int limit = 1 << bits;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(
                n, vector<bool>(limit, false)
            )
        );

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int x = 0; x < limit; x++) {
                    if (i > 0 && dp[i - 1][j][x]) {
                        dp[i][j][x ^ grid[i][j]] = true;
                    }

                    if (j > 0 && dp[i][j - 1][x]) {
                        dp[i][j][x ^ grid[i][j]] = true;
                    }
                }
            }
        }

        for (int x = 0; x < limit; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};