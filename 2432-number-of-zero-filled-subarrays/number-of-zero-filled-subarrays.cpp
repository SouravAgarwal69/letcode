class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       long long total=0,i=0,cnt=0;
        while(i<nums.size())
        {
            if(nums[i]==0)
            {
                cnt++;
            }
            else
            {
                cnt=0;
            }
            total+=cnt;
            i++;
        }
        return total;
    }
};