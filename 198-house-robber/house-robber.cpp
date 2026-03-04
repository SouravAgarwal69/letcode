class Solution {
public:
    int rob(vector<int>& nums) {
        int PrevPrev=0,Prev=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int skip=Prev;
            int take=PrevPrev+nums[i];
            ans=max(skip,take);
            PrevPrev=Prev;
            Prev=ans;
        }
        return ans;
    }
};