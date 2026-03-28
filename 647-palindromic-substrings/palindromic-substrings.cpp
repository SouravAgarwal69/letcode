class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        vector<vector<bool>>present(s.size(),vector<bool>(s.size()));
        for(int len=1;len<=s.size();len++)
        {
            for(int i=0;i+len-1<s.size();i++)
            {
                int j=i+len-1;
                if(len==1)
                {
                   present[i][j]=true;
                }
                else if(len==2)
                {
                    present[i][j]=(s[i]==s[j]);
                }
                else
                {
                    present[i][j]=(s[i]==s[j] && present[i+1][j-1]);
                }
                if(present[i][j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};