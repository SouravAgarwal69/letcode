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
            else if(s[i]==')')
            {
                if(open>0)
                {
                    open--;
                }
                else
                {
                    continue;
                }
            }
            result.push_back(s[i]);
        }
        string temp;
        for(int i=result.size()-1;i>=0;i--)
        {
            if(result[i]==')')
            {
                close++;
            }
            else if(result[i]=='(' )
            {
                if(close>0)
                {
                   close--;
                }
                else
                {
                    continue;
                }
            }
           temp.push_back(result[i]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};