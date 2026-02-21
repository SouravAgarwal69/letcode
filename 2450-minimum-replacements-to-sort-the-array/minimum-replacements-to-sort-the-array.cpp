class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int size=nums.size();
        long long result=0,prev=nums[size-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
               if(prev<nums[i])
               {
                   int parts=nums[i]/prev;
                   if(nums[i]%prev!=0)
                   {
                      parts++;
                   }
                prev=nums[i]/parts;
                   result+=parts-1;
               }
               else
               {
                  prev=nums[i];
               }
        }
        return result;
    }
};