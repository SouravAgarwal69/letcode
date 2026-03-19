class Solution {
public:
     bool isPossible(int product,int Avl_Store,vector<int>&quantities)
    {
        int req_store=0;
        for(int i=0;i<quantities.size();i++)
        {
            req_store+=quantities[i]/product;
            if(quantities[i]%product!=0)
            {
                req_store++;
            }
        }
       return req_store<=Avl_Store;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s=1,e=*max_element(quantities.begin(),quantities.end());
        int ans=e;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(mid,n,quantities))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};