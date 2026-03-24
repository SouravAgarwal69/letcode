class Solution {
public:
    bool isPossible(int mid,vector<int>&nums,int k)
    {
        int i=0,house=0;
        while(i<nums.size())
        {
            if(nums[i]<=mid)
            {
               house++;
               i+=2;
            }
            else
            {
                i++;
            }
        }
        return house>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int s=*min_element(nums.begin(),nums.end());
        int e=*max_element(nums.begin(),nums.end());
        int ans=e;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(mid,nums,k))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};