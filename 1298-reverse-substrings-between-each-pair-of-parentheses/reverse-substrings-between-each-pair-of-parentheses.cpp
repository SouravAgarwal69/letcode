class Solution {
public:
    string reverseParentheses(string s) {
        vector<int>mp(s.size());
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            if(s[i]==')')
            {
                mp[i]=st.top();
                mp[st.top()]=i;
                st.pop();
            }
        }
        int direction=1;
        string result;
        for(int i=0;i<s.size();i+=direction)
        {
            if(s[i]=='(' || s[i]==')')
            {
                i=mp[i];
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