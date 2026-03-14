class Solution {
public:
    bool isPossible(vector<int>&nums,int windowSize,long long k,vector<long long>&prefixSum)
    {
        int i=0,j=0;
        while(j<nums.size())
        {
            if(j-i+1==windowSize)
            {
                long long mid=i+(j-i)/2;
                long long leftOperation=0,leftSum=0;
                if(mid>0)
                {
                 leftSum=prefixSum[mid-1]-(i>0?prefixSum[i-1]:0);
                leftOperation=(mid-i)*nums[mid]-leftSum;
                }
                long long rightSum=prefixSum[j]-prefixSum[mid];
                long long rightOperation=rightSum-(j-mid)*nums[mid];
                if(leftOperation+rightOperation<=k)
                {
                    return true;
                }
                i++;
            }
            j++;
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        int s=1,e=nums.size();
        vector<long long>prefixSum(nums.size());
        prefixSum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        int ans=s;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(nums,mid,k,prefixSum))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};