class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0,totalCost=0;
        for(int i=0;i<gas.size();i++)
        {
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalGas<totalCost)
        {
            return -1;
        }
        int available=0,resultIndex=0;
        for(int i=0;i<gas.size();i++)
        {
            available+=gas[i];
            if(available<cost[i])
            {
                resultIndex=i+1;
                available=0;
            }
            else
            {
            available-=cost[i];
            }
        }
        return resultIndex;
    }
};