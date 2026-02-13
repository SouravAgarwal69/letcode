class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalGain=0;
        string maxString=x>y?"ab":"ba";
        string minString=x>y?"ba":"ab";
        int maxScore=max(x,y);
        int minScore=min(x,y);
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(!result.empty() && result.back()==maxString[0] && s[i]==maxString[1])
            {
                result.pop_back();
                totalGain+=maxScore;
            }
            else
            {
               result.push_back(s[i]);   
            }
        }
        string temp;
        for(int i=0;i<result.size();i++)
        {
            if(!temp.empty() && temp.back()==minString[0] && result[i]==minString[1])
            {
                temp.pop_back();
                totalGain+=minScore;
            }
            else
            {
                temp.push_back(result[i]);
            }
        }
        return totalGain;
    }
};