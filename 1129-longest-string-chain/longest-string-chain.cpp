class Solution {
public:
    bool isPossible(int prev,int curr,vector<string>&words)
    {
        if(words[prev].size()+1!=words[curr].size())
        {
           return false;
        }
        int i=0,j=0;
        while(j<words[curr].size() && i<words[prev].size())
        {
            if(words[curr][j]==words[prev][i])
            {
                i++;
            }
            j++;
        }
        return i==words[prev].size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &words1,string &words2){
              return words1.size()<words2.size();
        });
        int ans=1;
       vector<int>dp(words.size(),1);
       for(int i=1;i<words.size();i++)
       {
          for(int j=0;j<i;j++)
          {
             if(isPossible(j,i,words))
             {
                dp[i]=max(dp[i],dp[j]+1);
             }
          }
          ans=max(ans,dp[i]);
       }
       return ans;
    }
};