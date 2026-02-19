class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxIce=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++)
        {
            if(coins>=costs[i])
            {
                maxIce++;
                coins-=costs[i];
            }
            else{
               return maxIce;
            }
        }
        return maxIce;
    }
};