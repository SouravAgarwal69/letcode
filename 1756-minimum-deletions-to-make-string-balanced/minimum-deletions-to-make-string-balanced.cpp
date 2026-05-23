class Solution {
public:
    int minimumDeletions(string s) {
        vector<int>rightA(s.size());
        vector<int>leftB(s.size());
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            leftB[i]=cnt;
            if(s[i]=='b')
            {
                cnt++;
            }
        }
        cnt=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            rightA[i]=cnt;
            if(s[i]=='a')
            {
                cnt++;
            }
        }
        int result=s.size();
        for(int i=0;i<s.size();i++)
        {
            result=min(result,leftB[i]+rightA[i]);
        }
        return result;
    }
};