class Solution {
public:
    int  fun(int a)
    {
          int cnt=0;
          while(a!=0)
          {
             a= a & (a-1);
             cnt++;
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