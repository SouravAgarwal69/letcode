class Solution {
public:
    bool isPossible(vector<int>&nums,int target)
    {
        vector<long long>temp(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(temp[i]>target)
            {
                return false;
            }
            long long buffer=target-temp[i];
            temp[i+1]=temp[i+1]-buffer;
        }
        return temp[temp.size()-1]<=target;
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