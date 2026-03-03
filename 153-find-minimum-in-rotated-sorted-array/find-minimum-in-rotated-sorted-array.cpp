class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,ans=0;
        int n=nums.size();
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]<=nums[n-1])
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
               s=mid+1;
            }
        }
        return nums[ans];
    }
};