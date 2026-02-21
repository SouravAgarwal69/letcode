class Solution {
public:
    int calculate(string s) {
        long long result=0,sign=1;
        stack<int>st;
        long long num=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                result+=num*sign;
                int prevSign=st.top();
                st.pop();
                int prevVal=st.top();
                st.pop();
                result=prevSign*result+prevVal;
                num=0;
            }
            else if (isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                result+=num*sign;
                sign=s[i]=='+'?1:-1;
                num=0;
            }
        }
        result+=num*sign;
        return result;
    }
};