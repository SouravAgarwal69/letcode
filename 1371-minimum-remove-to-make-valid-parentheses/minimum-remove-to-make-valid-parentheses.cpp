class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        vector<int>invalidIndex;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                continue;
            }
            else if(!invalidIndex.empty() && s[invalidIndex.back()]=='(' && s[i]==')')
            {
                invalidIndex.pop_back();
            }
           else
           {
              invalidIndex.push_back(i);
           }
        }
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(k<invalidIndex.size() && i==invalidIndex[k])
            {
                k++;
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};