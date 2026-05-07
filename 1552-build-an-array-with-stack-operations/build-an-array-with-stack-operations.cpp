class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>result;
        int i=0,k=1;
        while(i<target.size() && k<=n)
        {
            result.push_back("Push");
            if(target[i]!=k)
            {
                result.push_back("Pop");
            }
            else
            {
                i++;
            }
            k++;
        }
        return result;
    }
};