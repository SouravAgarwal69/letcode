class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        map<int,long long>mp;
        long long result=LLONG_MIN;
        for(int i=0;i<nums.size();i++)
        {
            long long sum=nums[i];
            auto it=mp.upper_bound(nums[i]-i);
            if(it!=mp.begin())
            {
                it--;
                sum=max(sum,sum+it->second);
            }
           it=mp.upper_bound(nums[i]-i);
           while(it!=mp.end() && it->second<sum)
           {
              it=mp.erase(it);
           }
           mp[nums[i]-i]=sum;
           result=max(sum,result);
        }
        return result;
    }
};