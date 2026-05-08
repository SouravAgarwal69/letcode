class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        stack<int>st;
        vector<int>store(s.size());
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                store[i]=st.top();
                store[st.top()]=i;
                st.pop();
            }
        }
       int direction=1;
       for(int i=0;i<s.size();i+=direction)
       {
           if(s[i]=='(' || s[i]==')')
           {
                 i=store[i];
                 direction=-1*direction;
           }
           else
           {
               result.push_back(s[i]);
           }
       }
       return result;
    }
};