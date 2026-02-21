class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,currEnd=0,maxEnd=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>currEnd)
            {
                jump++;
                currEnd=maxEnd;
            }
            maxEnd=max(maxEnd,nums[i]+i);
        }
        return jump;
    }
};