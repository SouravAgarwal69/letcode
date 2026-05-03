class Solution {
public:
    int find(int a)
    {
         int cnt=0;
         while(a>0)
         {
             a= a &(a-1);
            cnt++;
         }
         return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b)
        {
            int cntA=find(a);
            int cntB=find(b);
            if(cntA==cntB)
            {
                return a<b;
            }
            else{
                return cntA<cntB;
            }
        });
       return arr;
    }
};