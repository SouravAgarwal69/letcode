class Solution {
public:
    int countMonobit(int n) {
        int cnt=1;
        for(int i=1;i<=n;i++)
            {
         string s=bitset<32>(i).to_string();
        s=s.substr(s.find('1'));
                char ch=s[0];
                bool flag=true;
        for(int i=1;i<s.size();i++)
            {
                if(s[i]!=ch)
                {
                    flag=false;
                    break;
                }
            }
                if(flag)
                {
                    cnt++;
                }
            }
        return cnt;
    }
};