class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>first;
        for(int i=0;i<nums.size();i++)
        {
            first[nums[i]]++;
        }
        unordered_map<int,int>second;
        for(auto it=first.begin();it!=first.end();it++)
        {
           second[it->second]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(second[first[nums[i]]]==1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};