class Solution {
public:
   bool isPallindrome(string &s,int i,int j)
   {
       if(i>=j)
       {
        return true;
       }
       if(s[i]==s[j])
       {
          return isPallindrome(s,i+1,j-1);
       }
       return false;
   }
    string longestPalindrome(string s) {
        int start=0,len=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(isPallindrome(s,i,j)&& len<j-i+1)
                {
                    start=i;
                    len=j-i+1;
                }
            }
        }
        return s.substr(start,len);
    }
};