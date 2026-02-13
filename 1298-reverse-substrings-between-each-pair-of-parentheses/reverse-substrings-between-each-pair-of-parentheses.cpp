class Solution {
public:
    string reverseParentheses(string s) {
        vector<int>v(s.size());
        stack<int>st;
        string result;
        for(int i=0;i<s.size();i++)
        {
             if(s[i]=='(')
             {
                st.push(i);
             }
             else if(s[i]==')')
             {
                int j=st.top();
                st.pop();
                v[i]=j;
                v[j]=i;
             }
        }
        int direction=1;
        for(int i=0;i<s.size();i+=direction)
        {
            if(s[i]=='(' || s[i]==')')
            {
                i=v[i];
                direction=-direction;
            }
            else
            {
                 result.push_back(s[i]);
            }
        }
       return result;
    }
};