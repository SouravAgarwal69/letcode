class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>>result=new ArrayList<>();
        Arrays.sort(nums);
        int n=nums.length;
        for(int i=0;i<nums.length;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int s=i+1,e=n-1;
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
                    result.add(Arrays.asList(nums[i],nums[s],nums[e]));
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]<-nums[i])
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
        return result;
    }
}