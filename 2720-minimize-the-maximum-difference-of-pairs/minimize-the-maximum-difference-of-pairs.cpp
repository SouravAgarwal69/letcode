class Solution {
public:
    bool isPossible(vector<int>&nums,int target, int p)
    {
        int pairs=0,i=0;
        while(i<nums.size()-1)
        {
            if(nums[i+1]-nums[i]<=target)
            {
                pairs++;
                i+=2;
            }
            else
            {
                i++;
            }
            if(pairs>=p)
            {
                return true;
            }
        }
        return pairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int s=0,e=nums[nums.size()-1]-nums[0];
        int ans=e;
        while(s<=e)
      {
           int mid=s+(e-s)/2;
           if(isPossible(nums,mid,p))
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