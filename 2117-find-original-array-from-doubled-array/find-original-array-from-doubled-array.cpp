class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0)
        {
            return {};
        }
        sort(changed.begin(),changed.end());
        vector<int>result;
        unordered_map<int,int>mp;
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