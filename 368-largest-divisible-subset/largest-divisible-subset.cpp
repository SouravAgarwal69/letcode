class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>result;
        vector<int>prev(nums.size(),-1);
        vector<int>dp(nums.size(),1);
        int maxIndex=0,maxValue=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
               if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
               {
                  dp[i]=dp[j]+1;
                  prev[i]=j;
               }
            }
            if(maxValue<dp[i])
            {
                maxValue=dp[i];
                maxIndex=i;
            }
        }
       result.push_back(nums[maxIndex]);
       while(prev[maxIndex]!=-1)
       {
          result.push_back(nums[prev[maxIndex]]);
          maxIndex=prev[maxIndex];
       }
       return result;
    }
};