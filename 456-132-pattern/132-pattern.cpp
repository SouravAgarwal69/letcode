class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>num3;
        int num2=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<num2)
            {
                return true;
            }
            while(!num3.empty() && num3.top()<nums[i])
            {
                num2=num3.top();
                num3.pop();
            }
            num3.push(nums[i]);
        }
        return false;
    }
};