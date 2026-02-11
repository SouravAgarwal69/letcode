class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
         int j=0,i=1;
         while(i<=n && j<target.size())
         {
            ans.push_back("Push");
            if(target[j]!=i)
            {
                ans.push_back("Pop");
            }
            else
            {
                j++;
            }
            i++;
         }
         return ans;
    }
};