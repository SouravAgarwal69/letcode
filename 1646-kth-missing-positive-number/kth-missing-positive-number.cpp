class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0,e=arr.size()-1,ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int missing=arr[mid]-(mid+1);
            if(missing>=k)
            {
                  e=mid-1;
            }
            else
            {
                ans=mid;
                s=mid+1;
            }
        }
        return ans+k+1;
    }
};