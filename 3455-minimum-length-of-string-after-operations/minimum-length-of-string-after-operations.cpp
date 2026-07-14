class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        int deleted=0;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']==3)
            {
                freq[s[i]-'a']-=2;
                deleted+=2;
            }
        }
        return s.size()-deleted;
    }
};