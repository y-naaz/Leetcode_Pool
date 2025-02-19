class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int j  = 0 ; 
        int diff = -1;
        int ans = 0 ; 
        for(int i = 0 ; i < n  ; i ++){
            while( j<n && nums[j]-nums[i]<k) j++;
            if(j< n && nums[j]-nums[i]<=k && i!=j){
                ans++;
                while(j+1<n && nums[j+1]==nums[j]) j++;
                j++;
            }
        }
        return ans;
    }
};
