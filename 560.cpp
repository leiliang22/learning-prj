class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int size_ = nums.size();
        map<int,int> dict;
        dict[0] = 1;
        int sum = 0;

        for (int i=0; i<size_; ++i) {
            sum += nums[i];
            ans += dict[sum - k];
            ++dict[sum];
        }

        return ans;
    }
};
