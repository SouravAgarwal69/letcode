class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int cntOne=0;
        while(n!=0)
        {
           cntOne=cntOne+(n&1);
           n=n>>1;
        }
        return cntOne==1;
    }
};