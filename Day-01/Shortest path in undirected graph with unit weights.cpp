class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
      vector<int>ans(N,INT_MAX);
      vector<vector<int>>adj(N);
      for(auto &it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }
      queue<int>q;
      q.push(0);
      ans[0]=0;
      while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
          if(ans[it]>ans[node]+1){
            ans[it]=ans[node]+1;
            q.push(it);
          }
        }
      }
    for(int i = 0; i < N; i++) {
            if (ans[i] == INT_MAX) 
                ans[i] = -1;
        }
   return ans; }
};
