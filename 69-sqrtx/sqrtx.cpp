class Solution {
public:
    int mySqrt(int x) {
      int low=0;
      int high=x/2+1;
      long long sqroot=-1;
      while(low<=high){
          long long mid= low+(high-low)/2;
          if(mid*mid==x) {
              sqroot= mid;
              break;
          }
          if(mid*mid<x){
               low=mid+1;
               sqroot=mid;
          }
          else high=mid-1;
      }
      return sqroot;
    }
};