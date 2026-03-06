class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long odd=0,even=0;
        for(int i=0;i<nums.size();i++)
        {
            odd=max(odd,even-nums[i]);
            even=max(even,odd+nums[i]);
        }
        return max(odd,even);
    }
};