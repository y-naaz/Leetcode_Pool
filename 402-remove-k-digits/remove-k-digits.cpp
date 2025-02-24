class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k>=n) return "0";
        stack<char> st;
        st.push(num[0]);
        for (int i = 1; i < n; i++) {
            while (!st.empty()&& k && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k){
                st.pop();
                k--;
            }
        string str = "";
        while(!st.empty()){
            
            str+=st.top();
            st.pop();
        }
        
        for(int  i = str.size()-1; i>=0;i--){
            if(str[i]!='0'){
                break;
            }
            str.pop_back();
        }
        reverse(str.begin(),str.end());
        return str==""?"0":str;
    }
};