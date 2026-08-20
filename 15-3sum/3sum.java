class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>>list=new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length-2;i++)
        {
            if( i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int s=i+1,e=nums.length-1;
            while(s<e)
            {
                if(nums[s]+nums[e]==-nums[i])
                {
                    while(s<e && nums[s]==nums[s+1])
                    {
                        s++;
                    }
                    while(s<e && nums[e]==nums[e-1])
                    {
                        e--;
                    }
                    list.add(Arrays.asList(nums[i],nums[s],nums[e]));
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]>-nums[i])
                {
                   e--;
                }
                else
                {
                   s++;
                }
            }
        }
        return list;
    }
}