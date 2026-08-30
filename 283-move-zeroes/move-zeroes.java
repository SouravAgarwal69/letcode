class Solution {
    public void moveZeroes(int[] nums) {
        ArrayList<Integer>temp1=new ArrayList<>();
        ArrayList<Integer>temp2=new ArrayList<>();
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]!=0)
            {
                temp1.add(nums[i]);
            }
            else
            {
                temp2.add(nums[i]);
            }
        }
        int idx=0;
        for(int i=0;i<temp1.size();i++)
        {
           nums[idx]=temp1.get(i);
           idx++;
        }
        for(int i=0;i<temp2.size();i++)
        {
            nums[idx]=temp2.get(i);
            idx++;
        }
    }
}