class Solution {
public:
    int calculate(vector<int>&nums,int s,int e)
    {
        int prevPrev=0,prev=nums[s],ans=nums[s];
        for(int i=s+1;i<=e;i++)
        {
            int take=prevPrev+nums[i];
            int skip=prev;
            ans=max(take,skip);
            prevPrev=prev;
            prev=ans;
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        return max(calculate(nums,0,nums.size()-2),calculate(nums,1,nums.size()-1));
    }
};