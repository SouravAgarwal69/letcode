class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int open=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else if(s[i]==')' && open==0)
            {
                 continue;
            }
            else if(s[i]==')' && open>0)
            {
                open--;
            }
           ans.push_back(s[i]);
        }
        string result;
        int close=0;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]==')')
            {
                close++;
            }
            else if(ans[i]=='(' &&  close>0 )
            {
                close--;
            }
            else if(ans[i]=='(' && close==0)
            {
                continue;
            }
            result.push_back(ans[i]);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};