class Solution {
public:
    static bool comp( int a , int b){
        string str1 = to_string(a);
        string str2 = to_string(b);
        return str1+str2>str2+str1;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),comp);
        string res ="";
        if(nums[0]==0)
        {
            return "0";
        }
        for(auto it : nums) 
        {
            res+=to_string(it);
        }
        return res;
    }

};