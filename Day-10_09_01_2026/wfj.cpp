class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int, pair<int,int>>> q;
        vector<int>prices(n,1e9);
 q.push({0,{src,0}});
 prices[src]=0;
 while(!q.empty()){
    int node=q.front().second.first;
    int price=q.front().second.second;
    int stop=q.front().first;
    q.pop();
    if (stop>k) continue;
    for(auto it:adj[node]){
        int nnode=it.first;
        int nprice=it.second;
        if(price+nprice<prices[nnode]){
           prices[nnode]=price+nprice ;
        q.push({stop+1,{nnode,price+nprice}});}
    }
 }

    if(prices[dst]==1e9) return -1;
    return prices[dst];}
};