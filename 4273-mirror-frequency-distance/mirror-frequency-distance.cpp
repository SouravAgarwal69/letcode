class Solution {
public:
    int mirrorFrequency(string s) {
        int ans=0;
        unordered_map<char,int>mp;
        unordered_set<char>st;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(st.find(s[i])==st.end())
            {
                char m;
                if(s[i]>='0' && s[i]<='9')
                {
                     m='0'+('9'-s[i]);
                }
                else
                {
                    m='a'+('z'-s[i]);
                }
                 ans+=abs(mp[s[i]]-mp[m]);
                st.insert(s[i]);
                st.insert(m);
            }
        }
        return ans;
    }
};