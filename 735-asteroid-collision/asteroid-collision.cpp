class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
       for(int i=0;i<asteroids.size();i++)
       {
          bool collision=false;
          while(!ans.empty() && ans.back()>0 && asteroids[i]<0)
          {
              if(ans.back()==abs(asteroids[i]))
              {
                 ans.pop_back();
                 collision=true;
                 break;
              }
              else if(ans.back()<abs(asteroids[i]))
              {
                  ans.pop_back();
              }
              else
              {
                 collision=true;
                 break;
              }
          }
          if(!collision)
          {
             ans.push_back(asteroids[i]);
          }
       } 
       return ans;
    }
};