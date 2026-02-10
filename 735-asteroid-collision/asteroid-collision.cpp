class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<asteroids.size();i++)
        {
            bool collision=false;
            while(!st.empty() && st.top()>0 && asteroids[i]<0)
            {
                if(st.top()==abs(asteroids[i]))
                {
                    st.pop();
                    collision=true;
                    break;
                }
                else if(st.top()>abs(asteroids[i]))
                {
                    collision=true;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(!collision)
            {
                st.push(asteroids[i]);
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};