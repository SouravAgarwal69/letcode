class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int total=0;
        string target=x>y?"ab":"ba";
        int val=x>y?x:y;
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(!result.empty() && result.back()==target[0] && s[i]==target[1])
            {
                result.pop_back();
                total+=val;
            }
            else
            {
                result.push_back(s[i]);
            }
        }
        target=x>y?"ba":"ab";
        val=min(x,y);
        string temp;
        for(int i=0;i<result.size();i++)
        {
            if(!temp.empty() && temp.back()==target[0] && result[i]==target[1])
            {
                temp.pop_back();
                total+=val;
            }
            else
            {
                temp.push_back(result[i]);
            }
        }
        return total;
    }
};