class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
       long long totalSum=0;
       vector<int>leftIndex(arr.size());
       vector<int>rightIndex(arr.size());
       stack<int>leftSt;
       stack<int>rightSt;
       for(int i=0;i<arr.size();i++)
       {
          while(!leftSt.empty() && arr[leftSt.top()]>=arr[i])
          {
               leftSt.pop();          
          }
          if(leftSt.empty())
          {
            leftIndex[i]=-1;
          }
          else
          {
            leftIndex[i]=leftSt.top();
          }
          leftSt.push(i);
       }
       for(int i=arr.size()-1;i>=0;i--)
       {
           while(!rightSt.empty() && arr[rightSt.top()]>arr[i])
           {
               rightSt.pop();
           }
           if(rightSt.empty())
           {
               rightIndex[i]=arr.size();
           }
           else
           {
                rightIndex[i]=rightSt.top();
           }
           rightSt.push(i);
       }
       for(int i=0;i<arr.size();i++)
       {
         totalSum+=1LL*arr[i]*((i-leftIndex[i])*(rightIndex[i]-i));
       }
       return totalSum %mod;
    }
};