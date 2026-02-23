class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,currEnd=0,maxEnd=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>currEnd)
            {
                jumps++;
                currEnd=maxEnd;
            }
            maxEnd=max(maxEnd,nums[i]+i);
        }
        return jumps;
    }
};