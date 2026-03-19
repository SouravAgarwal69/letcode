class Solution {
public:
    bool isPossible(int target,vector<int>&nums,int maxOperations)
    {
        long long operation=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%target==0)
            {
                operation+=(nums[i]/target)-1;
            }
            else
            {
                operation+=nums[i]/target;
            }
        }
        return operation<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s=1,e=*max_element(nums.begin(),nums.end());
        int ans=e;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(mid,nums,maxOperations))
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