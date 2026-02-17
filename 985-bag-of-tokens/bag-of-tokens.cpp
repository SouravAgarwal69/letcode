class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0,i=0,j=tokens.size()-1,maxScore=0;
        sort(tokens.begin(),tokens.end());
        while(i<=j)
        {
            if(tokens[i]<=power)
            {
                score++;
                power-=tokens[i];
                i++;
                maxScore=max(maxScore,score);
            }
            else if(score>0)
            {
                power+=tokens[j];
                j--;
                score--;
            }
            else
            {
                return maxScore;
            }
        }
        return maxScore;
    }
};