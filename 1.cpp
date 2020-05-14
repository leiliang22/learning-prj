class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> dict;
        map<int, int>::iterator it;

        for (int i=0; i<nums.size(); ++i) {
            int peer = target - nums[i];
            it = dict.find(peer);
            if (it != dict.end()) {
                ans.push_back(it->second);
                ans.push_back(i);
                return ans;
            } else {
                dict[nums[i]] = i;
            }
        }

        return ans;
    }
};
