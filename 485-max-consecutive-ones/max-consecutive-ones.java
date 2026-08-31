class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maximum=0,prevIndex=-1;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==0)
            {
                prevIndex=i;
            }
            else
            {
                maximum=Math.max(maximum,i-prevIndex);
            }
        }
        return maximum;
    }
}