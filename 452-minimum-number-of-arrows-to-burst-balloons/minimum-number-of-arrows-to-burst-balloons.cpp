class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int Arrow=1;
        sort(points.begin(),points.end());
        int ps=points[0][0],pe=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            int cs=points[i][0],ce=points[i][1];
            if(pe>=cs)
            {
                ps=max(ps,cs);
                pe=min(pe,ce);
            }
            else
            {
                ps=cs;
                pe=ce;
                Arrow++;
            }
        }
        return Arrow++;
    }
};