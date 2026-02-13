class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalGain=0;
        int maxScore=max(x,y);
        int minScore=min(x,y);
        string maxString=x>y?"ab":"ba";
        string minString=x>y?"ba":"ab";
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(!result.empty() && result.back()==maxString[0] && s[i]==maxString[1])
            {
                totalGain+=maxScore;
                result.pop_back();
            }
            else
            {
                result.push_back(s[i]);
            }
        }
        int size=result.size();
        string temp;
        for(int i=0;i<size;i++)
        {
            if(!temp.empty() && temp.back()==minString[0] && result[i]==minString[1])
            {
                totalGain+=minScore;
                temp.pop_back();
            }
            else{
                temp.push_back(result[i]);
            }
        }
        return totalGain;

    }
};