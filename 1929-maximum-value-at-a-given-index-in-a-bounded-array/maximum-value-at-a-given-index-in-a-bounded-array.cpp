class Solution {
public:
    long long calculate(long long mid,long long length)
    {
        if(length<=mid-1)
        {
            return length*(mid-1+mid-length)/2;
        }
        else
        {
            return length-(mid-1)+((mid-1)*(mid-1+1)/2);
        }
    }
    bool isPossible(long long mid,int n,int index,int maxSum)
    {
        long long left=calculate(mid,index);
        long long right=calculate(mid,n-1-index);
        return left+mid+right<=maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        long long s=1,e=maxSum,result=1;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            if(isPossible(mid,n,index,maxSum))
            {
                result=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return result;
    }
};