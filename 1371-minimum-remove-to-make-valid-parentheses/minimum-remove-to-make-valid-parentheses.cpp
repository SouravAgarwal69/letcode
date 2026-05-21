class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int>skip;
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                continue;
            }
            if(!skip.empty() && s[i]==')' && s[skip.back()]=='(')
            {
                skip.pop_back();
            }
            else
            {
                skip.push_back(i);
            }
        }
        int j=0;
       for(int i=0;i<s.size();i++)
       {
          if(j<skip.size() && i==skip[j])
          {
            j++;
          }
          else
          {
             result.push_back(s[i]);
          }
       }
       return result;
    }
};