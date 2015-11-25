/**********************************************************
 * File name: SearchInRotatedSortedArrayII.cpp
 * Author: lei.liang
 *********************************************************/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int result = -1;
        int l=0, r=nums.size()-1;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (target == nums[mid]) return true;
            
            if (nums[l]==nums[mid] && nums[mid]==nums[r]) {
                int i=1;
                while (nums[mid+i] == nums[mid-i] && mid-i > 0)
                    ++i;
                if (nums[mid+i] != nums[mid])
                    l = mid+i;
                else
                    r = mid-i;
                continue;
            }
            
            if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target <= nums[r])
                    l = mid+1;
                else
                    r = mid-1;
            } else {
                if (target >= nums[l] && target < nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
        }
        return false;
    }
};