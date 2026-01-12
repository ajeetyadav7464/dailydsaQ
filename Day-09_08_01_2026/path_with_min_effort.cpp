class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
    priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;

        int nrow[]={0,-1,0,1};
        int ncol[]={-1,0,1,0};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int effort=pq.top().first;;
            pq.pop();
            if(r==n-1 && c==m-1){
                return effort;
            }
            for(int i=0;i<4;i++){
                int Nr=r+nrow[i];
                int Nc=c+ncol[i];
                if(Nr>=0 && Nr<n && Nc>=0 && Nc<m){
                    int Neffort=abs(heights[Nr][Nc]-heights[r][c]);
                    int t=max(effort,Neffort);
                    if(dist[Nr][Nc]>t){
                        dist[Nr][Nc]=t;
                        pq.push({t,{Nr,Nc}});
                    }
                }

            }
       }
   return -1;  }
};
// ajeet