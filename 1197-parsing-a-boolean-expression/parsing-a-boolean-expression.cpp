class Solution {
public:
    char find(char op,string temp)
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
            for(int j=0;j<temp.size();j++)
            {
                if(temp[j]=='f')
                {
                    return 'f';
                }
            }
            return 't';
        }
        else
        {
           return temp.back()=='t'?'f':'t';
        }
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
                    char ch=find(op,temp);
                    st.push(ch);
                }
                else
                {
                    st.push(expression[i]);
                }
            }
            return st.top()=='t'?true:false;
    }
};