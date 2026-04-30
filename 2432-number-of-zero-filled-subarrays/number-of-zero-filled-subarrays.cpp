class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       long long total=0,i=0;
        while(i<nums.size())
        {
             long long cnt=0;
            while(i<nums.size() && nums[i]==0)
            {
                 cnt++;
                 total+=cnt;
                 i++;
            }
            i++;
        }
        return total;
    }
};