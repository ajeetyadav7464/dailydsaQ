class Solution{
public:
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s) {
        set<pair<int,int>>st;
        vector<int>dist(v,1e9);
        st.insert({0,s});
        dist[s]=0;
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int edgeweight=it.first;
            st.erase(it);
            for(auto it:adj[node]){
                int adjnode=it[0];
                int adjnodew=it[1];
                if(dist[adjnode]>edgeweight+adjnodew){
                    if(dist[adjnode]!=1e9){
                        st.erase({dist[adjnode],adjnode});}
                        dist[adjnode]=adjnodew+edgeweight;
                        st.insert({dist[adjnode],adjnode});
                    }
                }
            }
     return dist;     }

  
};