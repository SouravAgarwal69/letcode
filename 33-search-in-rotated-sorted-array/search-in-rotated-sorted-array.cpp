class Solution {
public:
    int BS(int s,int e,vector<int>&nums,int target)
    {
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1,pivot=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]<=nums[n-1])
            {
                pivot=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        int find=BS(0,pivot-1,nums,target);
        if(find!=-1)
        {
            return find;
        }
        return BS(pivot,n-1,nums,target);
    }
};