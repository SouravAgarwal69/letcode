class Solution {
    public int rob(int[] nums) {
        int prev=nums[0];
        int result=nums[0];
        int prevPrev=0;
        for(int i=1;i<nums.length;i++)
        {
            int skip=prev;
            int take=prevPrev+nums[i];
            result=Math.max(take,skip);
            prevPrev=prev;
            prev=result;
        }
        return result;
    }
}