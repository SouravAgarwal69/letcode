class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>result;
        int i=0,j=1;
        while(i<target.size() && j<=n)
        {
              result.push_back("Push");
              if(target[i]!=j)
              {
                 result.push_back("Pop");
              }
              else{
                 i++;
              }
            j++;
        }
        return result;
    }
};