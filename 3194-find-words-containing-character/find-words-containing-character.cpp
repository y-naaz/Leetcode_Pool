class Solution {
public:
    bool containX(string word , char x){
        for(char ch : word){
            if(ch==x) return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int>v;
        for(int i = 0 ;i<n; i++){
            if(containX(words[i],x)) v.push_back(i);
        }
        return v ;
    }
};