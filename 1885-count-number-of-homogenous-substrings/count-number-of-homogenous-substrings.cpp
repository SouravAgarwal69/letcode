class Solution {
public:
    int countHomogenous(string s) {
        int res=0,cnt=0;
        int mod=1e9+7;
        for(int i=0;i<s.size();i++)
        {
            if(i>0 && s[i]==s[i-1])
            {
                cnt++;
            }
            else
            {
                cnt=1;
            }
            res=(res+cnt)%mod;
        }
        return res;
    }
};