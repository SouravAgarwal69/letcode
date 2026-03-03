class Solution {
public:
    int findLast(vector<int>&nums,int target,int s,int e)
    {
        int index=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                index=mid;
                s=mid+1;
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
        return index;
    }
    int findFirst(vector<int>&nums,int target,int s,int e)
    {
        int index=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                index=mid;
                e=mid-1;
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
        return index;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findFirst(nums,target,0,nums.size()-1);
        int second=findLast(nums,target,0,nums.size()-1);
        return {first,second};
    }
};