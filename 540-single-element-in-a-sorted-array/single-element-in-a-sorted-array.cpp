class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
     int s=0,e=n-1;
     while(s<e)
     {
        int mid=s+(e-s)/2;
        bool isEven=(mid+1)%2==0;
        if(mid-1>=0 && nums[mid]==nums[mid-1])
        {
            if(isEven)
            {
                s=mid+1;
            }
            else
            {
                e=mid-2;
            }
        }
        else if( mid+1<n && nums[mid]==nums[mid+1])
        {
            if(isEven)
            {
               e=mid-1;
            }
            else
            {
               s=mid+2;
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