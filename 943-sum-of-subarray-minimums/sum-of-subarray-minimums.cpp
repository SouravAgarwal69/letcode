class Solution {
public:
    void findNSE(vector<int>&arr,vector<int>&NSE)
    {
          stack<int>st;
          for(int i=arr.size()-1;i>=0;i--)
          {
             while(!st.empty() && arr[st.top()]>=arr[i])
             {
                st.pop();
             } 
             if(st.empty())
             {
                NSE[i]=arr.size();
             }
             else
             {
                NSE[i]=st.top();
             }
             st.push(i);
          }
    }
    void findPSE(vector<int>&arr,vector<int>&PSE)
    {
         stack<int>st;
         for(int i=0;i<arr.size();i++)
         {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                PSE[i]=-1;
            }
            else
            {
                PSE[i]=st.top();
            }
            st.push(i);
         }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        vector<int>NSE(arr.size());
        vector<int>PSE(arr.size());
        findNSE(arr,NSE);
        findPSE(arr,PSE);
        int total=0;
        for(int i=0;i<arr.size();i++)
        {
           long long left=i-PSE[i];
           long long right=NSE[i]-i;
           total=(total+(left*right % mod)*arr[i] % mod) % mod;
        }
        return total;
    }
};