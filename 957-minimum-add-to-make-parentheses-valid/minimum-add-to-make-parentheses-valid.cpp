class Solution {
public:
    int minAddToMakeValid(string s) {
        int ExtraOpen=0,ExtraClose=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                ExtraOpen++;
            }
            else
            {
                if(ExtraOpen>0)
                {
                    ExtraOpen--;
                }
                else
                {
                    ExtraClose++;
                }
            }
        }
        return ExtraOpen+ExtraClose;
    }
};