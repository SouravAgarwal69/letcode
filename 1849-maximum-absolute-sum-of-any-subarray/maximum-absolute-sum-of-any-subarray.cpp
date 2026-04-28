class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMinSum=nums[0],minSum=nums[0],maxSum=nums[0],currMaxSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            currMinSum=min(currMinSum+nums[i],nums[i]);
            minSum=min(minSum,currMinSum);
            currMaxSum=max(currMaxSum+nums[i],nums[i]);
            maxSum=max(maxSum,currMaxSum);
        }
        return max(abs(maxSum),abs(minSum));
    }
};