class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long operation=0,prev=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
              if(prev<nums[i])
              {
                int parts=nums[i]/prev;
                if(nums[i] % prev!=0)
                {
                     parts++;
                }
                prev=nums[i]/parts;
                operation+=parts-1;
              }
              else
              {
                prev=nums[i];
              }
        }
        return operation;
    }
};