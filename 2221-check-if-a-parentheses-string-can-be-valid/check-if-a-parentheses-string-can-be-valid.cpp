class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0)
        {
            return false;
        }
        stack<int>open;
        stack<int>flexible;
        for(int i=0;i<s.size();i++)
        {
           if(locked[i]=='0')
           {
               flexible.push(i);
           }
           else if(s[i]=='(')
           {
            open.push(i);
           }
           else if(s[i]==')')
           {
                if(!open.empty())
                {
                    open.pop();
                }
                else if(!flexible.empty())
                {
                    flexible.pop();
                }
                else
                {
                    return false;
                }
           }
        }
        while(!open.empty() && !flexible.empty())
        {
            if(flexible.top()<open.top())
            {
                return false;
            }
            open.pop();
            flexible.pop();
        }
        return open.empty();
    }
};