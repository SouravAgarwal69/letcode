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
       int start=0;
      for(int i=0;i<index.size();i++)
      {
       ans+=s.substr(start,index[i]-start);
        start=index[i]+1;
      }
      ans+=s.substr(start);
       return ans;
    }
};