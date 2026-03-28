class Solution {
public:
    bool solve(int i,int j,string &s)
    {
        if(i>=j)
        {
            return true;
        }
        if(s[i]==s[j])
        {
            return solve(i+1,j-1,s);
        }
        return false;
    }
    string longestPalindrome(string s) {
       int startIndex=0,len=0;
       for(int i=0;i<s.size();i++)
       {
          for(int j=i;j<s.size();j++)
          {
              if(solve(i,j,s) && len<j-i+1)
              {
                startIndex=i;
                len=j-i+1;
              }
          }
       }
       return s.substr(startIndex,len);
    }
};