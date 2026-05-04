class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n>0)
        {
            int temp=n&1;
            if(temp==1)
            {
                 cnt++;
            }
            n=n>>1;
        }
        return cnt;
    }
};