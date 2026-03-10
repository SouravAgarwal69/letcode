class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int s=i+1,e=nums.size()-1;
            while(s<e)
            {
                if( nums[s]+nums[e]==-nums[i])
                {
                 while(s<e && nums[s]==nums[s+1])
                {
                    s++;
                }
                while(s<e && nums[e]==nums[e-1])
                {
                    e--;
                }
                    ans.push_back({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]>-nums[i])
                {
                    e--;
                }
                else
                {
                    s++;
                }
            }  
        }
        return ans;
    }
};