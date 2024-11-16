class Solution {
public:
    string generateTheString(int n) {
        string s = "";;
        if(n%2!=0){
            for(int i  = 0 ; i < n  ; i++) s+='a';
            return s;
        }
        s='a';
        for(int  i = 0 ; i <n-1; i++){
            s+='b';
        }
        return s;
    }
};