class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    //     set<pair<int,int>>st;
    //     vector<int>dist(v,1e9);
    //     st.insert({0,s});
    //     dist[s]=0;
    //     while(!st.empty()){
    //         auto it=*(st.begin());
    //         int node=it.second;
    //         int edgeweight=it.first;
    //         st.erase(it);
    //         for(auto it:adj[node]){
    //             int adjnode=it[0];
    //             int adjnodew=it[1];
    //             if(dist[adjnode]>edgeweight+adjnodew){
    //                 if(dist[adjnode]!=1e9){
    //                     st.erase({dist[adjnode],adjnode});}
    //                     dist[adjnode]=adjnodew+edgeweight;
    //                     st.insert({dist[adjnode],adjnode});
    //                 }
    //             }
    //         }
    //  return dist;   
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(V,1e9);
    pq.push({0,S});
    dist[S]=0;
    while(!pq.empty()){
        auto it=pq.top();
        int node=it.second;
        int edgew=it.first;
        pq.pop();
        for(auto it:adj[node]){
            int adjnode=it[0];
            int adjnodew=it[1];
            if(dist[adjnode]>edgew+adjnodew){
               dist[adjnode]=edgew+adjnodew ;
               pq.push({dist[adjnode],adjnode});
            }
        }

    }
    
    
    
    
   return dist; 
    
      }

  
};