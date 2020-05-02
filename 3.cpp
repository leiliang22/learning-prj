#include <set>
#include <string>
#include <queue>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> dir;

        queue<char> q;
        size_t maxlen = 0, res = 0;

        for (char c : s) {
            if (dir.count(c) == 0) {
                dir.insert(c);
                q.push(c);
                ++res;
                maxlen = (maxlen < res ? res : maxlen);
            } else {
                char tc = q.front();
                while (tc != c) {
                    q.pop();
                    dir.erase(c);
                    --res;
                }
                q.pop();
                q.push(c);
            }
        }
        return maxlen;
    }
};

int main() {
	string str = "abcabcbb";
	Solution s;
	return s.lengthOfLongestSubstring(str);
}
