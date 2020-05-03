class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int maxval = res;
        for (int i=1; i<nums.size(); i++) {
            if (res >= 0) {
                res += nums[i];
            } else {
                res = nums[i];    
            }
            maxval = (maxval >= res ? maxval : res);
        }

        return maxval;
    }
};
