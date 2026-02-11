class Solution {
public:
    string minRemoveToMakeValid(string s) {
       string ans;
       vector<int>index;
       for(int i=0;i<s.size();i++)
       {
          if( !index.empty() && s[i]==')' && s[index.back()]=='(')
          {
              index.pop_back();
          }
          else if(s[i]=='(' || s[i]==')')
          {
            index.push_back(i);
          }
       } 
       int k=0;
      for(int i=0;i<s.size();i++)
      { 
         if( k<index.size() && i==index[k])
         {
            k++;
            continue;
         }
         ans.push_back(s[i]);
         
      }
       return ans;
    }
};