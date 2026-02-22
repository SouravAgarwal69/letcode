class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currEnd=0,maxEnd=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>maxEnd)
            {
                return false;
            }
            if(i>currEnd)
            {
                currEnd=maxEnd;
            }
            maxEnd=max(maxEnd,nums[i]+i);
        }
        return true;
    }
};