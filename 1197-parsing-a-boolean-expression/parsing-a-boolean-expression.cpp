class Solution {
public:
    char find(char op,string expression)
    {
        if(op=='&')
        {
            for(int i=0;i<expression.size();i++)
            {
                if(expression[i]=='f')
                {
                    return 'f';
                }
            }
            return 't';
        }
        else if(op=='|')
        {
            for(int i=0;i<expression.size();i++)
            {
                if(expression[i]=='t')
                {
                    return 't';
                }
            }
            return 'f';
        }
        return expression.back()=='t'?'f':'t';
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i]==',')
            {
                continue;
            }
            if(expression[i]==')')
            {
                string expression;
                while(  st.top()!='(')
                {
                    expression.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(find(op,expression));
            }
            else
            {
                st.push(expression[i]);
            }
        }
        return st.top()=='t';
    }
};