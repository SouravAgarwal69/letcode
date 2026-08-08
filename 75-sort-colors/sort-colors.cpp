class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cntOne=0,cntZero=0,cntTwo=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                cntZero++;
            }
            else if(nums[i]==1)
            {
                cntOne++;
            }
            else 
            {
                cntTwo++;
            }
        }
        int index=0;
        while(cntZero--)
        {
            nums[index]=0;
            index++;
        }
        while(cntOne--)
        {
            nums[index]=1;
            index++;
        }
        while(cntTwo--)
        {
            nums[index]=2;
            index++;
        }
    }
};