class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n=flowerbed.size();
        if(flowerbed.size()==1 && flowerbed[0]==0)
        {
            return 1;
        }
        int possible=0;
        if( flowerbed[0]==0 &&  flowerbed[1]==0)
        {
            possible++;
            flowerbed[0]=1;
        }
        if(flowerbed[n-1]==0 && flowerbed[n-2]==0)
        {
            possible++;
            flowerbed[n-1]=1;
        }
        for(int i=1;i<n-1;i++)
        {
            if( flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0)
            { 
                possible++;
                flowerbed[i]=1;
            }
        }
        return possible>=k;
    }
};