class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num=0;
        for(int k=0;k<32;k++)
        {
            int cntOne=0;
            int temp=1<<k;
            for(int i=0;i<nums.size();i++)
            {
                if((nums[i] & temp)!=0)
                {
                    cntOne++;
                }
            }
            if((cntOne % 3)!=0)
            {
                 num=num | temp;
            }
        }
        return num;
    }
};