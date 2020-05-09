class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int nw = 0;
        int h = matrix.size();
        int w = matrix[0].size();
        vector<int> dp(w+1, 0);
        int maxside = 0;

        for (int i=0; i<h; ++i) {
            nw = 0;
            for (int j=0; j<w; ++j) {
                int next_nw = dp[j+1];
                if (matrix[i][j] == '1') {
                    dp[j+1] = std::min(std::min(dp[j], dp[j+1]), nw) + 1;
                } else {
                    dp[j+1] = 0;
                }
                maxside = (maxside < dp[j+1] ? dp[j+1] : maxside);
                nw = next_nw;
            }
        }
        return maxside * maxside;
    }
};
