class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int days=0;
         vector<int>index(growTime.size());
         iota(index.begin(),index.end(),0);
         sort(index.begin(),index.end(),[&](int i,int j)
         {
            return growTime[i]>growTime[j];
         }
         );
         int maximum=0,plant=0;
         for(int i=0.;i<index.size();i++)
         {
             plant+=plantTime[index[i]];
            maximum=max(maximum,plant+growTime[index[i]]);
           
         }
         return maximum;
    }
};