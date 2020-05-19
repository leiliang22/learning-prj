class Solution {
public:
    bool validPalindrome(string s) {
        if (s.length() < 2) return true;

        size_t start = 0;
        size_t end = s.length() - 1;

        bool ans = valid(s, start, end);
        size_t left = start+1;
        size_t right = end-1;
        return ans || valid(s, left, end) || valid(s, start, right);
    }

    bool valid(string& s, size_t& start, size_t& end) {
        while (start < end) {
            if (s[start] == s[end]) {
                ++start;
                --end;
            } else {
                return false;
            }
        }
        return true;
    }
};
