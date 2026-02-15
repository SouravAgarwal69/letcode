class Solution {
public:
   char find(string temp,char op)
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
      else
      {
         return temp.back()=='t'?'f':'t';
      }
   }
    bool parseBoolExpr(string expression) {
        string st;
       for(int i=0;i<expression.size();i++)
       {
          if(expression[i]==',')
          {
            continue;
          }
          else if(expression[i]==')')
          {
            string temp;
            while(st.back()!='(')
            {
                temp.push_back(st.back());
                st.pop_back();
            }
            st.pop_back();
            char op=st.back();
            st.pop_back();
            char res=find(temp,op);
            st.push_back(res);
          }
          else
          {
             st.push_back(expression[i]);
          }
       }
       return st.back()=='t'?true:false;
    }
};