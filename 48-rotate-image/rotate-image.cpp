class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
//The logic behind this code is first transpose the matrix and then reverse each row.
     int n=matrix.size();
     for(int i =0;i<n;i++){
         for(int j =0;j<n;j++){
             if(i>j){
                 int temp=matrix[i][j];
                 matrix[i][j]=matrix[j][i];
                 matrix[j][i]=temp;
             }
         }
     }
     int k = 0;
     int j = n-1;
     for(int i =0;i<n;i++){
     while(k<j){
        int c=matrix[i][k];
        matrix[i][k]=matrix[i][j];
        matrix[i][j]=c;
        k++;
        j--;
     }
     k=0;
     j=n-1;
    }
    }
};