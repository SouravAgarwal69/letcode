class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            if(nums[e]==val)
            {
                nums.pop_back();
                e--;
            }
            else if(nums[s]==val)
            {
                swap(nums[s],nums[e]);
                s++;
            }
            else
            {
                s++;
            }
        }
        return nums.size();
    }
};