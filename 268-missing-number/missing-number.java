class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int index=1,result=nums.length;
        for(int i=0;i<nums.length;i++)
        {
            if(i!=nums[index-1])
            {
                  result=i;
                  break;
            }
            index++;
        }
        return result;
    }
}