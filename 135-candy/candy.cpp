class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>store(ratings.size(),1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                 store[i]=store[i-1]+1;
            }
        }
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
            store[i]=max(store[i],store[i+1]+1);
            }
        }
        int candies=0;
        for(int i=0;i<ratings.size();i++)
        {
            candies+=store[i];
        }
        return candies;
    }
};