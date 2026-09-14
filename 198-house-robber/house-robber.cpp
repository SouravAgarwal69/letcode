class Solution {
public:
    int solve(vector<int>&nums,vector<int>&result,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
         if(result[index]!=-1)
         {
            return result[index];
         }
        int take=nums[index]+solve(nums,result,index+2);
        int skip=solve(nums,result,index+1);
        return result[index]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,-1);
        return solve(nums,result,0);
    }
};