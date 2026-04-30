class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        int n=arr.size();
        queue<int>q;
        q.push(0);
        vector<bool>visited(arr.size());
        int steps=0;
        visited[0]=true;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int index=q.front();
                q.pop();
                if(index==n-1)
                {
                    return steps;
                }
                if(index-1>=0 && !visited[index-1])
                {
                    q.push(index-1);
                    visited[index-1]=true;
                }
                if(index+1<n && !visited[index+1])
                {
                    q.push(index+1);
                    visited[index+1]=true;
                }
                if(mp.find(arr[index])!=mp.end())
                {
                    vector<int>temp=mp[arr[index]];
                    for(int i=0;i<temp.size();i++)
                    {
                        if(!visited[temp[i]])
                        {
                            q.push(temp[i]);
                            visited[temp[i]]=true;
                        }
                    }
                    mp.erase(arr[index]);
                }
            }
            steps++;
        }
        return steps;
    }
};