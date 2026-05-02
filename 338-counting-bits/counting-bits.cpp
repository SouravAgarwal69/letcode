class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result;
        for(int i=0;i<=n;i++)
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
            result.push_back(cnt);
        }
        return result;
    }
};