class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0)
        {
            return false;
        }
        stack<int>flexible;
        stack<int>open;
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
            else if(s[i]==')' && !open.empty())
            {
                open.pop();
            }
            else if(s[i]==')' && !flexible.empty())
            {
                flexible.pop();
            }
            else
            {
                return false;
            }
        }
        while(!open.empty() && !flexible.empty())
        {
            if(open.top()>flexible.top())
            {
                 return false;
            }
            open.pop();
            flexible.pop();
        }
        return open.empty();
    }
};