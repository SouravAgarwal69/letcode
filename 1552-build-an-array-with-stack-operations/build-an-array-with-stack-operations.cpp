class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int i=0,j=1;
        while(i<target.size() && j<=n)
        {
            ans.push_back("Push");
            if(target[i]==j)
            {
                i++;
            }
            else
            {
                ans.push_back("Pop");
            }
            j++;
        }
        return ans;
    }
};