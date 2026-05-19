class Solution {
public:
    int calculate(string s) {
        long long res=0,num=0,sign=1;
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                 st.push(res);
                 st.push(sign);
                 res=0;
                 num=0;
                 sign=1;
            }
            else if(isdigit(s[i]))
            {
                num=num*10+s[i]-'0';
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                res=res+num*sign;
                sign=s[i]=='+'?1:-1;
                num=0;
            }
            else if(s[i]==')')
            {
                res=res+num*sign;
                int prevSign=st.top();
                st.pop();
                int prevVal=st.top();
                st.pop();
                res=prevVal+res*prevSign;
                num=0;
            }
        }
        res=res+num*sign;
        return (int)res;
    }
};