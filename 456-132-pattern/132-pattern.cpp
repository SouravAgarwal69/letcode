class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int possibleTwo=INT_MIN;
        stack<int>possibleThree;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(possibleTwo>nums[i])
            {
                return true;
            }
            while(!possibleThree.empty() && possibleThree.top()<nums[i])
            {
                possibleTwo=possibleThree.top();
                possibleThree.pop();
            }
             possibleThree.push(nums[i]);
        }
        return false;
    }
};