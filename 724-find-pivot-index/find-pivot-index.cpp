class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum=0,cumSum=0,totalSum=0;
        for(int i=0;i<nums.size();i++)
        {
            totalSum+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            cumSum+=nums[i];
          int  rightSum=totalSum-cumSum;
            if(leftSum==rightSum)
            {
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};