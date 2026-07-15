class Solution {
public:
    char calculate(string temp,char op)
    {
        if(op=='|')
        {
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]=='t')
                {
                    return 't';
                }
            }
            return 'f';
        }
        else if(op=='&')
        {
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]=='f')
                {
                    return 'f';
                }
            }
            return 't';
        }
        return temp.back()=='t'?'f':'t';
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i]==',')
            {
                 continue;
            }
            else if(expression[i]==')')
            {
                string temp;
                while(!st.empty() && st.top()!='(')
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(calculate(temp,op));
            }
            else
            {
                st.push(expression[i]);
            }
        }
         return st.top()=='t';
    }
};