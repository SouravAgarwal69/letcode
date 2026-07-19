class Solution {
public:
    string orderlyQueue(string s, int k) {
        string temp=s;
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        for(int i=1;i<s.size();i++)
        {
            temp=min(temp,s.substr(i)+s.substr(0,i));
        }
        return temp;
    }
};