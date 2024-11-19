class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //change the times vector in adjacency list
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis+wt<dist[adjNode]){
                    dist[adjNode]= dis+wt;
                    pq.push({dis+wt,adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1 ; i <=n;i++){
            ans = max(ans,dist[i]);
        }
        return ans == INT_MAX ? -1:ans;
    }
};