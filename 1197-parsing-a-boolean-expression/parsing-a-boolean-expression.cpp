class Solution {
public:
    char find(string res,char op)
    {
         if(op=='|')
         {
            for(int i=0;i<res.size();i++)
            {
                if(res[i]=='t')
                {
                    return 't';
                }
            }
            return 'f';
         }
         else if(op=='&')
         {
            for(int i=0;i<res.size();i++)
            {
                if(res[i]=='f')
                {
                    return 'f';
                }
            }
            return 't';
         }
         else
         {
            return res.back()=='t'?'f':'t';
         }
    }
    bool parseBoolExpr(string expression) {
        string temp;
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i]==',')
            {
               continue;
            }
            else if(expression[i]==')')
            {
                string res;
                while(temp.back()!='(')
                {
                    res.push_back(temp.back());
                    temp.pop_back();
                }
                temp.pop_back();
                char op=temp.back();
                temp.pop_back();
                temp.push_back(find(res,op));
            }
            else
            {
                temp.push_back(expression[i]);
            }
        }
        return temp.back()=='t'?true:false;
    }
};