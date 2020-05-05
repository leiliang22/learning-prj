class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        size_t step = 0, i = 0;
        size_t maxval = nums[0];

        while (i < nums.size()) {
            step += 1;
            if (maxval >= nums.size() - 1) return step;
            int tmp = 0, tmpidx = 0;
            for (int j=1; j<=nums[i]; ++j) {
                if (tmp <= i + j + nums[i+j]) {
                    tmp = i + j + nums[i+j];
                    tmpidx = i+j;
                }
            }
            maxval = tmp;
            i = tmpidx;
        }
        return step;
    }
};
