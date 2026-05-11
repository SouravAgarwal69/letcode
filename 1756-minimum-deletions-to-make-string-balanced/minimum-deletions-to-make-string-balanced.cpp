class Solution {
public:
    int minimumDeletions(string s) {
        int cnt=0;
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(!result.empty() && result.back()=='b' && s[i]=='a')
            {
                result.pop_back();
                cnt++;
            }
            else
            {
                result.push_back(s[i]);
            }
        }
        return cnt;
    }
};