class Solution {
public:
    vector<int>parent;
	vector<int>rank;
	int find(int node){
	    if(node==parent[node]) return node;
	    return parent[node] = find(parent[node]);
	}
	void unionByRank(int x , int y){
	    int x_parent = find(x);
	    int y_parent = find(y);
	    if(x_parent==y_parent) return ;
	    else{
	        if(rank[x_parent]<rank[y_parent]) {
	            parent[x_parent] = y_parent;
	        }
	        else if(rank[x_parent]>rank[y_parent]){
	            parent[y_parent] = x_parent;
	        }
	        else{
	            parent[x_parent] = y_parent;
	            rank[y_parent]++;
	        }
	    }
	}
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0 ; i < n ; i++){
            parent[i]=i;
        }
            int m = connections.size();
            if(m<n-1) return -1;
            int components = n; ; 
            for(auto it:connections){
                if(find(it[0])!=find(it[1])){
                    unionByRank(it[0],it[1]);
                    components--;
                }
            }
        return components-1;
    }
};