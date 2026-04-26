class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long minimumAvg=INT_MAX,minIndex=-1;
        long long totalSum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            totalSum+=nums[i];
        }
        long long leftSum=0;
        for(int i=0;i<nums.size();i++)
        {
            leftSum+=nums[i];
            long long rightSum=totalSum-leftSum;
            long long leftAvg=leftSum/(i+1);
            long long rightAvg=0;
            if(i!=nums.size()-1)
            {
             rightAvg=rightSum/(n-i-1);
            }
            if(minimumAvg>abs(leftAvg-rightAvg))
            {
                minimumAvg=abs(leftAvg-rightAvg);
                minIndex=i;
            }
        }
        return minIndex;
    }
};