class Solution {
public:
    void dfs(int i  , vector<int>&vis,vector<vector<int>>&adj){
        vis[i]=1;
        for(auto&it : adj[i]){
            if(vis[it]==-1){
                dfs(it,vis,adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,-1);
        vector<vector<int>>adj(n);
        for(int  i = 0 ; i< n ; i++){
            for(int  j = 0 ; j < rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        dfs(0,vis ,adj);
        for(int  i = 0 ; i < n  ; i++){
            if(vis[i]==-1) return false;
        }
        return true;
    }
};