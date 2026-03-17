class Solution {
public:
    bool isPossible(int Distance,vector<int>&nums,int k)
    {
        int pairs=0,i=0,j=0;
        while(j<nums.size())
        {
            while(nums[j]-nums[i]>Distance)
            {
                i++;
            }
            pairs+=j-i;
            j++;
        }
        return pairs>=k;
     }
   
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s=0,e=nums[nums.size()-1]-nums[0];
        int ans=e;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(mid,nums,k))
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