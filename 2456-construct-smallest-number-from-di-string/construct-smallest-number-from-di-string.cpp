class Solution {
public:
    string smallestNumber(string pattern) {
        string result;
        stack<int>st;
        int cnt=0;
        for(int i=0;i<=pattern.size();i++)
        {
           cnt++;
           st.push(cnt);
           if(pattern[i]=='I' || i==pattern.size())
           {
                while(!st.empty())
                {
                    result.push_back(st.top()+'0');
                    st.pop();
                }
           }
        }
        return result;
    }
};