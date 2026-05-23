class Solution {
public:
    int minimumDeletions(string s) {
        int cnt=s.size();
        int cntA=0,cntB=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                cntA++;
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                cntA--;
            }
            cnt=min(cnt,cntA+cntB);
            if(s[i]=='b')
            {
                cntB++;
            }
        }
        return cnt;
    }
};