class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0)
        {
            return {};
        }
        vector<int>result;
        sort(changed.begin(),changed.end());
        unordered_map<int,int>mp;
        for(int i=0;i<changed.size();i++)
        {
            mp[changed[i]]++;
        }
        sort(changed.begin(),changed.end());
        for(int i=0;i<changed.size();i++)
        {
            if(mp[changed[i]]>0)
            {
                if(mp[2*changed[i]]>0)
                {
                    result.push_back(changed[i]);
                    mp[changed[i]]--;
                    mp[changed[i]*2]--;
                }
                else
                {
                    return {};
                }
            }
        }
        return result;
    }
};