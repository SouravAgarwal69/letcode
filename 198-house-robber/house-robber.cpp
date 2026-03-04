class Solution {
public:
    int rob(vector<int>& nums) {
        int prevPrev=0,prev=nums[0],ans=prev;
        for(int i=1;i<nums.size();i++)
        {
            int skip=prev;
            int stashed=nums[i]+prevPrev;
            ans=max(skip,stashed);
            prevPrev=prev;
             prev=ans;
        }
        return ans;
    }
};