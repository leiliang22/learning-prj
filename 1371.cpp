class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> pre(32, INT_MAX);
        int cur = 0;
        int ans = 0;
        pre[0] = -1;

        for (int i=0; i<s.length(); ++i) {
            switch (s[i]) {
                case 'a':
                    cur ^= 1;
                    break;
                case 'e':
                    cur ^= 2;
                    break;
                case 'i':
                    cur ^= 4;
                    break;
                case 'o':
                    cur ^= 8;
                    break;
                case 'u':
                    cur ^= 16;
                    break;
                default:
                    break;
            }
            if (pre[cur] == INT_MAX) pre[cur] = i;
            ans = max(ans, i - pre[cur]); 
        }

        return ans;
    }
};
