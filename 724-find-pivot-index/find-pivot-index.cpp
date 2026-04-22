class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int totalSum=0;
       for(int i=0;i<nums.size();i++)
       {
        totalSum+=nums[i];
       } 
       int cummSum=0;
       for(int i=0;i<nums.size();i++)
       {
          cummSum+=nums[i];
          int leftSum=cummSum-nums[i];
          int rightSum=totalSum-cummSum;
          if(leftSum==rightSum)
          {
            return i;
          }
       }
       return -1;
    }
};