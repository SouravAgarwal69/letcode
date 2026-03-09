class Solution {
public:
    int find(vector<int>&nums,int s,int e)
    {
        int prevPrev=0,prev=nums[s],ans=nums[s];
        for(int i=s+1;i<=e;i++)
        {
           int take=nums[i]+prevPrev;
           int skip=prev;
           ans=max(skip,take);
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
        return max(find(nums,0,nums.size()-2),find(nums,1,nums.size()-1));
    }
};