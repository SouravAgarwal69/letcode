class Solution {
public:
   int mod=1e9+7;
    void findNSL(vector<int>&NSL,vector<int>&arr)
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
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                NSR[i]=arr.size();
            }
            else
            {
                NSR[i]=st.top();
            }
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long total=0;
        vector<int>NSL(arr.size());
        vector<int>NSR(arr.size());
        findNSL(NSL,arr);
        findNSR(NSR,arr);
        for(int i=0;i<arr.size();i++)
        {
            int d1=i-NSL[i];
            int d2=NSR[i]-i;
            total=total+(1LL*d1*d2*arr[i])%mod;
        }
        return total%mod;
    }
};