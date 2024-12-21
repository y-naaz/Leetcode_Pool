class Solution {
public:
    bool isPowerOfThree(int n) {
        int m=n;
        if(n==0) return false;
        else if (n%3!=0 && n!=1) return false;
        else if(n==1) return true;
        while(m!=1){
            m/=3;
            if(m%3!=0 && m!=1) return false;
        }
        return true;
    }
};