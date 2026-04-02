class Solution {
public:
    void fun(string &s,vector<vector<string>>&result,vector<string>&ans,vector<vector<bool>>&mat,int index)
    {
        if(index==s.size())
        {
            result.push_back(ans);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            string temp=s.substr(index,i-index+1);
            if(mat[index][i])
            {
                ans.push_back(temp);
                fun(s,result,ans,mat,i+1);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>ans;
        vector<vector<bool>>mat(s.size(),vector<bool>(s.size()));
        for(int L=1;L<=s.size();L++)
        {
            for(int i=0;i+L-1<s.size();i++)
            {
                int j=i+L-1;
                if(L==1)
                {
                    mat[i][j]=true;
                }
                else if(L==2)
                {
                    mat[i][j]=(s[i]==s[j]);
                }
                else
                {
                    mat[i][j]=(s[i]==s[j] && mat[i+1][j-1]);
                }
            }
        }
        fun(s,result,ans,mat,0);
        return result;
    }
};