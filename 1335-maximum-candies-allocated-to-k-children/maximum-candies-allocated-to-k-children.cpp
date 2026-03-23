class Solution {
public:
    bool isPossible(vector<int>&candies,int pile,long long k)
    {
         long long child=0;
         for(int i=0;i<candies.size();i++)
         {
            child+=candies[i]/pile;
         }
         return child>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int s=1,e=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(candies,mid,k))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};