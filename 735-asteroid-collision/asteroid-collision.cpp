class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>result;
        for(int i=0;i<asteroids.size();i++)
        {
            bool collision=false;
            while(!result.empty() && asteroids[i]<0 && result.back()>0) 
            {
                if(result.back()==abs(asteroids[i]))
                {
                    result.pop_back();
                    collision=true;
                    break;
                }
                else if(abs(result.back())>abs(asteroids[i]))
                {
                      collision=true;
                      break;
                }
                else
                {
                    result.pop_back();
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