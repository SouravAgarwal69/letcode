class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        stringstream ss(path);
        string temp;
        while(getline(ss,temp,'/'))
        {
            if(temp=="" || temp==".")
            {
                continue;
            }
            else if(temp=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(temp);
            }
        }
        if(st.empty())
        {
            return "/";
        }
        string result;
        while(!st.empty())
        {
           result="/"+st.top()+result;
           st.pop();
        }
        return result;
    }
};