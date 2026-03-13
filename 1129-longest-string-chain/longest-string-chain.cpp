class Solution {
public:
    int dp[1000][1000];
    bool isPossible(vector<string>&words,int prev,int index)
    {
        string word1=words[prev];
        string word2=words[index];
        if(word1.size()+1!=word2.size())
        {
            return false;
        }
        int i=0,j=0;
        while(i<word1.size() && j<word2.size())
        {
            if(word1[i]==word2[j])
            {
                i++;
            }
            j++;
        }
        return i==word1.size();
    }
    int find(vector<string>&words,int index,int prev)
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
        if(prev==-1 || isPossible(words,prev,index))
        {
            take=1+find(words,index+1,index);
        }
        int skip=find(words,index+1,prev);
        if(prev!=-1)
        {
            return dp[index][prev]=max(take,skip);
        }
        return max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),[](string &a, string &b)
        {
            return a.size()<b.size();
        });
        return find(words,0,-1);
    }
};