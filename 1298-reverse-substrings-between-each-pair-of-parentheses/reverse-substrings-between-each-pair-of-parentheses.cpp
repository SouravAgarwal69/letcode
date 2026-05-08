class Solution {
public:
    string reverseParentheses(string s) {
        vector<int>index;
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                index.push_back(result.size());
            }
            else if(s[i]==')')
            {
                reverse(result.begin()+index.back(),result.end());
                index.pop_back();
            }
            else
            {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};