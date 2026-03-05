class Solution {
public:
    bool isPossible(vector<int>&nums,int target)
    {
        vector<long long>temp(nums.begin(),nums.end());
        long long buffer=target-temp[0];
        for(int i=1;i<nums.size();i++)
        {
            temp[i]-=buffer;
            if(temp[i]>target)
            {
                return false;
            }
             buffer=target-temp[i];
        }
        return true;;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int s=nums[0],e=*max_element(nums.begin(),nums.end());
        int ans=e;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
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