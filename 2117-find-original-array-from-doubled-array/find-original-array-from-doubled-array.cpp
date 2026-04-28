class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>result;
        if(changed.size()%2!=0)
        {
            return {};
        }
        unordered_map<int,int>mp;
        sort(changed.begin(),changed.end());
        for(int i=0;i<changed.size();i++)
        {
            mp[changed[i]]++;
        }
        for(int i=0;i<changed.size();i++)
        {
            if(mp[changed[i]]>0)
            {
                if(mp[changed[i]*2]>0)
                {
                    mp[changed[i]]--;
                    mp[changed[i]*2]--;
                    result.push_back(changed[i]);
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