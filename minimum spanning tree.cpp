class Solution {
public:
    int traverse(int cur, vector<bool> &visited, const vector<vector<int>> &edges) {
        if (visited[cur])
            return 0;
        
        visited[cur] = true;
        int ret = 0;
        int i;
        for (i=0; i<edges[cur].size(); i++) {
            ret += traverse(edges[cur][i], visited, edges);
        }
        return ret + 1;
    }
    int traverse2(int cur, vector<bool> &visited, const vector<vector<int>> &edges, 
                  const vector<vector<int>> &edges2) {
        if (visited[cur])
            return 0;
        
        visited[cur] = true;
        int ret = 0;
        int i;
        for (i=0; i<edges[cur].size(); i++) {
            ret += traverse2(edges[cur][i], visited, edges,edges2);
        }
         for (i=0; i<edges2[cur].size(); i++) {
            ret += traverse2(edges2[cur][i], visited, edges,edges2);
        }
        return ret + 1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> conn(n+1);
        vector<vector<int>> alice(n+1);
        vector<vector<int>> bob(n+1);
        int common_tot = 0;
        int alice_tot = 0;
        int bob_tot = 0;
        int i;
        for (i=0; i<edges.size(); i++) {
            if (edges[i][0] == 3) {
                conn[edges[i][1]].push_back(edges[i][2]);
                conn[edges[i][2]].push_back(edges[i][1]);
                common_tot++;
            } else if (edges[i][0] == 1) {
                alice[edges[i][1]].push_back(edges[i][2]);
                alice[edges[i][2]].push_back(edges[i][1]);
                alice_tot++;
            } else {
                bob[edges[i][1]].push_back(edges[i][2]);
                bob[edges[i][2]].push_back(edges[i][1]);
                bob_tot++;
            }
        }
        vector<bool> tmp1(n+1);
        if (traverse2(1,tmp1,conn,alice) != n) {        
            return -1;
        }
        vector<bool> tmp2(n+1);
        if (traverse2(1,tmp2,conn,bob) != n)
            return -1;
        
        vector<bool> visited(n+1);
        int used_common = 0;
        int num_pile = 0;
        
        for (i=1; i<visited.size(); i++) {
            if (!visited[i]) {
                num_pile++;
                int cnt = traverse(i,visited,conn);
                used_common += cnt - 1;
            }
        }
    
        return common_tot - used_common + alice_tot - num_pile + bob_tot - num_pile + 2;      
    }
};