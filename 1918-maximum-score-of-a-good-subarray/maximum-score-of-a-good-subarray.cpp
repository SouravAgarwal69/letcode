class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int score=nums[k],minimum=nums[k];
        int i=k,j=k;
        while(i>0 || j<nums.size())
        {
            int left=i-1>=0?nums[i-1]:0;
            int right=j+1<nums.size()?nums[j+1]:0;
             if(left>right)
             {
                minimum=min(minimum,left);
                i--;
                score=max(score,minimum*(j-i+1));
             }
             else
             {
                minimum=min(minimum,right);
                j++;
                score=max(score,minimum*(j-i+1));
             }
        }
        return score;
    }
};