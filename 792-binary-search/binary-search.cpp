class Solution {
public:
    int recursion(vector<int>&nums,int target,int s,int e)
    {
        if(s>e)
        {
            return -1;
        }
        int mid=s+(e-s)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]>target)
        {
            return recursion(nums,target,s,mid-1);
        }
        else
        {
            return recursion(nums,target,mid+1,e);
        }
    }
    int search(vector<int>& nums, int target) {
       return recursion(nums,target,0,nums.size()-1);
    }
};