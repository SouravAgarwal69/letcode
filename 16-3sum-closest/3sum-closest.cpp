class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minimum=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(minimum>abs(target-(nums[i]+nums[j]+nums[k])))
                    {
                      minimum=min(minimum,abs(target-(nums[i]+nums[j]+nums[k])));
                      ans=nums[i]+nums[j]+nums[k];
                    }
                }
            }
        }
        return ans;
    }
};