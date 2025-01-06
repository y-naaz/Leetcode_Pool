class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>answer(n,0);
        for(int i= 0 ; i<n ;i++){
            for(int j = 0 ; j<n;j++){
                if(i==j) continue ;
                if(boxes[j] == '1')
                answer[i] = answer[i]+abs(i-j);
            }
        }
        return answer;
    }
};