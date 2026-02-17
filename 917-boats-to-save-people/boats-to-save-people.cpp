class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat=0,i=0,j=people.size()-1;
        sort(people.begin(),people.end());
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
            }
            else
            {
                j--;
            }
            boat++;
        }
        return boat;
    }
};