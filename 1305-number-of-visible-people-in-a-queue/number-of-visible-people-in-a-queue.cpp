class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int  i = n-1;i>=0;i--){
            while(!st.empty()&& st.top()<arr[i]){
                ans[i]++;
                st.pop();
            }
            if(!st.empty()){
                ans[i]++;
            }
            st.push(arr[i]);
        }
        return ans;
    }
};