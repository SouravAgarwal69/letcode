class Solution {
public:
    long long find(int target,vector<int>&nums,vector<int>&cost)
    {
        long long result=0;
        for(int i=0;i<nums.size();i++)
        {
            result+=1LL*abs(nums[i]-target)*cost[i];
        }
        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int s=*min_element(nums.begin(),nums.end());
        int e=*max_element(nums.begin(),nums.end());
        long long ans=INT_MAX;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            long long c1=find(mid,nums,cost);
            long long c2=find(mid+1,nums,cost);
            if(c1<=c2)
            {
                ans=c1;
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