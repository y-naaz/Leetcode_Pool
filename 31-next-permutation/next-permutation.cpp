class Solution {
public:
    void nextPermutation(vector<int>& arr) {
       int n = arr.size();
       int indx=-1;
       for(int i = n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            indx = i ;
            break ;
        }
       }
       if(indx==-1){
         reverse(arr.begin(),arr.end());
         return ;
       }
       for(int  i = n-1;i>indx;i--){
        if(arr[i]>arr[indx]){
            swap(arr[i],arr[indx]);
            break;
        }
       }
       reverse(arr.begin()+indx+1,arr.end());
       
        }
};