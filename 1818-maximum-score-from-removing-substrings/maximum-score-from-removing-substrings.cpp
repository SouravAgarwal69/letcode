class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string result1,result2;
        string temp1=x>y?"ab":"ba";
        int val1=x>y?x:y;
        int val2=x>y?y:x;
        string temp2=x>y?"ba":"ab";
        int points=0;
        for(int i=0;i<s.size();i++)
        {
            if(!result1.empty() && result1.back()==temp1[0] && s[i]==temp1[1])
            {
                result1.pop_back();
                points+=val1;
            }
            else
            {
                result1.push_back(s[i]);
            }
        }
        for(int i=0;i<result1.size();i++)
        {
            if(!result2.empty() && result2.back()==temp2[0] && result1[i]==temp2[1])
            {
                result2.pop_back();
                points+=val2;
            }
            else
            {
                result2.push_back(result1[i]);
            }
        }
        return points;
    };

};