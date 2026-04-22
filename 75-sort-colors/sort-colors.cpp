class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ZeroCount=0,OneCount=0,twoCount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                ZeroCount++;
            }
            else if(nums[i]==1)
            {
                OneCount++;
            }
            else
            {
                twoCount++;
            }
        }
        int idx=0;
        while(ZeroCount>0)
        {
            nums[idx]=0;
            ZeroCount--;
            idx++;
        }
        while(OneCount>0)
        {
            nums[idx]=1;
            OneCount--;
            idx++;
        }
        while(twoCount>0)
        {
            nums[idx]=2;
            twoCount--;
            idx++;
        }
    }
};