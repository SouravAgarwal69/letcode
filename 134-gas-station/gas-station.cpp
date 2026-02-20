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
        int resultIndex=0,avl=0;
        for(int i=0;i<gas.size();i++)
        {
            avl+=gas[i];
            if(avl<cost[i])
            {
                resultIndex=i+1;
                avl=0;
            }
            else
            {
                avl-=cost[i];
            }
        }
        return resultIndex;
    }
};