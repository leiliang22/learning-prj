class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int64_t maxval = nums[0];
        int64_t minval = nums[0];
        int64_t res = maxval;

        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] > 0) {
                maxval = findmax(maxval*nums[i], nums[i]);
                minval = findmin(minval*nums[i], nums[i]);
            } else if (nums[i] < 0) {
                int64_t tmpmax = maxval, tmpmin = minval;
                maxval = findmax(tmpmin*nums[i], nums[i]);
                minval = findmin(tmpmax*nums[i], nums[i]);
            } else {
                maxval = minval = 0;
            }
            //cout << "max:" << maxval << "min:" << minval << endl;
            res = (res < maxval ? maxval : res);
        }
        return res;
    }

private:
    int64_t findmin(int64_t x, int64_t y) {
        return (x < y ? x : y);
    }
    int64_t findmax(int64_t x, int64_t y) {
        return (x < y ? y : x);
    }
};
