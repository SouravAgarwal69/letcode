class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int target_index=-1,n=nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                target_index=i;
                break;
            }
        }
        if(target_index!=-1)
        {
            for(int i=n-1;i>target_index;i--)
            {
                if(nums[i]>nums[target_index])
                {
                    swap(nums[i],nums[target_index]);
                    break;
                }
            }
        }
        reverse(nums.begin()+target_index+1,nums.end());
     
    }
};