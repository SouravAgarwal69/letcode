class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i=1,j=0;
        vector<string>temp;
        while(i<=n && j<target.size())
        {
            temp.push_back("Push");
            if(i==target[j])
            {
                j++;
            }
            else
            {
                temp.push_back("Pop");
            }
            i++;
        }
        return temp;
    }
};