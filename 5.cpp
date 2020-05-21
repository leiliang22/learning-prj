class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i=0; i<s.length(); ++i) {
            string s1 = func(s, i, i);
            string s2 = func(s, i, i+1);
            res = (res.size() < s1.size() ? s1 : res);
            res = (res.size() < s2.size() ? s2 : res);
        }
        return res;
    }

private:
    string func(string& s, int l, int r) {
        while (l>=0 && r<s.size() && s[l] == s[r]) {
            --l; ++r;
        }
        cout << l << "," << r<<"," << s.substr(l+1, r-l-1) << endl;
        return s.substr(l+1, r-l-1);
    }
};
