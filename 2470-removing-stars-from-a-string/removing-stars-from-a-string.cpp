class Solution {
public:
    string removeStars(string s) {
        string ans;
        vector<char>vec(s.size());
        int j=0;
        for(int i=0;i<s.size();i++)
        { 
            if(s[i]=='*')
            {
                j--;
            }
            else
            {
                vec[j]=s[i];
                j++;
            }
        }
        for(int i=0;i<j;i++)
        {
              ans.push_back(vec[i]);
        }
        return ans;
    }
};