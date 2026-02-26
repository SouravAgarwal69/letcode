class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int coins=0;
        sort(piles.begin(),piles.end());
        int M=piles.size()-2,A=piles.size()-1,B=0;
        while(M>B)
        {
           coins+=piles[M];
           A=M-1;
           M=A-1;
           B++;
        }
        return coins;
    }
};