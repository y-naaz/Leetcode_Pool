class Solution {
public:
    stack<char> process(string s){
        int n = s.size();
        stack<char>st;
        for(int i = 0 ; i<n ; i++){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        return st;
    }
    bool backspaceCompare(string s, string t) {

        return process(s)==process(t);
    }
};