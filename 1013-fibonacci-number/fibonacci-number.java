class Solution {
    public int fib(int n) {
        if(n==0 || n==1)
        {
            return n;
        }
        int f0=0,f1=1,result=0;
        for(int i=2;i<=n;i++)
        {
            result=f0+f1;
            f0=f1;
            f1=result;
        }
        return result;
    }
}