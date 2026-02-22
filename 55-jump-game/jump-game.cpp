class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxEnd=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>maxEnd)
            {
                return false;
            }
           
            maxEnd=max(maxEnd,nums[i]+i);
        }
        return true;
    }
};