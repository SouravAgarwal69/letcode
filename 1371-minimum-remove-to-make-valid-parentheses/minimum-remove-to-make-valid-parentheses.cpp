class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int>skip;
        for(int i=0;i<s.size();i++)
        {
            if(!skip.empty() && s[skip.back()]=='(' && s[i]==')')
            {
                skip.pop_back();
            }
            else if(s[i]=='(' || s[i]==')')
            {
                skip.push_back(i);
            }
        }
        int k=0;
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(k<skip.size() && i==skip[k])
            {
                k++;
            }
            else
            {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};