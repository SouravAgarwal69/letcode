class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            int s=i+1,e=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            while(s<e)
            {
                if(nums[s]+nums[e]==-nums[i])
                {
                     result.push_back({nums[i],nums[s],nums[e]});
                        s++;
                        e--;
                    while( s<e && nums[s]==nums[s-1])
                    {
                       s++;
                    }
                    while(s<e && nums[e]==nums[e+1])
                    {
                        e--;
                    }
                }
                else if(nums[s]+nums[e]<-nums[i])
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
        return result;
    }
};