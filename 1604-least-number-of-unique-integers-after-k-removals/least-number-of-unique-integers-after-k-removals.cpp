class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        vector<pair<int,int>>vp;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vp.push_back(make_pair(it->second,it->first));
        }
        sort(vp.begin(),vp.end());
        int remove=0;
        for(int i=0;i<vp.size();i++)
        {
            if(vp[i].first<=k)
            {
                k-=vp[i].first;
                remove++;
            }
        }
        return vp.size()-remove;
    }
};