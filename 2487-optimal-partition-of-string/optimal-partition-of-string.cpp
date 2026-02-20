class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        int startIndex=0,partition=0;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=startIndex)
            {
                 partition++;
                 startIndex=i;
            }
            mp[s[i]]=i;
        }
        return partition+1;
    }
};