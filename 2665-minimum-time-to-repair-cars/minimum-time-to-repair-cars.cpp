class Solution {
public:
    bool isPossible(long long time,vector<int>&ranks,int cars)
    {
        long long Totalcars=0;
        for(int i=0;i<ranks.size();i++)
        {
            Totalcars+=1LL*sqrt(1LL*time/ranks[i]);
            if(Totalcars>=cars)
            {
                return true;
            }
        }
        return Totalcars>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long s=1;
        long long e=1LL**max_element(ranks.begin(),ranks.end())*cars*cars;
        long long ans=e;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            if(isPossible(mid,ranks,cars))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};