class Solution {
public:
    int  fun(int a)
    {
          int cnt=0;
          for(int k=0;k<32;k++)
          {
             int temp=1<<k;
             if((temp & a)!=0)
             {
                 cnt++;
             }
          }
          return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b){
           if(fun(a)==fun(b))
           {
              return a<b;
           }
           return fun(a)<fun(b);
        }
        );
        return arr;
    }
};