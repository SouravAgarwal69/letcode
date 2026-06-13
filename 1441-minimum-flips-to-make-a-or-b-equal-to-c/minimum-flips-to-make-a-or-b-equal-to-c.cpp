class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        while(a != 0 || b != 0 || c != 0)
        {
            int first=a & 1;
            int second=b & 1;
            int target=c & 1;
            if(target!=0)
            {
                if(first==0 && second==0)
                {
                    flips++;
                }
            }
            else
            {
               if(first!=0)
               {
                 flips++;
               }
               if(second!=0)
               {
                  flips++;
               }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return flips;
    }
};