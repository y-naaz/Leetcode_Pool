class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1= word1.size();
        int n2= word2.size();
        int w1i=0;
        int w2i=0;
        int i =0;
        int j =0;
        while(w1i<n1 && w2i<n2){
            if(word1[w1i][i]!= word2[w2i][j]){
                return false;
            }
            i++;
            j++;
            if(i==word1[w1i].length()){
                i=0;
                w1i++;
            }
            if(j==word2[w2i].length()){
                j=0;
                w2i++;
            }
        }
         return w1i==n1 && w2i==n2;
    }
};