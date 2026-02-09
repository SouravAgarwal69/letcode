class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int result=0,sign=1;
        long long num=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='-' || s[i]=='+')
            {
                result+=num*sign;
                num=0;
                sign=s[i]=='-'?-1:1;
            }
            if(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
            }
            if(s[i]=='(')
            {
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
                num=0;
            }
            if(s[i]==')')
            {
                result+=num*sign;
                num=0;
                int prev_sign=st.top();
                st.pop();
                int prev_val=st.top();
                st.pop();
                result=prev_val+prev_sign*result;
            }
        }
        result+=sign*num;
        return result;
    }
};