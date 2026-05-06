class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        long long res=0,num=0,sign=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+' || s[i]=='-')
            {
                res=res+num*sign;
                num=0;
                sign=s[i]=='+'?1:-1;
            }
           else if(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
            }
           else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                res=0;
                num=0;
                sign=1;
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
         return res;
    }
};