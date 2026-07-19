class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        string temp=countAndSay(n-1);
        int i=0;
        string ptr;
        while(i<temp.size())
        {
            int j=i+1,cnt=1;
            while(j<temp.size() && temp[i]==temp[j])
            {
               cnt++;
               j++;
            }
            ptr+=to_string(cnt);
            ptr+=temp[i];
              i=j;
        }
        return ptr;
    }
};