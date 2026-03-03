class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
     if(nums.size()==1)
     {
        return nums[0];
     }
     if(nums[0]!=nums[1])
     {
        return nums[0];
     }
     if(nums[n-1]!=nums[n-2])
     {
        return nums[n-1];
     }
     int s=1,e=n-2;
     while(s<e)
     {
        int mid=s+(e-s)/2;
        bool isEven=(mid+1)%2==0;
        if(nums[mid]==nums[mid-1])
        {
            if(isEven)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        else if(nums[mid]==nums[mid+1])
        {
            if(isEven)
            {
               e=mid-1;
            }
            else
            {
               s=mid+1;
            }
        }
        else
        {
            return nums[mid];
        }
     }
     return nums[s];
    }
};