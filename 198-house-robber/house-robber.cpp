class Solution {
public:
    int rob(vector<int>& nums) {
        int prevPrev=0,prev=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
             int take=nums[i]+prevPrev;
             int skip=prev;
             ans=max(take,skip);
             prevPrev=prev;
             prev=ans;
        }
        return ans;
    }
};