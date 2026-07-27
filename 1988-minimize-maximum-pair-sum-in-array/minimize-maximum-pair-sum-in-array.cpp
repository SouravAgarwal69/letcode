class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int minimum=INT_MIN;
         sort(nums.begin(),nums.end());
         int s=0,e=nums.size()-1;
       while(s<e)
        {
           minimum=max(nums[s]+nums[e],minimum);
           s++;
           e--;
        }
        return minimum;
    }
};