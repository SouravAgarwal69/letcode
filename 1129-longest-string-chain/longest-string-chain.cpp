class Solution {
public:
    bool isPossible(int j,int i,vector<string>&words)
    {
        string prev=words[j];
        string curr=words[i];
        if(prev.size()+1!=curr.size())
        {
            return false;
        }
        int m=0,n=0;
        while(m<prev.size() && n<curr.size())
        {
            if(prev[m]==curr[n])
            {
                m++;
            }
            n++;
        }
        return m==prev.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &words1,string &words2)
        {
            return words1.size()<words2.size();
        });
        vector<int>dp(words.size(),1);
        int maximum=1;
        for(int i=1;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isPossible(j,i,words))
                {
                   dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maximum=max(maximum,dp[i]);
        }
        return maximum;
    }
};