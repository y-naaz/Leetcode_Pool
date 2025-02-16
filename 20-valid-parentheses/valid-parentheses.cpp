class Solution {
public:
    bool isValid(string s) {
        stack<char>st ; 
        for(char ch : s){
            if(ch=='[' || ch=='(' || ch=='{') st.push(ch);
            else if(ch==')' || ch=='}' || ch==']'){
                if(st.empty()) return false ; 
                char top = st.top();
                st.pop();
                if((ch==')' && top!='(') 
                    || (ch==']' && top!='[')
                    ||(ch=='}' && top!='{')) return false ;
                
            }
        }
        return st.empty();
    }
};