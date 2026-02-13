class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>result;
        for(int i=0;i<asteroids.size();i++)
        {
            bool collision=false;
            while(!result.empty() && asteroids[i]<0 && result.back()>0)
            {
               if(abs(asteroids[i])==result.back())
               {
                  result.pop_back();
                  collision=true;
                  break;
               }
               else if(abs(asteroids[i])>result.back())
               {
                  result.pop_back();
               }
               else
               {
                  collision=true;
                  break;
               }
            }
            if(!collision)
            {
                result.push_back(asteroids[i]);
            }
        }
        return result;
    }
};