class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int maxBags=0;
        vector<int>req(capacity.size());
        for(int i=0;i<capacity.size();i++)
        {
            req[i]=capacity[i]-rocks[i];
        }
        sort(req.begin(),req.end());
        for(int i=0;i<req.size();i++)
        {
            if(req[i]<=additionalRocks)
            {
                maxBags++;
                additionalRocks-=req[i];
            }
            else
            {
                break;
            }
        }
        return maxBags;
    }
};