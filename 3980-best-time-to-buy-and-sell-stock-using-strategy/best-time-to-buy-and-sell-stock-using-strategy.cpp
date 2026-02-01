class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long initialProfit=0,windowOriginal=0,windowModified=0,maxProfit=0;
        for(int i=0;i<prices.size();i++)
        {
            initialProfit+=prices[i]*strategy[i];
        }
        int i=0,j=0;
        while(j<prices.size())
        {
            windowOriginal+=prices[j]*strategy[j];
            if(j-i+1>k/2)
            {
                windowModified+=prices[j];
            }
            if(j-i+1==k)
            {
                maxProfit=max(maxProfit,windowModified-windowOriginal);
                windowOriginal-=prices[i]*strategy[i];
                windowModified-=prices[i+k/2];
                i++;
            }
            j++;
        }
       return initialProfit+maxProfit;
    }
};