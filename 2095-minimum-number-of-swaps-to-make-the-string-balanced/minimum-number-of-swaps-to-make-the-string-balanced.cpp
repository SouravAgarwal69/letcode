class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && st.top()=='[' && s[i]==']')
            {
                st.pop();
            }
            else if(s[i]=='[')
            {
                st.push(s[i]);
            }
        }
        return st.empty()?0:(st.size()+1)/2;
    }
};