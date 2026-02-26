class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int operations=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==1)
            {
                return -1;
            }
            operations+=ceil((float)it->second/3);
        }
        return operations;
    }
};