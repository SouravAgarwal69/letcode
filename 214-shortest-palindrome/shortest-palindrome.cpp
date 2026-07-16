class Solution {
public:
    void findLps(vector<int>&lps,string &temp)
    {
        int i=1,len=0;
        lps[0]=0;
        while(i<temp.size())
        {
            if(temp[i]==temp[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
      string rev=s;
      reverse(rev.begin(),rev.end());
      string temp=s+"-"+rev;
      vector<int>lps(temp.size());
      findLps(lps,temp);
      int longestLps=lps[temp.size()-1];
      string culprit=rev.substr(0,s.size()-longestLps);
      return culprit+s;
    }
};