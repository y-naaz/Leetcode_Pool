class Solution {
public:
    int reverse(int a){
        int res = 0 ; 
        while(a>0){
            int rem = a%10;
            res = res*10+rem;
            a=a/10;
        }
        return res;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
            st.insert(reverse(nums[i]));
        }
        return st.size();
    }
};