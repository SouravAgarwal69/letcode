class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result(n+1);
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            for(int k=0;k<32;k++)
            {
                 int temp=1<<k;
                 if((temp & i)!=0)
                 {
                     cnt++;
                 }
            }
            result[i]=cnt;
        }
        return result;
    }
};