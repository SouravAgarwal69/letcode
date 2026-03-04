class Solution {
public:
    int find(int s,int e,vector<int>&nums,vector<int>&dp)
    {
       int prevPrev=0,prev=nums[s],ans=nums[s];
       for(int i=s+1;i<=e;i++)
       {
           int skip=prev;
           int stashed=nums[i]+prevPrev;
           ans=max(skip,stashed);
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
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        return max(find(0,nums.size()-2,nums,dp1),find(1,nums.size()-1,nums,dp2));
    }
};