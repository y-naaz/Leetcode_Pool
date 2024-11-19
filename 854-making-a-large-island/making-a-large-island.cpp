class Solution {
public:
    vector<int>parent ; 
    vector<int>size;
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void unionBySize(int x , int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent==y_parent) return;
        else{
            if(size[x_parent]<size[y_parent]){
                parent[x_parent] = y_parent;
                size[y_parent] += size[x_parent];
            }
            else if(size[x_parent]>size[y_parent]){
                parent[y_parent] = x_parent;
                size[x_parent] += size[y_parent];
            }
            else{
                parent[x_parent] = y_parent;
                size[y_parent]+=size[x_parent];
            }
        }
    }
    bool isValid(int i , int j , int n ){
        return i>=0 && i<n && j>=0 && j<n ; 
    }
    int largestIsland(vector<vector<int>>& grid) {
        int mx = 0;
        int n = grid.size();
        parent.resize(n*n);
        size.resize(n*n,1);
        for(int i = 0  ; i < n*n ; i++ ){
            parent[i]=i;
        }
        //step 1 : make the components connected
        for(int  i = 0 ; i< n  ;i++){
            for(int  j = 0 ; j< n  ; j++){
                if(grid[i][j]==0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int idx = 0 ; idx< 4 ; idx++){
                    int nr = i+dr[idx];
                    int nc = j+dc[idx];
                    if(isValid(nr,nc,n)&& grid[nr][nc]==1){
                        int nodeNo = i*n+j;
                        int adjnodeNo = nr*n+nc;
                        unionBySize(nodeNo, adjnodeNo);
                    }
                }
            }
        }
        //step2: do simple brute force and try to convert every 0 ->1
        for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j< n ; j++){
                if(grid[i][j]==1) continue;
                set<int>components;
                 int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int idx = 0 ; idx< 4 ; idx++){
                    int nr = i+dr[idx];
                    int nc = j+dc[idx];
                    if(isValid(nr,nc,n) && grid[nr][nc]==1){
                        components.insert(find(nr*n+nc));
                    }
                }
                int sizeTotal = 0 ;
                for(auto it: components){
                    sizeTotal+=size[it];

                }
                mx = max(mx , sizeTotal+1);
            }
            //what if matrix have all 1's
        }
         for(int i = 0 ; i<n*n;i++){
                mx = max(mx,size[find(i)]);
            }
        return mx;
    }
};