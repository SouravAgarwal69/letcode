class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        for(int k=0;k<32;k++)
        {
            int temp=1<<k;
            if((temp & n)!=0)
            {
                cnt++;
            }
            
        }
        return cnt;
    }
};