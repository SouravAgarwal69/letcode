class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result;
        int open=0,close=0;
        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='(')
           {
             open++;
           }
           else if(s[i]==')' && open>0)
           {
               open--;
           }
           else if((s[i]==')' && open==0))
           {
               continue;
           }
           result.push_back(s[i]);
        }
        open=0;
        close=0;
        string ans;
        for(int i=result.size()-1;i>=0;i--)
        {
             if(result[i]=='(')
             {
                if(close==0)
                {
                    continue;
                }
                else
                {
                    close--;
                }
             }
             else if(result[i]==')')
             {
                close++;
             }
             ans.push_back(result[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};