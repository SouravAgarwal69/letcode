class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>result;
        for(int i=0;i<asteroids.size();i++)
        {
            bool collision=false;
            while(!result.empty() && result.back()>0 && asteroids[i]<0)
            {
                if(abs(asteroids[i])==result.back())
                {
                    collision=true;
                    result.pop_back();
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