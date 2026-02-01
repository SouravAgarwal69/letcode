class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long initialCost=0,originalWindow=0,modifiedWindow=0,maxProfit=0;
        for(int i=0;i<prices.size();i++)
        {
            initialCost+=prices[i]*strategy[i];
        }
        int i=0,j=0;
        while(j<prices.size())
        {
            originalWindow+=prices[j]*strategy[j];
            if(j-i>=k/2)
            {
                modifiedWindow+=prices[j];
            }
            if(j-i+1==k)
            {
                maxProfit=max(maxProfit,modifiedWindow-originalWindow);
                originalWindow-=prices[i]*strategy[i];
                modifiedWindow-=prices[i+(k/2)];
                i++;
            }
            j++;
        }
        return initialCost+maxProfit;
    }
};