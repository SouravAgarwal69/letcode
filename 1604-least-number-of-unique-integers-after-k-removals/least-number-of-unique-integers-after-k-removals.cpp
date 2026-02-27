class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        vector<int>freq(arr.size()+1);
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            freq[it->second]++;
        }
        int removed=0;
        for(int i=0;i<=arr.size();i++)
        {
            if(freq[i]==0)
            {
                continue;
            }
            while(i<=k && freq[i]>0)
            {
                removed++;
                freq[i]--;
                k-=i;
            }
        }
        return mp.size()-removed;
    }
};