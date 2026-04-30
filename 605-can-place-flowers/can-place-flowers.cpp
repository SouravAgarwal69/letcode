class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int possible=0,m=flowerbed.size();
        for(int i=0;i<m;i++)
        {
            if(flowerbed[i]==0)
            {
                bool left=( i==0 || flowerbed[i-1]==0);
                bool right=(i==m-1 || flowerbed[i+1]==0);
                if(left && right)
                {
                    possible++;
                    flowerbed[i]=1;
                }
            }
        }
        return possible>=n;
    }
};