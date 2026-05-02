class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result;
        for(int i=0;i<=n;i++)
        {
            int val=__builtin_popcount(i);
            result.push_back(val);
        }
        return result;
    }
};