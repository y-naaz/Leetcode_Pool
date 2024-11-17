class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long k  = 0 ;
        long long cnt = 0 ; 
        long long xr = 0 ; 
        unordered_map<long long,long long>mp;
        mp[xr]++;
        for(int i = 0 ; i < n  ; i++){
            xr = xr^nums[i];
            long long x = xr^k;
            cnt+=mp[x];
            mp[xr]++;
        }
        return cnt ; 
    }
};