class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total=total^nums[i];
        }
        return total;
    }
};