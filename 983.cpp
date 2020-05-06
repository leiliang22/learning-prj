class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 1, 0);
        size_t j = 0;
        for (int i=0; i<days.size(); ++i) {
            while (j < days[i]) {
                dp[j+1] = dp[j];
                ++j;
            }
            dp[days[i]] = find_min(getdp(days[i] - 1, dp) + costs[0],
                             getdp(days[i] - 7, dp) + costs[1],
                             getdp(days[i] - 30, dp) + costs[2]);
        }
        return dp.back();
    }

    int find_min(int a, int b, int c) {
        int res = (a < b ? a : b);
        return (res < c ? res : c);
    }

    int getdp(int idx, vector<int>& dp) {
        if (idx < 0)
            return 0;
        else
            return dp[idx];
    }
};
