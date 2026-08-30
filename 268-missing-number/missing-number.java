class Solution {
    public int missingNumber(int[] nums) {
        int n=nums.length,total=0;
        int sum_n=n*(n+1)/2;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
        }
        return sum_n-total;
    }
}