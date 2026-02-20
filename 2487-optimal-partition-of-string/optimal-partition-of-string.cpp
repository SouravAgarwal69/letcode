class Solution {
public:
    int partitionString(string s) {
        vector<bool>present(26,0);
        int partition=0;
        for(int i=0;i<s.size();i++)
        {
             if(present[s[i]-'a'])
             {
              fill(present.begin(), present.end(), false);
                partition++;
             }
             present[s[i]-'a']=true;
        }
        return partition+1;
    }
};