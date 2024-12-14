class Solution {
public:
    void dfs(int i , int j ,vector<vector<int>>&vis,vector<vector<char>>mat,int delrow[],int delcol[]){
        vis[i][j]=1;
        int n = mat.size();
        int m = mat[0].size();
        for(int k= 0 ; k<4;k++){
            int nrow=i+delrow[k];
            int ncol = j+delcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,mat,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>&mat) {
        int n = mat.size();
        int m = mat[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        //traversing the boundary rows
        for(int j = 0 ; j < m ; j++){
            //traversing the first rows
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,vis,mat,delrow,delcol);
            }
            //traversing the last row
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat,delrow,delcol);
            }
        }
        //traversing the boundary coloumn
        for(int i = 0 ;i< n ;i++){
            //traversing the first column
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat,delrow,delcol);
            }
            //traversing the last column
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat,delrow,delcol);
            }
        }
        for(int i = 0 ; i< n ;i++){
            for(int j = 0 ; j<m ; j++){
                if(!vis[i][j] && mat[i][j]=='O') mat[i][j]='X';
            }
        }
    }
};