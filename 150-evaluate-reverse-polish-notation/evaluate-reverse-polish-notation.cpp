class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]==
            "/")
            {
                int e2=st.top();
                st.pop();
                int e1=st.top();
                st.pop();
                if(tokens[i]=="+")
                {
                st.push(e1+e2);
                }
                 if(tokens[i]=="-")
                {
                st.push(e1-e2);
                }
                 if(tokens[i]=="*")
                {
                st.push(e1*e2);
                }
                 if(tokens[i]=="/")
                {
                st.push(e1/e2);
                }
            }
            else
            {
                int val=stoi(tokens[i]);
                st.push(val);
            }
        }
        return st.top();
    }
};