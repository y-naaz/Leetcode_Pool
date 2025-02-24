class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        int n = tickets.size();
        int time = 0 ;

        for(int  i = 0 ; i< n ; i++){
            q.push({tickets[i],i});
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            it.first--;
            time++;
            if(it.first==0 && it.second==k){
                break ; 
                return time;
            }
            if(it.first>0){
                q.push({it.first , it.second});
            }
           
        }
        
        return time;
    }
};