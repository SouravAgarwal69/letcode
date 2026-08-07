class Solution {
public:
    void SortIt(string str,unordered_map<string,vector<string>>&mp)
    {
        vector<int>freq(26,0);
        for(int i=0;i<str.size();i++)
        {
            freq[str[i]-'a']++;
        }
        string temp;
        for(int i=0;i<26;i++)
        {
            while(freq[i]>0)
            {
                temp.push_back(i+'a');
                freq[i]--;
            }
        }
        mp[temp].push_back(str);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            SortIt(strs[i],mp);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};