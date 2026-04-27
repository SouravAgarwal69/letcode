class Solution {
public:
    string findSort(string temp)
    {
        vector<int>freq(26,0);
        for(int i=0;i<temp.size();i++)
        {
            freq[temp[i]-'a']++;
        }
        string ptr;
        for(int i=0;i<26;i++)
        {
            int cnt=freq[i];
            while(cnt>0)
            {
                ptr.push_back(i+'a');
                cnt--;
            }
        }
        return ptr;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string temp=findSort(strs[i]);
            mp[temp].push_back(strs[i]);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};