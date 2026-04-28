class Solution {
public:
    int kandaneMax(vector<int>&nums)
    {
        int sum=nums[0],maximum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum=max(sum+nums[i],nums[i]);
            maximum=max(maximum,sum);
        }
        return maximum;
    }
    int kandaneMin(vector<int>&nums)
    {
        int sum=nums[0],minimum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum=min(sum+nums[i],nums[i]);
            minimum=min(minimum,sum);
        }
        return minimum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int Total=0;
        for(int i=0;i<nums.size();i++)
        {
            Total+=nums[i];
        }
        int maxSum=kandaneMax(nums);
        int minSum=kandaneMin(nums);
        int CircularSum=Total-minSum;
        if(CircularSum>0)
        {
            return max(CircularSum,maxSum);
        }
        return maxSum;
    }
};