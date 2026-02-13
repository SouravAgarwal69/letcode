class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(result.size());
            }
            else if(s[i]==')')
            {
                int start=st.top();
                st.pop();
                reverse(result.begin()+start,result.end());
            }
            else
            {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};