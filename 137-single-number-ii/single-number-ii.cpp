class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<32;k++)
        {
           int temp=1<<k;
           int cntZero=0,cntOne=0;
        for(int i=0;i<nums.size();i++)
        {
            int bit=nums[i] & temp;
            if(bit==0)
            {
                cntZero++;
            }
          else
            {
                cntOne++;
            }
        }
          if(cntOne%3!=0)
          {
             result=result | temp;
          }
        }
        return result;
    }
};