class Solution {
public:
    int calculate(string s) {
        int result=0,sign=1;
        long long num=0;
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                result=result+num*sign;
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
                num=0;
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                result+=num*sign;
                num=0;
                sign=s[i]=='+'?1:-1;
            }
            else if(isdigit(s[i]))
            {
                num=num*10+s[i]-'0';
            }
            else if(s[i]==')')
            {
                result+=num*sign;
                int prevSign=st.top();
                st.pop();
                int prevVal=st.top();
                st.pop();
                result=result*prevSign+prevVal;
                num=0;
                sign=1;
            }
        }
        result=result+num*sign;
        return result;
    }
};