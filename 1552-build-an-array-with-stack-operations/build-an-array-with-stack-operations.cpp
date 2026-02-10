class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int j=0;
        stack<int>st;
        for(int i=1;i<=n;i++)
        {
           st.push(i);
           ans.push_back("Push");
           if(target[j]!=i)
           {
              st.pop();
              ans.push_back("Pop");
           }
           else
           {
               j++;
           }
           if(j==target.size())
           {
            return ans;
           }
        }
        return ans;
    }
};