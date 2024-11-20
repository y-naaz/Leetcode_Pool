class Solution {
public:
void merge(vector<int>&arr , int low , int mid , int high){
        int left = low ; 
        int right = mid+1;
        vector<int>temp;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int  i = low ; i<=high ; i++){
            arr[i] = temp[i-low];
        } 
    }
    int countPiars(vector<int>&arr , int l , int m , int h){
        int cnt = 0 ; 
        int right = m+1;
        for(int i = l ; i<=m ; i++){
            while(right<=h && (long long)arr[i]>2LL*arr[right]){
                 right++;
            }
            cnt+=(right-(m+1));
        }
        return cnt ; 
    }
    int mergeSort(vector<int>& arr , int low ,int  high){
        int cnt = 0 ; 
        if(low>=high) return cnt ; 
        int mid = (low+high)/2;
        cnt=cnt+mergeSort(arr ,low , mid);
        cnt+=(mergeSort(arr, mid+1 ,high));
        cnt+=(countPiars(arr , low , mid , high));
        merge(arr,low , mid , high);
        return cnt ; 
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
      return mergeSort(nums, 0 , n-1);  
    }
};