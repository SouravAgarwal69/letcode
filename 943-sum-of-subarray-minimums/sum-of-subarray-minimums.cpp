class Solution {
public:
    void findLeft(vector<int>&arr,vector<int>&left)
    {
         stack<int>st;
         for(int i=0;i<arr.size();i++)
         {
             while(!st.empty() && arr[st.top()]>=arr[i])
             {
                st.pop();
             }
             if(st.empty())
             {
                left[i]=-1;
             }
             else
             {
                left[i]=st.top();
             }
             st.push(i);  
         }
    }
    void findRight(vector<int>&arr,vector<int>&right)
    {
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--)
        {
           while(!st.empty() && arr[st.top()]>arr[i])
           {
              st.pop();
           }
           if(st.empty())
           {
              right[i]=arr.size();
           }
           else 
           {
              right[i]=st.top();
           }
           st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        vector<int>left(arr.size());
        vector<int>right(arr.size());
        findLeft(arr,left);
        findRight(arr,right);
        long long sum=0;
        for(int i=0;i<arr.size();i++)
        {
           int leftSum=i-left[i];
           int rightSum=right[i]-i;
            sum=(sum+1LL*leftSum*rightSum*arr[i])%mod;
        }
        return sum%mod;
    }
};