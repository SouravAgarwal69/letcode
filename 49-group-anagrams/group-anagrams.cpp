class Solution {
public:
    string construct(string temp)
    {
        string result;
        vector<int>charcter(26);
        for(int i=0;i<temp.size();i++)
        {
             charcter[temp[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            int cnt=charcter[i];
            while(cnt>0)
            {
                result.push_back(i+'a');
                cnt--;
            }
        }
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string temp=construct(strs[i]);
            mp[temp].push_back(strs[i]);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};