class Solution {
public:
    char find(char op,string &result)
    {
        if(op=='&')
        {
            for(int i=0;i<result.size();i++)
            {
                if(result[i]=='f')
                {
                    return 'f';
                }
            }
            return 't';
        }
        if(op=='|')
        {
            for(int i=0;i<result.size();i++)
            {
                if(result[i]=='t')
                {
                    return 't';
                }
            }
            return 'f';
        }
        else
        {
            if(result.back()=='t')
            {
                return 'f';
            }
            return 't';
        }
    }
    bool parseBoolExpr(string expression) {
        string result;
        for(int i=0;i<expression.size();i++)
        {
            if(!result.empty() && expression[i]==')')
            {
                string temp;
                while(result.back()!='(')
                {
                    temp.push_back(result.back());
                    result.pop_back();
                }
                result.pop_back();
                char op=result.back();
                result.pop_back();
                result.push_back(find(op,temp));
            }
            else
            {
                result.push_back(expression[i]);
            }
        }
        return result.back()=='t'?true:false;
    }
};