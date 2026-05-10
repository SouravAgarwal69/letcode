class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>result;
        vector<int>temp;
        int n=positions.size();
        vector<int>index(n);
        iota(index.begin(),index.end(),0);
        sort(index.begin(),index.end(),[&](int i,int j)
        {
            return positions[i]<positions[j];
        });
        for(int i=0;i<n;i++)
        {
            bool collision=false;
            while(!result.empty() && directions[result.back()]=='R' && directions[index[i]]=='L')
            {
                if(healths[result.back()]==healths[index[i]])
                {
                    healths[result.back()]=0;
                    healths[index[i]]=0;
                    result.pop_back();
                    collision=true;
                    break;
                }
                else if(healths[result.back()]>healths[index[i]])
                {
                    healths[index[i]]=0;
                    healths[result.back()]--;
                    collision=true;
                    break;
                }
                else
                {
                    healths[index[i]]--;
                    healths[result.back()]=0;
                    result.pop_back();
                }
            }
            if(!collision)
            {
                result.push_back(index[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
             if(healths[i]!=0)
             {
                temp.push_back(healths[i]);
             }
        }
        return temp;
    }
};