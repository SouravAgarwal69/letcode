class Solution {
public:
    int MOD=1e9+7;
    void findNSE(vector<int>&NSL,vector<int>&arr)
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
                NSL[i]=-1;
            }
            else
            {
                NSL[i]=st.top();
            }
            st.push(i);
         }
    }
    void findNSR(vector<int>&NSR,vector<int>&arr)
    {
        stack<int>st;
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                NSR[i]=n;
            }
            else
            {
                NSR[i]=st.top();
            }
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int total=0;
        vector<int>NSL(arr.size());
        vector<int>NSR(arr.size());
        findNSE(NSL,arr);
        findNSR(NSR,arr);
        for(int i=0;i<arr.size();i++)
        {
            long long left=i-NSL[i];
            long long right=NSR[i]-i;
            total=(total+(left*right%MOD)*arr[i]%MOD)%MOD;
        }
        return total;
    }
};