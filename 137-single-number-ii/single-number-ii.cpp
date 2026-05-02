class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<32;k++)
        {
            int temp=1<<k;
            int cntOne=0;
            for(int i=0;i<nums.size();i++)
            {
                int bit=(temp & nums[i]);
                if(bit!=0)
                {
                    cntOne++;
                }
            }
            if(cntOne % 3!=0)
            {
                result=result | temp;
            }
        }
        return result;
    }
};