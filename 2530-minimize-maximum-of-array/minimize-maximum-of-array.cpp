class Solution {
public:
    bool isPossible(vector<int>&temp,long long target)
    {
        vector<long long>nums(temp.begin(),temp.end());
        long long buffer=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>target)
            {
                return false;
            }
            buffer=target-nums[i];
            nums[i+1]=nums[i+1]-buffer;
        }
        return nums[nums.size()-1]<=target;
    }
    int minimizeArrayValue(vector<int>& nums) {
        long long s=*min_element(nums.begin(),nums.end());
      long long e=*max_element(nums.begin(),nums.end());
       long long ans=e;
        while(s<=e)
        {
           long long mid=s+(e-s)/2;
            if(isPossible(nums,mid))
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