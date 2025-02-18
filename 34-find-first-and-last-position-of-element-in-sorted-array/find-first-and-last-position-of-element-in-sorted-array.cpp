class Solution {
public:
    int leftmost(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        int ans = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                ans = mid;
                h = mid - 1;
            }
        }
        return ans;
    }
    int rightmost(vector < int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        int ans = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftmost(nums,target);
        int right = rightmost(nums,target);
        return {left,right};
    }
}
;