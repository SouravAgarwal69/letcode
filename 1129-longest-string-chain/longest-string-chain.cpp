class Solution {
public:
    int dp[1000][1000];
    bool isPossible(int prev,int index,vector<string>&words)
    {
        if(words[prev].size()+1!=words[index].size())
        {
            return false;
        }
        string s1=words[prev];
        string s2=words[index];
        int i=0,j=0;
        while(j<s2.size() && i<s1.size())
        {
            if(s1[i]==s2[j])
            {
                i++;
            }
            j++;
        }
        return i==s1.size();
    }
    int findLength(vector<string>&words,int prev,int index)
    {
        if(index==words.size())
        {
            return 0;
        }
        if(prev!=-1 && dp[index][prev]!=-1)
        {
            return dp[index][prev];
        }
        int take=0;
        if(prev==-1 || isPossible(prev,index,words))
        {
            take=1+findLength(words,index,index+1);
        }
        int skip=findLength(words,prev,index+1);
        if(prev!=-1)
        {
           return dp[index][prev]=max(take,skip);
        }
        return max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),[](string &a,string &b){
           return a.length()<b.length();
        });
       return findLength(words,-1,0);
    }
};