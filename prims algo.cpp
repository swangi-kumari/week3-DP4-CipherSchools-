class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        if(p.size()==1)return 0;
        int n=p.size(),ans=0;
        priority_queue<pair<int,int>>q;
        vector<bool>vis(n,0);
        for(int i=0;i<1;i++)  
        {
            for(int j=i+1;j<n;j++)
            {
                int w=abs(p[i][0]-p[j][0])+abs(p[j][1]-p[i][1]);
                q.push({-w,j}); 
            }
        }
        vis[0]=1;
        int k=n-1;  
        while(k)
        {
            auto it=q.top();
            q.pop();
            if(vis[it.second])continue;  
            ans+=it.first;
            vis[it.second]=1;
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    int w=abs(p[it.second][0]-p[i][0])+abs(p[it.second][1]-p[i][1]);
                    q.push({-w,i});
                }
            }
            k--;
        }
        return -ans;
    }
};