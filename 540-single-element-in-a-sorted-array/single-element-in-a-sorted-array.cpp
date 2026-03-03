class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int element,n=nums.size();
        if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2])
        {
            return nums[n-1];
        }
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1])
            {
                element=nums[i];
                break;
            }
        }
        return element;
    }
};