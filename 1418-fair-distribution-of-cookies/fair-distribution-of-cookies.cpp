class Solution {
public:
    void find(vector<int>&cookies,vector<int>&child,int k,int &result,int index)
    {
           if(index==cookies.size())
           {
              int val=*max_element(child.begin(),child.end());
              result=min(result,val);
              return;
           }
           for(int i=0;i<k;i++)
           {
                child[i]+=cookies[index];
                find(cookies,child,k,result,index+1);
                child[i]-=cookies[index];
           }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k);
        int result=INT_MAX;
        find(cookies,child,k,result,0);
        return result;
    }
};