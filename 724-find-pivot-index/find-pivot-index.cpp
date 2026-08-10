class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum=0,rightSum=0,n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0;i<n;i++)
        {
            left[i]=leftSum;
            leftSum+=nums[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            right[i]=rightSum;
            rightSum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(left[i]==right[i])
            {
                return i;
            }
        }
        return -1;
    }
};