class Solution {
public:
    void sortColors(vector<int>& nums) {
       int cntZero=0,cntOne=0,cntTwo=0;
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
       int i=0;
       while(i<nums.size())
       {
           while(cntZero>0)
           {
               nums[i]=0;
               i++;
               cntZero--;
           }
           while(cntOne>0)
           {
              nums[i]=1;
              i++;
              cntOne--;
           }
           while(cntTwo>0)
           {
             nums[i]=2;
             i++;
             cntTwo--;
           }
       }
    }
};