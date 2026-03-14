class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int>freq(nums.size()+1);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=nums.size())
            {
                freq[nums.size()]++;
            }
            else
            {
                freq[nums[i]]++;
            }
        }
        vector<int>freqSum(nums.size()+1);
        freqSum[nums.size()]=freq[nums.size()];
        for(int i=freq.size()-2;i>=0;i--)
        {
            freqSum[i]=freqSum[i+1]+freq[i];
        }
        for(int i=0;i<freqSum.size();i++)
        {
            if(freqSum[i]==i)
            {
                return i;
            }
        }
        return -1;
    }
};