class Solution {
    public int missingNumber(int[] nums) {
        HashSet<Integer>set=new HashSet<>();
        for(int i=0;i<nums.length;i++)
        {
            set.add(nums[i]);
        }
        int result=0;
        for(int i=0;i<=nums.length;i++)
        {
            if(!set.contains(i))
            {
                result=i;
                break;
            }
        }
        return result;
    }
}