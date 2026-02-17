class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
           int first=nums[i];
           while(!result.empty())
           {
                 int second=result.back();
                int GCD=__gcd(first,second);
                if(GCD==1)
                {
                   break;
                }
                int LCM=(1LL*first*second)/GCD;
                result.pop_back();
                first=LCM;
           }
        result.push_back(first);        
        
        }
        return result;
    }
};