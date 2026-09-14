class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        int prevPrev=0,prev=nums[0];
        result[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int take=prevPrev+nums[i];
            int skip=prev;
            result[i]=max(take,skip);
            prevPrev=prev;
            prev=result[i];
        }
        return result[n-1];
    }
};