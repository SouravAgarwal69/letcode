class Solution {
public:
    string countAndSay(int n) {
        string temp="1";
        for(int i=1;i<n;i++)
        {
            int j=0;
            string ptr;
            while(j<temp.size())
            {

                int cnt=1,k=j+1;
                while(k<temp.size() && temp[j]==temp[k])
                {
                    cnt++;
                    k++;
                }
                ptr+=to_string(cnt);
                ptr+=temp[j];
                 j=k;
            }
            temp=ptr;
        }
        return temp;
    }
};