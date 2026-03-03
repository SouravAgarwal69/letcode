class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(s<e)
        {
            while(s<e && nums[s]==nums[s+1])
            {
                 s++;
            }
            while(s<e && nums[e]==nums[e-1])
            {
                e--;
            }
             int mid=s+(e-s)/2;
             if(nums[mid]<=nums[e])
             {
                 e=mid;
             }
             else
             {
                s=mid+1;
             }
        }
        return nums[s];
    }
};