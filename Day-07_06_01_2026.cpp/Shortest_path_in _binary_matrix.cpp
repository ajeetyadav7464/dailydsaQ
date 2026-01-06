class Solution {

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int nrow[]={0,-1,-1,-1,0,1,1,1};
        int ncol[]={-1,-1,0,1,1,1,0,-1};
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int dist=1;
        while(!q.empty()){
            int size=q.size();
            while(size>0){
                auto it=q.front();
                int r=it.first;
                int c=it.second;
                if(r==n-1 && c==n-1){
                    return dist;
                }
                q.pop();
                for(int i=0;i<8;i++){
                    int newrow=r+nrow[i];
                    int newcol=c+ncol[i];
                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<n 
                    && grid[newrow][newcol]==0){
                        q.push({newrow,newcol});
                        grid[newrow][newcol]=1;
                    }
                }
           size--;
            }
       dist++; }
   return -1; }
};