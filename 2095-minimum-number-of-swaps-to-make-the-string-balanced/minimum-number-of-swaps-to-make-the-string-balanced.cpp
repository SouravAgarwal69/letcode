class Solution {
public:
    int minSwaps(string s) {
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(!ans.empty() && s[i]==']')
            {
                ans.pop_back();
            }
            else if(s[i]=='[')
            {
                ans.push_back(s[i]);
            }
        }
        return (ans.size()+1)/2;
    }
};